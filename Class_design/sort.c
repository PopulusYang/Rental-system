#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"
//链表排序（冒泡)(房子面积）
//jug用于判断具体排什么的顺序
void bubbleSort_Area(Flat** head,int jug) 
{
	if (*head == NULL || (*head)->next == NULL) 
	{
		return; // 空链表或只有一个节点，无需排序  
	}
	int swapped;
	if (jug == 1)
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
	if (jug == 2)
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
	if (jug == 3)
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
int  bubbleSort_more(Flat** head, int jug1,int jug2)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // 空链表或只有一个节点，无需排序  
	}
	int swapped;
	if (jug1 == 1 && jug2 == 2)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent&&ptr1->floor>ptr1->next->floor)
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
		return 1;
	}
	else if (jug1 == 1 && jug2 == 3)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent && ptr1->Area > ptr1->next->Area)
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
		return 1;
	}
	else if (jug1 == 2 && jug2 == 1)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->rent > ptr1->next->rent)
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
		return 1;
	}
	else if (jug1 == 2 && jug2 == 3)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->Area > ptr1->next->Area)
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
		return 1;
	}
	else if (jug1 == 3 && jug2 == 1)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->rent > ptr1->next->rent)
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
		return 1;
	}
	else if (jug1 == 3 && jug2 == 2)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->floor > ptr1->next->floor)
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
		return 1;
	}
	else if(jug1==jug2)
	{
		return 2;
	}
	else
	{
		return 3;
		}
}