#define _CRT_SECURE_NO_WARNINGS
#include"temphead.h"
#include"list.h"
#pragma warning(disable:6031) 
typedef struct Flat Flat, * list_1;
//延长Flat链表并写入
int extend_writeFlat(list_1 p1, list_1 head, list_1 tail, char* city, float area, int t, int floor, float rent,int shi,int ting,struct Agency* ag)
{
    p1 = (struct Flat*)malloc(sizeof(struct Flat));
    if (p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;
    }
    int debug = 0;//手滑的特殊情况
    strcpy(p1->city, city);
    p1->Area = area;
    p1->shi = shi;
    p1->ting = ting;
    do
    {
        if (debug == 1)
        {
            printf("请正确输入朝向！！！\n");
            printf("请输入朝向：\n");
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
    p1->agency_fee = p1->rent * 0.01f;//手续费为总租金的百分之一
    p1->deposit = p1->rent * 3;//押金为三个月租金
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
    //数据修改都在上面
    p1->prev = tail;
    tail->next = p1;
    tail = p1;
    tail->next = NULL;

    return 0;
}

//延长Admin链表
int extendAdmin(char* Account, char* key, struct Admin* p1, struct Admin* p2, struct Admin* tail)
{
    p1 = (struct Admin*)malloc(sizeof(struct Admin));
    if (p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;

    }
    strcpy(p1->Account, Account);
    strcpy(p1->Key, key);


    //数据修改都在上面
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//延长链表
    return 0;
}

//延长Agency链表
int extendAgency(char* Account, char* key, struct Agency* p1, struct Agency* head, struct Agency* tail)
{
    p1 = (struct Agency*)malloc(sizeof(struct Agency));
    if (p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;

    }
    strcpy(p1->Account, Account);
    strcpy(p1->Key, key);
    char* temp;
    temp = radom_number(8);//生成编号

    while (checkRecurAG(temp, head))//查重
    {
        free(temp);
        temp = radom_number(8);
    }
    strcpy(p1->Number,temp);//复制
    free(temp);

    //数据修改都在上面
    tail->next = p1;
    p1->prev = tail;
    tail = p1;
    tail->next = NULL;
    return 0;
}


//延长Customer链表
int extendCustomer(char* Account, char* key, struct Customer* p1, struct Customer* p2, struct Customer* tail)
{
    p1 = (struct Customer*)malloc(sizeof(struct Customer));
    if (p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;

    }
    strcpy(p1->Account, Account);
    strcpy(p1->Key, key);
    p1->statment = 1;

    //数据修改都在上面
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//延长链表
    return 0;
}

//延长预约信息
int extendApm(struct Appointment* p, struct Appointment* tail, int year, int month, int day, struct Flat* flat, struct Customer* custom)
{
    p = (struct Appointment*)malloc(sizeof(struct Appointment));
    if (p == NULL)//注意安全
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

int DelListall(list_1 mylist, int t) //t为删除的序号
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
//查找操作，查找一个范围内的房产信息
//l和r为左右端点
//jug为正序or倒序
//jug2判断排什么的顺序
int range_search_Area(int l,int r,Flat* mylist_head,list_1 mylist_tail, int jug,int jug2)//以房产面积为例子
{
    bubbleSort_Area(&mylist_head,jug2);
    struct Flat* p1;
    int t = 0;
    //正序
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
            //这块需要加入打印
            if (p1->rent >= l && p1->rent <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", p1->number);//这里需要更改成序号
                printf("%4.2f\t", p1->Area);
                printf("%d室%d厅\t", p1->shi, p1->ting);
                printf("朝向为");
                switch ((int)p1->toward)
                {
                case 1:
                    printf("东\n");
                    break;
                case 2:
                    printf("西\n");
                    break;
                case 3:
                    printf("南\n");
                    break;
                case 4:
                    printf("北\n");
                    break;
                case 5:
                    printf("东南\n");
                    break;
                case 6:
                    printf("东北\n");
                    break;
                case 7:
                    printf("西南\n");
                    break;
                case 8:
                    printf("西北\n");
                    break;

                }
            }
            p1 = p1->next;
        }
        //倒序
        while (mylist_tail->prev != NULL && jug == 2)
        {
            //这块需要加入打印
            if (mylist_tail->rent >= l && mylist_tail->rent <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", mylist_tail->number);//改成序号
                printf("%4.2f\t", mylist_tail->Area);
                printf("%d室%d厅\t", mylist_tail->shi, mylist_tail->ting);
                printf("朝向为");
                switch ((int)mylist_tail->toward)
                {
                case 1:
                    printf("东\n");
                    break;
                case 2:
                    printf("西\n");
                    break;
                case 3:
                    printf("南\n");
                    break;
                case 4:
                    printf("北\n");
                    break;
                case 5:
                    printf("东南\n");
                    break;
                case 6:
                    printf("东北\n");
                    break;
                case 7:
                    printf("西南\n");
                    break;
                case 8:
                    printf("西北\n");
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
            //这块需要加入打印
            if (p1->floor >= l && p1->floor <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", p1->number);//这里需要更改成序号
                printf("%4.2f\t", p1->Area);
                printf("%d室%d厅\t", p1->shi, p1->ting);
                printf("朝向为");
                switch ((int)p1->toward)
                {
                case 1:
                    printf("东\n");
                    break;
                case 2:
                    printf("西\n");
                    break;
                case 3:
                    printf("南\n");
                    break;
                case 4:
                    printf("北\n");
                    break;
                case 5:
                    printf("东南\n");
                    break;
                case 6:
                    printf("东北\n");
                    break;
                case 7:
                    printf("西南\n");
                    break;
                case 8:
                    printf("西北\n");
                    break;

                }
            }
            p1 = p1->next;
        }
        //倒序
        while (mylist_tail->prev != NULL && jug == 2)
        {
            //这块需要加入打印
            if (mylist_tail->floor >= l && mylist_tail->floor <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", mylist_tail->number);//改成序号
                printf("%4.2f\t", mylist_tail->Area);
                printf("%d室%d厅\t", mylist_tail->shi, mylist_tail->ting);
                printf("朝向为");
                switch ((int)mylist_tail->toward)
                {
                case 1:
                    printf("东\n");
                    break;
                case 2:
                    printf("西\n");
                    break;
                case 3:
                    printf("南\n");
                    break;
                case 4:
                    printf("北\n");
                    break;
                case 5:
                    printf("东南\n");
                    break;
                case 6:
                    printf("东北\n");
                    break;
                case 7:
                    printf("西南\n");
                    break;
                case 8:
                    printf("西北\n");
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
            //这块需要加入打印
            if (p1->Area >= l && p1->Area <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", p1->number);//这里需要更改成序号
                printf("%4.2f\t", p1->Area);
                printf("%d室%d厅\t", p1->shi, p1->ting);
                printf("朝向为");
                switch ((int)p1->toward)
                {
                case 1:
                    printf("东\n");
                    break;
                case 2:
                    printf("西\n");
                    break;
                case 3:
                    printf("南\n");
                    break;
                case 4:
                    printf("北\n");
                    break;
                case 5:
                    printf("东南\n");
                    break;
                case 6:
                    printf("东北\n");
                    break;
                case 7:
                    printf("西南\n");
                    break;
                case 8:
                    printf("西北\n");
                    break;

                }
            }
            p1 = p1->next;
        }
        //倒序
        while (mylist_tail->prev != NULL && jug == 2)
        {
            //这块需要加入打印
            if (mylist_tail->Area >= l && mylist_tail->Area <= r)
            {
                t++;
                printf("%d:\t", t);
                printf("%s\t", mylist_tail->number);//改成序号
                printf("%4.2f\t", mylist_tail->Area);
                printf("%d室%d厅\t", mylist_tail->shi, mylist_tail->ting);
                printf("朝向为");
                switch ((int)mylist_tail->toward)
                {
                case 1:
                    printf("东\n");
                    break;
                case 2:
                    printf("西\n");
                    break;
                case 3:
                    printf("南\n");
                    break;
                case 4:
                    printf("北\n");
                    break;
                case 5:
                    printf("东南\n");
                    break;
                case 6:
                    printf("东北\n");
                    break;
                case 7:
                    printf("西南\n");
                    break;
                case 8:
                    printf("西北\n");
                    break;

                }
            }
            mylist_tail = mylist_tail->prev;
        }
    }
    return t;
}
int fl_change(list_1 fl_p1)//用于更改房子信息
{
    printf("成功找到对象\n");
    printf("请按照序号/城市/面积/室/厅/朝向/楼层/租金顺序输入更改后的信息\n");
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
    int debug = 0;//手滑的特殊情况
    do
    {
        if (debug == 1)
        {
            printf("请正确输入朝向！！！\n");
            printf("请输入朝向：\n");
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
    fl_p1->agency_fee = fl_p1->rent * 0.01f;//手续费为总租金的百分之一
    fl_p1->deposit = fl_p1->rent * 3;//押金为三个月租金、
    return 0;
}
//链表打印
//judge用于判断正反向打印
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
        printf("%s\t", p1->number);//这里需要更改成序号
        printf("%4.2f\t", p1->Area);
        printf("%d室%d厅\t", p1->shi, p1->ting);
        printf("%d层\t", p1->floor);
        printf("在%s城市\t", p1->city);
        printf("租金为%6.2f\t", p1->rent);
        printf("朝向为");
        switch ((int)p1->toward)
        {
        case 1:
            printf("东\n");
            break;
        case 2:
            printf("西\n");
            break;
        case 3:
            printf("南\n");
            break;
        case 4:
            printf("北\n");
            break;
        case 5:
            printf("东南\n");
            break;
        case 6:
            printf("东北\n");
            break;
        case 7:
            printf("西南\n");
            break;
        case 8:
            printf("西北\n");
            break;
        }
        p1 = p1->next;
    }
    while (mylist_tail->prev != NULL && judge== 2)
    {
        n++;
        printf("%d:\t", n);
        printf("%s\t", p1->number);//这里需要更改成序号
        printf("%4.2f\t", p1->Area);
        printf("%d室%d厅\t", p1->shi, p1->ting);
        printf("%d层\t", p1->floor);
        printf("在%s城市\t", p1->city);
        printf("租金为%6.2f\t", p1->rent);
        printf("朝向为");
            switch ((int)mylist_tail->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("西\n");
                break;
            case 3:
                printf("南\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
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
        //这块需要加入打印
        if ((int)p1->toward ==  i)
        {
            n++;
            printf("%d:\t", n);
            printf("%s\t", p1->number);//这里需要更改成序号
            printf("%4.2f\t", p1->Area);
            printf("%d室%d厅\t", p1->shi, p1->ting);
            printf("朝向为");
            switch ((int)p1->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("西\n");
                break;
            case 3:
                printf("南\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
        }
        p1 = p1->next;
    }
    return n;
}