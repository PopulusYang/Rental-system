#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"
//��������ð��)(���������
//jug�����жϾ�����ʲô��˳��
void bubbleSort_Area(Flat** head,int jug) 
{
	if (*head == NULL || (*head)->next == NULL) 
	{
		return; // �������ֻ��һ���ڵ㣬��������  
	}
	int swapped;
	if (jug == 1)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->rent > ptr1->next->rent)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
	}
	if (jug == 2)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->floor > ptr1->next->floor)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
	}
	if (jug == 3)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->Area > ptr1->next->Area)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
	}
}
int  bubbleSort_more(Flat** head, int jug1,int jug2)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // �������ֻ��һ���ڵ㣬��������  
	}
	int swapped;
	if (jug1 == 1 && jug2 == 2)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent&&ptr1->floor>ptr1->next->floor)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 1 && jug2 == 3)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent && ptr1->Area > ptr1->next->Area)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 2 && jug2 == 1)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->rent > ptr1->next->rent)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 2 && jug2 == 3)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->Area > ptr1->next->Area)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 3 && jug2 == 1)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->rent > ptr1->next->rent)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 3 && jug2 == 2)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->floor > ptr1->next->floor)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
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