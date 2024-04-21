#define _CRT_SECURE_NO_WARNINGS
#include"temphead.h"
#include"list.h"
#pragma warning(disable:6031) 
typedef struct Flat Flat, * list_1;
//�ӳ�Flat����д��
int extend_writeFlat(list_1 p1, list_1 head, list_1 tail, char* city, float area, int t, int floor, float rent,int shi,int ting,struct Agency* ag)
{
    p1 = (struct Flat*)malloc(sizeof(struct Flat));
    if (p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;
    }
    int debug = 0;//�ֻ����������
    strcpy(p1->city, city);
    p1->Area = area;
    p1->shi = shi;
    p1->ting = ting;
    do
    {
        if (debug == 1)
        {
            printf("����ȷ���볯�򣡣���\n");
            printf("�����볯��\n");
            scanf("%d", &t);
        }
        switch (t)
        {
        case 1:
            p1->toward = 1;
            debug = 0;
            break;
        case 2:
            p1->toward = 2;
            debug = 0;
            break;
        case 3:
            p1->toward = 3;
            debug = 0;
            break;
        case 4:
            p1->toward = 4;
            debug = 0;
            break;
        case 5:
            p1->toward = 5;
            debug = 0;
            break;
        case 6:
            p1->toward = 6;
            debug = 0;
            break;
        case 7:
            p1->toward = 7;
            debug = 0;
            break;
        case 8:
            p1->toward = 8;
            debug = 0;
            break;
        default:
            debug = 1;
            break;
        }
    } while (debug != 0);
    p1->floor = floor;
    p1->rent = rent;
    p1->agency_fee = p1->rent * 0.01f;//������Ϊ�����İٷ�֮һ
    p1->deposit = p1->rent * 3;//Ѻ��Ϊ���������
    char* temp;
    temp = radom_number(8);
    while (checkRecurFL(temp, head))
    {
        free(temp);
        temp = radom_number(8);
    }
        
    strcpy(p1->number, temp);
    if (ag == NULL)
    {
        memset(p1->agposition, 0, sizeof(p1->agposition));
    }
    else
        strcpy(p1->agposition, ag->Number);
    p1->agency = ag;
    //�����޸Ķ�������
    p1->prev = tail;
    tail->next = p1;
    tail = p1;
    tail->next = NULL;

    return 0;
}

//�ӳ�Admin����
int extendAdmin(char* Account, char* key, struct Admin* p1, struct Admin* p2, struct Admin* tail)
{
    p1 = (struct Admin*)malloc(sizeof(struct Admin));
    if (p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;

    }
    strcpy(p1->Account, Account);
    strcpy(p1->Key, key);


    //�����޸Ķ�������
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//�ӳ�����
    return 0;
}

//�ӳ�Agency����
int extendAgency(char* Account, char* key, struct Agency* p1, struct Agency* head, struct Agency* tail)
{
    p1 = (struct Agency*)malloc(sizeof(struct Agency));
    if (p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;

    }
    strcpy(p1->Account, Account);
    strcpy(p1->Key, key);
    char* temp;
    temp = radom_number(8);//���ɱ��

    while (checkRecurAG(temp, head))//����
    {
        free(temp);
        temp = radom_number(8);
    }
    strcpy(p1->Number,temp);//����
    free(temp);

    //�����޸Ķ�������
    tail->next = p1;
    p1->prev = tail;
    tail = p1;
    tail->next = NULL;
    return 0;
}


//�ӳ�Customer����
int extendCustomer(char* Account, char* key, struct Customer* p1, struct Customer* p2, struct Customer* tail)
{
    p1 = (struct Customer*)malloc(sizeof(struct Customer));
    if (p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;

    }
    strcpy(p1->Account, Account);
    strcpy(p1->Key, key);
    p1->statment = 1;

    //�����޸Ķ�������
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//�ӳ�����
    return 0;
}

//�ӳ�ԤԼ��Ϣ
int extendApm(struct Appointment* p, struct Appointment* tail, int year, int month, int day, struct Flat* flat, struct Customer* custom)
{
    p = (struct Appointment*)malloc(sizeof(struct Appointment));
    if (p == NULL)//ע�ⰲȫ
    {
        logError(0);
        return -1;
    }
    p->day = day;
    p->month = month;
    p->year = year;
    p->custom = custom;
    p->flat = flat;
    strcpy(p->cuposition, custom->Account);
    strcpy(p->flposition, flat->number);
    tail->next = p;
    return 0;
}

int DelListall(list_1 mylist, int t) //tΪɾ�������
{
    if (mylist->next == NULL)
    {
        logError(0);
        return 1;
    }
    struct Flat* head, * end, * temp;
    int i;
    head = mylist;
    temp = head->next;
    end = NULL;
    for (i = 0; i < t; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        assert(temp);
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    temp = NULL;
    return 0;
}
//���Ҳ���������һ����Χ�ڵķ�����Ϣ
//l��rΪ���Ҷ˵�
//jugΪ����or����
//jug2�ж���ʲô��˳��
int range_search_Area(int l,int r,Flat* mylist_head,list_1 mylist_tail, int jug,int jug2)//�Է������Ϊ����
{
    bubbleSort_Area(&mylist_head,jug2);
    struct Flat* p1;
    int t = 0;
    //����
    if (mylist_head->next = NULL)
    {
        logError(0);
        return -1;
    }
    p1 = mylist_head->next;
    assert(p1);
    if (jug2 == 1)
    {
        while (p1->next != NULL && jug == 1)
        {
            //�����Ҫ�����ӡ
            if (p1->rent >= l && p1->rent <= r)
            {
                t++;
                printf("%d:\t", t);
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
        //����
        while (mylist_tail->prev != NULL && jug == 2)
        {
            //�����Ҫ�����ӡ
            if (mylist_tail->rent >= l && mylist_tail->rent <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", mylist_tail->number);//�ĳ����
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
    if (jug2 == 2)
    {
        while (p1->next != NULL && jug == 1)
        {
            //�����Ҫ�����ӡ
            if (p1->floor >= l && p1->floor <= r)
            {
                t++;
                printf("%d:\t", t);
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
        //����
        while (mylist_tail->prev != NULL && jug == 2)
        {
            //�����Ҫ�����ӡ
            if (mylist_tail->floor >= l && mylist_tail->floor <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", mylist_tail->number);//�ĳ����
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
        while (p1->next != NULL && jug == 1)
        {
            //�����Ҫ�����ӡ
            if (p1->Area >= l && p1->Area <= r)
            {
                t++;
                printf("%d:\t", t);
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
        //����
        while (mylist_tail->prev != NULL && jug == 2)
        {
            //�����Ҫ�����ӡ
            if (mylist_tail->Area >= l && mylist_tail->Area <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", mylist_tail->number);//�ĳ����
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
    return t;
}
int fl_change(list_1 fl_p1)//���ڸ��ķ�����Ϣ
{
    printf("�ɹ��ҵ�����\n");
    printf("�밴�����/����/���/��/��/����/¥��/���˳��������ĺ����Ϣ\n");
    char number[9] = { '\0' };
    char city[20] = { '\0' };
    float Area;
    int shi;
    int ting;
    int t;
    int floor;
    float rent;
    scanf("%s", number);
    scanf("%s", city);
    scanf("%f %d %d %d %d %f", &Area, &shi, &ting, &t, &floor, &rent);
    strcpy(fl_p1->number, number);
    strcpy(fl_p1->city, city);
    fl_p1->Area = Area;
    fl_p1->shi = shi;
    fl_p1->ting = ting;
    int debug = 0;//�ֻ����������
    do
    {
        if (debug == 1)
        {
            printf("����ȷ���볯�򣡣���\n");
            printf("�����볯��\n");
            scanf("%d", &t);
        }
        switch (t)
        {
        case 1:
            fl_p1->toward = 1;
            debug = 0;
            break;
        case 2:
            fl_p1->toward = 2;
            debug = 0;
            break;
        case 3:
            fl_p1->toward = 3;
            debug = 0;
            break;
        case 4:
            fl_p1->toward = 4;
            debug = 0;
            break;
        case 5:
            fl_p1->toward = 5;
            debug = 0;
            break;
        case 6:
            fl_p1->toward = 6;
            debug = 0;
            break;
        case 7:
            fl_p1->toward = 7;
            debug = 0;
            break;
        case 8:
            fl_p1->toward = 8;
            debug = 0;
            break;
        default:
            debug = 1;
            break;
        }
    } while (debug != 0);
    fl_p1->floor = floor;
    fl_p1->rent = rent;
    fl_p1->agency_fee = fl_p1->rent * 0.01f;//������Ϊ�����İٷ�֮һ
    fl_p1->deposit = fl_p1->rent * 3;//Ѻ��Ϊ���������
    return 0;
}
//�����ӡ
//judge�����ж��������ӡ
int list_printfl(list_1 mylist_head, list_1 mylist_tail,int judge)
{
    int n=0;
    struct Flat*p1;
    if (mylist_head->next == NULL)
    {
        logError(0);
        return -1;
    }
    p1 = mylist_head->next;
    while (p1->next != NULL && judge == 1)
    {
        n++;
        printf("%d:\t",n);
        printf("%s\t", p1->number);//������Ҫ���ĳ����
        printf("%4.2f\t", p1->Area);
        printf("%d��%d��\t", p1->shi, p1->ting);
        printf("%d��\t", p1->floor);
        printf("��%s����\t", p1->city);
        printf("���Ϊ%6.2f\t", p1->rent);
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
        p1 = p1->next;
    }
    while (mylist_tail->prev != NULL && judge== 2)
    {
        n++;
        printf("%d:\t", n);
        printf("%s\t", p1->number);//������Ҫ���ĳ����
        printf("%4.2f\t", p1->Area);
        printf("%d��%d��\t", p1->shi, p1->ting);
        printf("%d��\t", p1->floor);
        printf("��%s����\t", p1->city);
        printf("���Ϊ%6.2f\t", p1->rent);
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
        mylist_tail = mylist_tail->prev;
    }
    return 0;
}
int toward_search(list_1 mylist_head,int i)
{
    int n = 0;
    struct Flat* p1;
    if (mylist_head->next == NULL)
    {
        logError(0);
        return -1;
    }
    p1 = mylist_head->next;
    while (p1->next != NULL )
    {
        //�����Ҫ�����ӡ
        if ((int)p1->toward ==  i)
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