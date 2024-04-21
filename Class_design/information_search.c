#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"	
/*************************************************
整型数搜索.input_num是输入的数，但是是字符串的数
据类型，num_group是数据集合，数组，max是数组中的数
字数量。发生错误时返回NULL，正常返回各个搜索结果在
数组中的位置。其返回的地址需要free释放.
*************************************************/
int* number_seach(char* input_num, int* num_group, int max)
{
	int* position;
	position = NULL;
	struct MyStruct
	{
		char num[20];
		int time;
		struct MyStruct* next;
		int position;
	};
	struct MyStruct* p, * head, * tail;
	p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
	if (p == NULL)
	{
		logError(0);
		return NULL;
	}
	head = p;
	tail = p;
	p->next = NULL;
	char num[20] = { '\0' };//将数组中的数转化为字符串
	int wei = 1;//数据位数

	char* temp2 = (char*)malloc(strlen(input_num) * sizeof(char));//临时储存与输入字符串长度相同的数据
	if (temp2 == NULL)//动态分配的内存不是NULL
	{
		logError(0);
		return NULL;
	}
	memset(temp2, 0, ((int)strlen(input_num)+1) * sizeof(char));
	int geshu = 0;//有效数据的个数
	for (int a = 0; a != max; a++)
	{
		int temp = *(num_group + a);
		for (int i = 0;; i++)//计算位数
		{
			int j = temp / (int)pow(10, i);
			if (j == 0)
				break;
			wei = i + 1;
		}
		memset(num, 0, sizeof(num));
		for (int i = 0, w = wei; w != 0; i++)//存入
		{
			int in = temp / (int)pow(10, --w);
			num[i] = '0' + (char)in;
			temp -= in * (int)pow(10, w);
		}

		int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
		int time = 0;//time越小关联性越高
		for (int i = 0; i <= (int)strlen(num) - (int)strlen(input_num); i++)
		{
			int k = 0;
			for (int j = i; j < i + strlen(input_num); j++)
				*(temp2 + k++) = num[j];
			if (strcmp(temp2, input_num) == 0)
			{
				jug = 1;
				break;
			}
			time++;//每检查一次，time+1
		}
		if (jug)
		{
			p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
			if (p == NULL)
			{
				logError(0);
				return NULL;
			}
			strcpy(p->num, num);
			p->time = time;
			p->position = a;
			tail->next = p;
			tail = p;
			tail->next = NULL;//延长链表
			geshu++;
			jug = 0;
		}
	}
	position = (int*)malloc(geshu * sizeof(int));
	if (position == NULL)
	{
		logError(0);
		return NULL;
	}
	for (int i = 0; geshu != 0; i++)
	{
		p = head->next;

		while (1)
		{
			if (p == NULL)
			{
				logError(0);
				return NULL;
			}
			if (i == p->time)
			{
				*(position++) = p->position;
				//此处还可实现其他功能
				geshu--;
			}
			if (p->next == NULL)
				break;
			p = p->next;
		}
	}
	struct MyStruct* p2;
	p = head;
	p2 = head->next;
	while (1)
	{
		free(p);
		p = p2;
		if (p == NULL)
		{
			logError(0);
			return NULL;
		}
		p2 = p->next;
		if (p2 == NULL)
		{
			free(p);
			break;
		}
	}
	free(temp2);
	return position;
}

/*********************************************
字符串搜索，依然是返回其地址，还是需要free释放
需要输入中介、租客、预约三个链表的head
kind是搜索字符串来自那个链表，1是agency，2是customer
3是appointment,4是flat
注意：本函数不具备普遍性
数组第一个数是数组中的元素个数（不包括第一个）
*********************************************/
int* string_seach(char* input, struct Agency* ah, struct Customer* ch, struct Flat* fh, struct Appointment* aph, int kind)
{
	int max;
	int geshu = 0;//有效数据的个数
	int* position;
	char* temp2;
	int* arr;
	arr = NULL;
	temp2 = NULL;
	position = NULL;
	//构建临时链表
	struct MyStruct
	{
		char string[20];
		int time;//相关度
		struct MyStruct* next;
		int position;
	};
	struct MyStruct* p, * head, * tail;
	p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
	if (p == NULL)
	{
		logError(0);
		return NULL;
	}
	head = p;
	tail = p;
	p->next = NULL;

	switch (kind)
	{
	case 1:
		max = countNumberAG(ah);
		struct Agency* ap;
		ap = ah;
		temp2 = (char*)malloc(51 * sizeof(char));//临时储存与输入字符串长度相同的数据
		if (temp2 == NULL)//动态分配的内存不是NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(ap->Account) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = ap->Account[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, ap->Account);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		ap = ah;
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(ap->phone_n) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = ap->phone_n[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, ap->phone_n);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		ap = ah;
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(ap->Name) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = ap->Name[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, ap->Name);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		ap = ah;
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(ap->Number) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = ap->Number[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, ap->Number);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		break;
	case 2:
		max = countNumberCU(ch);
		struct Customer* cp;
		cp = ch;
		temp2 = (char*)malloc(51 * sizeof(char));//临时储存与输入字符串长度相同的数据
		if (temp2 == NULL)//动态分配的内存不是NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			cp = cp->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(cp->Account) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = cp->Account[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, cp->Account);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		cp = ch;
		for (int a = 0; a != max; a++)
		{
			cp = cp->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(cp->phone_n) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = cp->phone_n[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, cp->phone_n);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		cp = ch;
		for (int a = 0; a != max; a++)
		{
			cp = cp->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(cp->Name) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = cp->Name[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, cp->Name);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		break;
	case 3:
		max = countNumberAP(aph);
		struct Appointment* app;
		app = aph;
		temp2 = (char*)malloc(51 * sizeof(char));//临时储存与输入字符串长度相同的数据
		if (temp2 == NULL)//动态分配的内存不是NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(app->Number) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = app->Number[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, app->Number);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(app->custom->Account) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = app->custom->Account[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, app->custom->Account);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(app->custom->Name) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = app->custom->Name[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, app->custom->Name);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(app->custom->phone_n) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = app->custom->phone_n[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, app->custom->phone_n);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(app->flat->number) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = app->flat->number[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, app->flat->number);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
		break;
	case 4:
		max = countNumberFL(fh);
		struct Flat* fp;
		fp = fh;
		temp2 = (char*)malloc(51 * sizeof(char));//临时储存与输入字符串长度相同的数据
		if (temp2 == NULL)//动态分配的内存不是NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			fp = fp->next;
			int jug = 0;//判断数据与输入项是否有关联，0无关联，1有关联
			int time = 0;//time越小关联性越高
			for (int i = 0; i <= (int)strlen(fp->number) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = fp->number[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, fp->number);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
			fp = fh;
			for (int i = 0; i <= (int)strlen(fp->city) - (int)strlen(input); i++)
			{
				int k = 0;
				for (int j = i; j < i + strlen(input); j++)
					*(temp2 + k++) = fp->city[j];
				if (strcmp(temp2, input) == 0)
				{
					jug = 1;
					break;
				}
				time++;//每检查一次，time+1
			}
			if (jug)
			{
				p = (struct MyStruct*)malloc(sizeof(struct MyStruct));
				if (p == NULL)
				{
					logError(0);
					return NULL;
				}
				strcpy(p->string, fp->city);
				p->time = time;
				p->position = a;
				tail->next = p;
				tail = p;
				tail->next = NULL;//延长链表
				geshu++;
				jug = 0;
			}
		}
	}
	position = (int*)malloc((geshu + 1)* sizeof(int));
	arr = (int*)malloc(geshu * sizeof(int));
	if (position == NULL)
	{
		logError(0);
		return NULL;
	}
	*position = geshu;
	int j = 0;
	for (int i = 0; geshu != 0; i++)
	{
		p = head->next;

		while (1)
		{
			if (p == NULL)
			{
				logError(0);
				return NULL;
			}
			if (i == p->time)
			{
				*(arr+(j++)) = p->position;
				//此处还可实现其他功能
				geshu--;
			}
			if (p->next == NULL)
				break;
			p = p->next;
		}
	}
	struct MyStruct* p2;
	p = head;
	p2 = head->next;
	while (1)
	{
		free(p);
		p = p2;
		if (p == NULL && *position!=0)
		{
			logError(0);
			return NULL;
		}
		if (p == NULL && *position == 0)
			break;
		p2 = p->next;
		if (p2 == NULL)
		{
			free(p);
			break;
		}
	}
	removeDuplicates(arr, position);
	j = 1;
	for (int i = 0; i < *position; i++)
		*(position + i + 1) = *(arr + i);
	if (temp2 != NULL)
		free(temp2);
	free(arr);
	return position;
}
