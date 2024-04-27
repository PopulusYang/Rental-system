#include "list.h"
#include "temphead.h"




//n为字符个数,返回字符串地址
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
		logError(0);
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

int checkRecurAP(char* num, struct Appointment* aphead)
{

	struct Appointment* p;
	p = aphead->next;
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

void hideInput(char* buffer, int maxLength) 
{
	int i = 0;
	char ch;
	while (i < maxLength - 1)
	{
		if (_kbhit()) 
		{ 
			ch = _getch();

			if (ch == 13)
			{
				buffer[i] = '\0';
				printf("\n");
				break; 
			}
			else if (ch == 8 && i > 0) 
			{ 
				printf("\b \b");
				i--; 
			}
			else {
				printf("*"); 
				buffer[i++] = ch;
			}
		}
		else 
		{
			Sleep(5);
		}
	}
	fflush(stdout);
}

void choose()//用于清屏
{
	char wait;
	scanf("%c", &wait);
	if (wait == '\n')
		system("cls");
	else
		choose();
}