#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"	
/*************************************************
����������.input_num������������������ַ�������
�����ͣ�num_group�����ݼ��ϣ����飬max�������е���
����������������ʱ����NULL���������ظ������������
�����е�λ�á��䷵�صĵ�ַ��Ҫfree�ͷ�.
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
	char num[20] = { '\0' };//�������е���ת��Ϊ�ַ���
	int wei = 1;//����λ��

	char* temp2 = (char*)malloc(strlen(input_num) * sizeof(char));//��ʱ�����������ַ���������ͬ������
	if (temp2 == NULL)//��̬������ڴ治��NULL
	{
		logError(0);
		return NULL;
	}
	memset(temp2, 0, ((int)strlen(input_num)+1) * sizeof(char));
	int geshu = 0;//��Ч���ݵĸ���
	for (int a = 0; a != max; a++)
	{
		int temp = *(num_group + a);
		for (int i = 0;; i++)//����λ��
		{
			int j = temp / (int)pow(10, i);
			if (j == 0)
				break;
			wei = i + 1;
		}
		memset(num, 0, sizeof(num));
		for (int i = 0, w = wei; w != 0; i++)//����
		{
			int in = temp / (int)pow(10, --w);
			num[i] = '0' + (char)in;
			temp -= in * (int)pow(10, w);
		}

		int jug = 0;//�ж��������������Ƿ��й�����0�޹�����1�й���
		int time = 0;//timeԽС������Խ��
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
			strcpy(p->num, num);
			p->time = time;
			p->position = a;
			tail->next = p;
			tail = p;
			tail->next = NULL;//�ӳ�����
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
�ַ�����������Ȼ�Ƿ������ַ��������Ҫfree�ͷ�
��Ҫ�����н顢��͡�ԤԼ���������head
kind�������ַ��������Ǹ�����1��agency��2��customer
3��appointment,4��flat
ע�⣺���������߱��ձ���
�����һ�����������е�Ԫ�ظ�������������һ����
*********************************************/
int* string_seach(char* input, struct Agency* ah, struct Customer* ch, struct Flat* fh, struct Appointment* aph, int kind)
{
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
