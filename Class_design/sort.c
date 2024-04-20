#define _CRT_SECURE_NO_WARNINGS
#include "temphead.h"
//��������
int I_sort(float* a, int l, int r)// l Ϊ��˵㣬r Ϊ�Ҷ˵�
{
	a++;
	if (l >= r)//�ж���˵��Ƿ����Ҷ˵����
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
	int num1 = 0, num2 = 0, num3 = 0; // ���ѡ��һ������������������Ϊ�±�ı�������¼���ȡ��������
	for (int i = l; i <= r; i++)// �� a �е����ֱ�ֵ� b, c, d
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
	for (int i = 0; i < num1; i++) // �� b, c, d �е������·Ż� a
	{
		a[i + l] = b[i];
	}
	for (int i = 0; i < num2; i++)
	{
		a[i + num1 + l] = c[i];
	}
	for (int i = 0; i < num3; i++)// ��������ԭ���� b �� d
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

//��������ð��)(���������
//jug�����жϾ�����ʲô��˳��
void bubbleSort_Area(Flat** head,int jug) 
{
	if (*head == NULL || (*head)->next == NULL) 
	{
		return; // �������ֻ��һ���ڵ㣬��������  
	}
	int swapped;
	if (jug = 1)
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
	if (jug = 2)
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
	if (jug = 3)
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