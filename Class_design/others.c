#include "list.h"
#include "temphead.h"


/************************************
由于部分排序搜索函数使用数组进行操作，
因此写一个将链表转换成数组的函数很有
必要
************************************/

//输入的为头和目标数组，返回值为租金数组地址，其中第一个数是数组元素个数.配合free.
float* GetNumber_FL_float(struct Flat* head)
{
	struct Flat* p;
	p = head->next;
	float number = 0.0f;
	while (p != NULL)
	{
		number++;
		p = p->next;
	}
	float* numG;
	numG = (float*)malloc((int)number * sizeof(float));
	if (numG == NULL)
	{
		logError(0);
		return NULL;
	}
	*(numG++) = number;
	p = head->next;
	if (p == NULL)//判断申请的空间是否为空（NULL）
	{
		logError(0);
		return NULL;
	}
	while (p != NULL)
	{
		assert(numG);
		*(numG++) = p->rent;
		p = p->next;
	}
	return numG;
}


//n为字符个数,返回字符串地址
char* radom_string(int n)
{
	char* str;
	n++;
	str = (char*)malloc(n * sizeof(char));
	if (str == NULL)
	{
		logError(1);
		return NULL;
	}
	memset(str, 0, (n) * sizeof(char));
	const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
	size_t len = sizeof(charset) - 1;//生成种子
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

//n为数字个数,返回字符串地址
char* radom_number(int n)
{
	char* str;
	n++;
	str = (char*)malloc(n * sizeof(char));
	if (str == NULL)
	{
		logError(1);
		return NULL;
	}
	memset(str, 0, (n) * sizeof(char));
	const char charset[] = "0123456789";
	size_t len = sizeof(charset) - 1;//生成种子
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

//计算链表中元素个数（房子）
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

//计算链表中元素个数（中介）
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
//计算链表中元素个数（租客）
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

//计算链表中元素个数（预约信息）
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

//编号查重
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
//去掉数组中的重复数据
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