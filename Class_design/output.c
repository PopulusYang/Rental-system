#include "list.h"
#include "temphead.h"

void outputFL(int position,struct Flat* head)
{
	struct Flat* p;
	p = head->next;
	for (int i = 0; i < position; i++)
		p = p->next;
	printf("编号\t位置\t面积\t房型\t租金\n");
	printf("%s\t%s\t%.2f\t%d室%d厅\t%.2f\n", p->number, p->city, p->Area, p->shi, p->ting, p->rent);
}

void list_print(list_1 mylist)
{
    struct Flat* head, * end, * temp;
    head = mylist;
    end = NULL;
    temp = head;
    while (1)
    {
        if ((temp->next == NULL))
        {
            return;
        }
        printf("%s", temp->number);
        printf("%4.2f", temp->Area);
        printf("%d室%d厅\t", temp->shi, temp->ting);
        printf("%4.2f", temp->rent);
        temp = temp->next;
    }
}