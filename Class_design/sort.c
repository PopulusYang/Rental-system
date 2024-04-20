#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"
//数组排序
int I_sort(float* a, int l, int r)// l 为左端点，r 为右端点
{
	a++;
	if (l >= r)//判断左端点是否在右端点左侧
	{
		logError(1);
		return -1;
	}
	float* b = (float*)malloc(r * sizeof(float));
	float* c = (float*)malloc(r * sizeof(float));
	float* d = (float*)malloc(r * sizeof(float));
	if (b == NULL|| c == NULL|| d == NULL)
	{
		logError(0);
		return -1;
	}
	int num = rand() % (r - l + 1) + l;
	int num1 = 0, num2 = 0, num3 = 0; // 随机选择一个数，并定义三个作为下标的变量来记录长度、存放数据
	for (int i = l; i <= r; i++)// 将 a 中的数分别分到 b, c, d
	{
		if (a[i] < a[num]) 
		{
			b[num1++] = a[i];
		}
		else if (a[i] == a[num]) 
		{
			c[num2++] = a[i];
		}
		else 
		{
			d[num3++] = a[i];
		}
	}
	for (int i = 0; i < num1; i++) // 将 b, c, d 中的数重新放回 a
	{
		a[i + l] = b[i];
	}
	for (int i = 0; i < num2; i++)
	{
		a[i + num1 + l] = c[i];
	}
	for (int i = 0; i < num3; i++)// 继续排序原来的 b 和 d
	{
		a[i + num1 + num2 + l] = d[i];
	}
	free(b);
	free(c);
	free(d);
	I_sort(a,l, l + num1 - 1);
	I_sort(a,l + num1 + num2, r);
	return 0;
}

//链表排序（冒泡)(房子面积）
//jug用于判断具体排什么的顺序
void bubbleSort_Area(Flat** head,int jug) 
{
	if (*head == NULL || (*head)->next == NULL) 
	{
		return; // 空链表或只有一个节点，无需排序  
	}
	int swapped;
	if (jug = 1)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->rent > ptr1->next->rent)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
	}
	if (jug = 2)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->floor > ptr1->next->floor)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
	}
	if (jug = 3)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->Area > ptr1->next->Area)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
	}
}