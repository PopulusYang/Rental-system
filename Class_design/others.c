#include "list.h"
#include "temphead.h"




//nΪ�ַ�����,�����ַ�����ַ
char* radom_string(int n)
{
	char* str;
	n++;
	str = (char*)malloc(n * sizeof(char));
	if (str == NULL)
	{
		logError(0);
		return NULL;
	}
	memset(str, 0, (n) * sizeof(char));
	const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
	size_t len = sizeof(charset) - 1;//��������
	unsigned int seed;
	seed = (unsigned int)time(NULL);
	srand(seed);
	n--;
	for (size_t i = 0; i < n; i++)
	{
		str[i] = charset[rand() % len];
	}
	return str;
}

//nΪ���ָ���,�����ַ�����ַ
char* radom_number(int n)
{
	char* str;
	n++;
	str = (char*)malloc(n * sizeof(char));
	if (str == NULL)
	{
		logError(0);
		return NULL;
	}
	memset(str, 0, (n) * sizeof(char));
	const char charset[] = "0123456789";
	size_t len = sizeof(charset) - 1;//��������
	unsigned int seed;
	seed = (unsigned int)time(NULL);
	srand(seed);
	n--;
	for (size_t i = 0; i < n; i++)
	{
		str[i] = charset[rand() % len];
	}
	return str;
}

int countNumberAD(struct Admin* head)
{
	struct Admin* p;
	p = head->next;
	int number = 0;
	while (p != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}

//����������Ԫ�ظ��������ӣ�
int countNumberFL(struct Flat* head)
{
	struct Flat* p;
	p = head->next;
	int number = 0;
	while (p != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}

//����������Ԫ�ظ������н飩
int countNumberAG(struct Agency* head)
{
	struct Agency* p;
	p = head->next;
	int number = 0;
	while (p != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}
//����������Ԫ�ظ�������ͣ�
int countNumberCU(struct Customer* head)
{
	struct Customer* p;
	p = head->next;
	int number = 0;
	while (p != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}

//����������Ԫ�ظ�����ԤԼ��Ϣ��
int countNumberAP(struct Appointment* head)
{
	struct Appointment* p;
	p = head->next;
	int number = 0;
	while (p != NULL)
	{
		p = p->next;
		number++;
	}
	return number;
}

//��Ų���
int checkRecurFL(char* num, struct Flat* fhead)
{

	struct Flat* p;
	p = fhead->next;
	while (p != NULL)
	{
		if (!strcmp(num, p->number))
			return 1;
		p = p->next;
	}
	return 0;
}
int checkRecurAG(char* num, struct Agency* aghead)
{

	struct Agency* p;
	p = aghead->next;
	while (p != NULL)
	{
		if (!strcmp(num, p->Number))
			return 1;
		p = p->next;
	}
	return 0;
}
//ȥ�������е��ظ�����
void removeDuplicates(int* arr, int* length) 
{
	for (int i = 0; i < *length; i++)
	{
		for (int j = i + 1; j < *length; j++)
		{
			if (arr[i] == arr[j])
			{
				(*length)--;
				for (int k = j; k < *length; k++)
					arr[k] = arr[k + 1];
				j--;
			}
		}
	}
}

