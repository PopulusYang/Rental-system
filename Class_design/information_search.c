#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"	

/*********************************************
�ַ�����������Ȼ�Ƿ������ַ��������Ҫfree�ͷ�
��Ҫ�����н顢��͡�ԤԼ���������head
kind�������ַ��������Ǹ�����1��agency��2��customer
3��appointment,4��flat
ע�⣺���������߱��ձ���
�����һ�����������е�Ԫ�ظ�������������һ����
*********************************************/
int* string_seach(char* input, struct Agency* ah, struct Customer* ch, struct Flat* fh, struct Appointment* aph, int kind)
{
	logInfo(6);
	int max;
	int geshu = 0;//��Ч���ݵĸ���
	int* position;
	char* temp2;
	int* arr;
	arr = NULL;
	temp2 = NULL;
	position = NULL;
	//������ʱ����
	struct MyStruct
	{
		char string[20];
		int time;//��ض�
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
		temp2 = (char*)malloc(51 * sizeof(char));//��ʱ�����������ַ���������ͬ������
		if (temp2 == NULL)//��̬������ڴ治��NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		ap = ah;
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		ap = ah;
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		ap = ah;
		for (int a = 0; a != max; a++)
		{
			ap = ap->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		break;
	case 2:
		max = countNumberCU(ch);
		struct Customer* cp;
		cp = ch;
		temp2 = (char*)malloc(51 * sizeof(char));//��ʱ�����������ַ���������ͬ������
		if (temp2 == NULL)//��̬������ڴ治��NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			cp = cp->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		cp = ch;
		for (int a = 0; a != max; a++)
		{
			cp = cp->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		cp = ch;
		for (int a = 0; a != max; a++)
		{
			cp = cp->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		break;
	case 3:
		max = countNumberAP(aph);
		struct Appointment* app;
		app = aph;
		temp2 = (char*)malloc(51 * sizeof(char));//��ʱ�����������ַ���������ͬ������
		if (temp2 == NULL)//��̬������ڴ治��NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		app = aph;
		for (int a = 0; a != max; a++)
		{
			app = app->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}
		}
		break;
	case 4:
		max = countNumberFL(fh);
		struct Flat* fp;
		fp = fh;
		temp2 = (char*)malloc(51 * sizeof(char));//��ʱ�����������ַ���������ͬ������
		if (temp2 == NULL)//��̬������ڴ治��NULL
		{
			logError(0);
			return NULL;
		}
		memset(temp2, 0, 51 * sizeof(char));
		for (int a = 0; a != max; a++)
		{
			fp = fp->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
				geshu++;
				jug = 0;
			}			
		}
		fp = fh;
		for (int a = 0; a != max; a++)
		{
			fp = fp->next;
			int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
			int time = 0;//timeԽС������Խ��
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
				time++;//ÿ���һ�Σ�time+1
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
				tail->next = NULL;//�ӳ�����
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
				//�˴�����ʵ����������
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

int toward_search(list_1 mylist_head, int i)
{
	int n = 0;
	struct Flat* p1;
	if (mylist_head->next == NULL)
	{
		logError(0);
		return -1;
	}
	p1 = mylist_head->next;
	while (p1 != NULL)
	{
		//�����Ҫ�����ӡ
		if ((int)p1->toward == i)
		{
			n++;
			printf("%d:\t", n);
			printf("%s\t", p1->number);//������Ҫ���ĳ����
			printf("%4.2f\t", p1->Area);
			printf("%d��%d��\t", p1->shi, p1->ting);
			printf("����Ϊ");
			switch ((int)p1->toward)
			{
			case 1:
				printf("��\n");
				break;
			case 2:
				printf("��\n");
				break;
			case 3:
				printf("��\n");
				break;
			case 4:
				printf("��\n");
				break;
			case 5:
				printf("����\n");
				break;
			case 6:
				printf("����\n");
				break;
			case 7:
				printf("����\n");
				break;
			case 8:
				printf("����\n");
				break;

			}
		}
		p1 = p1->next;
	}
	return n;
}


int toward_search_ag(list_1 mylist_head, int i)
{
	int n = 0;
	struct Flat* p1;
	if (mylist_head->next == NULL)
	{
		logError(0);
		return -1;
	}
	p1 = mylist_head->next;
	while (p1 != NULL)
	{
		//�����Ҫ�����ӡ
		if ((int)p1->toward == i && p1->agency == NULL)
		{
			n++;
			printf("%d:\t", n);
			printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
			printf("%4.2f\t", p1->Area);
			printf("%d��%d��\t", p1->shi, p1->ting);
			printf("����Ϊ");
			switch ((int)p1->toward)
			{
			case 1:
				printf("��\n");
				break;
			case 2:
				printf("��\n");
				break;
			case 3:
				printf("��\n");
				break;
			case 4:
				printf("��\n");
				break;
			case 5:
				printf("����\n");
				break;
			case 6:
				printf("����\n");
				break;
			case 7:
				printf("����\n");
				break;
			case 8:
				printf("����\n");
				break;

			}
		}
		p1 = p1->next;
	}
	return n;
}
int toward_search_cu(list_1 mylist_head, int i)
{
	int n = 0;
	struct Flat* p1;
	if (mylist_head->next == NULL)
	{
		logError(0);
		return -1;
	}
	p1 = mylist_head->next;
	while (p1 != NULL)
	{
		//�����Ҫ�����ӡ
		if ((int)p1->toward == i && p1->agency != NULL)
		{
			n++;
			printf("%d:\t", n);
			printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
			printf("%4.2f\t", p1->Area);
			printf("%d��%d��\t", p1->shi, p1->ting);
			printf("����Ϊ");
			switch ((int)p1->toward)
			{
			case 1:
				printf("��\n");
				break;
			case 2:
				printf("��\n");
				break;
			case 3:
				printf("��\n");
				break;
			case 4:
				printf("��\n");
				break;
			case 5:
				printf("����\n");
				break;
			case 6:
				printf("����\n");
				break;
			case 7:
				printf("����\n");
				break;
			case 8:
				printf("����\n");
				break;

			}
		}
		p1 = p1->next;
	}
	return n;
}

int range_search_ag(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2)//�Է������Ϊ����
{
	Flat* temp;
	temp = mylist_head;
	bubbleSort_Area(&temp, jug2);
	struct Flat* p1;
	int t = 0;
	//����
	if (mylist_head->next == NULL)
	{
		logError(0);
		return -1;
	}
	p1 = mylist_head->next;
	assert(p1);
	if (jug2 == 1)
	{
		while (p1 != NULL && jug == 1)
		{
			//�����Ҫ�����ӡ
			if (p1->rent >= l && p1->rent <= r && p1->agency == NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
				printf("%4.2f\t", p1->Area);
				printf("%d��%d��\t", p1->shi, p1->ting);
				printf("����Ϊ");
				switch ((int)p1->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			p1 = p1->next;
		}
		//����
		while (mylist_tail->prev != NULL && jug == 2)
		{
			//�����Ҫ�����ӡ
			if (mylist_tail->rent >= l && mylist_tail->rent <= r && mylist_tail->agency == NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%s\t", mylist_tail->number);//�ĳ����
				printf("%4.2fƽ����\n", mylist_tail->Area);
				printf("%d��%d��\t", mylist_tail->shi, mylist_tail->ting);
				printf("����Ϊ");
				switch ((int)mylist_tail->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			mylist_tail = mylist_tail->prev;
		}
	}
	if (jug2 == 2)
	{
		while (p1 != NULL && jug == 1)
		{
			//�����Ҫ�����ӡ
			if (p1->floor >= l && p1->floor <= r && p1->agency == NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
				printf("%4.2f\t", p1->Area);
				printf("%d��%d��\t", p1->shi, p1->ting);
				printf("����Ϊ");
				switch ((int)p1->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			p1 = p1->next;
		}
		//����
		while (mylist_tail->prev != NULL && jug == 2)
		{
			//�����Ҫ�����ӡ
			if (mylist_tail->floor >= l && mylist_tail->floor <= r && mylist_tail->agency == NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", mylist_tail->number);//�ĳ����
				printf("%4.2f\t", mylist_tail->Area);
				printf("%d��%d��\t", mylist_tail->shi, mylist_tail->ting);
				printf("����Ϊ");
				switch ((int)mylist_tail->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			mylist_tail = mylist_tail->prev;
		}
	}
	if (jug2 == 3)
	{
		while (p1 != NULL && jug == 1)
		{
			//�����Ҫ�����ӡ
			if (p1->Area >= l && p1->Area <= r && p1->agency == NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
				printf("%4.2f\t", p1->Area);
				printf("%d��%d��\t", p1->shi, p1->ting);
				printf("����Ϊ");
				switch ((int)p1->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			p1 = p1->next;
		}
		//����
		while (mylist_tail->prev != NULL && jug == 2)
		{
			//�����Ҫ�����ӡ
			if (mylist_tail->Area >= l && mylist_tail->Area <= r && mylist_tail->agency == NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%s\t", mylist_tail->number);//�ĳ����
				printf("%4.2fƽ����\n", mylist_tail->Area);
				printf("%d��%d��\t", mylist_tail->shi, mylist_tail->ting);
				printf("����Ϊ");
				switch ((int)mylist_tail->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			mylist_tail = mylist_tail->prev;
		}
	}
	return t;
}
int range_search_cu(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2)//�Է������Ϊ����
{
	Flat* temp;
	temp = mylist_head;
	bubbleSort_Area(&temp, jug2);
	struct Flat* p1;
	int t = 0;
	//����
	if (mylist_head->next == NULL)
	{
		logError(0);
		return -1;
	}
	p1 = mylist_head->next;
	assert(p1);
	if (jug2 == 1)
	{
		while (p1 != NULL && jug == 1)
		{
			//�����Ҫ�����ӡ
			if (p1->rent >= l && p1->rent <= r && p1->agency != NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
				printf("%4.2f\t", p1->Area);
				printf("%d��%d��\t", p1->shi, p1->ting);
				printf("����Ϊ");
				switch ((int)p1->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			p1 = p1->next;
		}
		//����
		while (mylist_tail->prev != NULL && jug == 2)
		{
			//�����Ҫ�����ӡ
			if (mylist_tail->rent >= l && mylist_tail->rent <= r && mylist_tail->agency != NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%s\t", mylist_tail->number);//�ĳ����
				printf("%4.2fƽ����\n", mylist_tail->Area);
				printf("%d��%d��\t", mylist_tail->shi, mylist_tail->ting);
				printf("����Ϊ");
				switch ((int)mylist_tail->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			mylist_tail = mylist_tail->prev;
		}
	}
	if (jug2 == 2)
	{
		while (p1 != NULL && jug == 1)
		{
			//�����Ҫ�����ӡ
			if (p1->floor >= l && p1->floor <= r && p1->agency != NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
				printf("%4.2f\t", p1->Area);
				printf("%d��%d��\t", p1->shi, p1->ting);
				printf("����Ϊ");
				switch ((int)p1->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			p1 = p1->next;
		}
		//����
		while (mylist_tail->prev != NULL && jug == 2)
		{
			//�����Ҫ�����ӡ
			if (mylist_tail->floor >= l && mylist_tail->floor <= r && mylist_tail->agency != NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", mylist_tail->number);//�ĳ����
				printf("%4.2f\t", mylist_tail->Area);
				printf("%d��%d��\t", mylist_tail->shi, mylist_tail->ting);
				printf("����Ϊ");
				switch ((int)mylist_tail->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			mylist_tail = mylist_tail->prev;
		}
	}
	if (jug2 == 3)
	{
		while (p1 != NULL && jug == 1)
		{
			//�����Ҫ�����ӡ
			if (p1->Area >= l && p1->Area <= r && p1->agency != NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%sƽ����\n", p1->number);//������Ҫ���ĳ����
				printf("%4.2f\t", p1->Area);
				printf("%d��%d��\t", p1->shi, p1->ting);
				printf("����Ϊ");
				switch ((int)p1->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			p1 = p1->next;
		}
		//����
		while (mylist_tail->prev != NULL && jug == 2)
		{
			//�����Ҫ�����ӡ
			if (mylist_tail->Area >= l && mylist_tail->Area <= r && mylist_tail->agency != NULL)
			{
				t++;
				printf("%d:\t", t);
				printf("%s\t", mylist_tail->number);//�ĳ����
				printf("%4.2fƽ����\n", mylist_tail->Area);
				printf("%d��%d��\t", mylist_tail->shi, mylist_tail->ting);
				printf("����Ϊ");
				switch ((int)mylist_tail->toward)
				{
				case 1:
					printf("��\n");
					break;
				case 2:
					printf("��\n");
					break;
				case 3:
					printf("��\n");
					break;
				case 4:
					printf("��\n");
					break;
				case 5:
					printf("����\n");
					break;
				case 6:
					printf("����\n");
					break;
				case 7:
					printf("����\n");
					break;
				case 8:
					printf("����\n");
					break;

				}
			}
			mylist_tail = mylist_tail->prev;
		}
	}
	return t;
}

