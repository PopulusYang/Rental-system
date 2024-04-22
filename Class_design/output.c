#include "list.h"
#include "temphead.h"



//链表打印
//judge用于判断正反向打印
int list_printfl(list_1 mylist_head, list_1 mylist_tail, int judge)
{
    int n = 0;
    struct Flat* p1;
    if (mylist_head->next == NULL)
    {
        logError(0);
        return -1;
    }
    p1 = mylist_head->next;
    while (p1 != NULL && judge == 1)
    {
        n++;
        printf("%d:\t", n);
        printf("%s\t", p1->number);//这里需要更改成序号
        printf("%4.2f平方米\n", p1->Area);
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
            printf("南\n");
            break;
        case 3:
            printf("西\n");
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
    p1 = mylist_tail;
    assert(p1);
    while (p1->prev != NULL && judge == 2)
    {
        n++;
        printf("%d:\t", n);
        assert(p1);
        printf("%s\t", p1->number);//这里需要更改成序号
        printf("%4.2f平方米\n", p1->Area);
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
        p1 = p1->prev;
    }
    return 0;
}

int list_printfl_ag(list_1 mylist_head, list_1 mylist_tail, int judge)
{
    int n = 0;
    struct Flat* p1;
    if (mylist_head->next == NULL)
    {
        logError(0);
        return -1;
    }
    p1 = mylist_head->next;
    while (p1 != NULL && judge == 1)
    {
        if (p1->agency == NULL)
        {
            n++;
            printf("%d:\t", n);
            printf("%s\t", p1->number);//这里需要更改成序号
            printf("%4.2f平方米\n", p1->Area);
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
                printf("南\n");
                break;
            case 3:
                printf("西\n");
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
    p1 = mylist_tail;
    assert(p1);
    while (p1->prev != NULL && judge == 2)
    {
        if (p1->agency == NULL)
        {
            n++;
            printf("%d:\t", n);
            assert(p1);
            printf("%s\t", p1->number);//这里需要更改成序号
            printf("%4.2f平方米\n", p1->Area);
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
                printf("南\n");
                break;
            case 3:
                printf("西\n");
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
        p1 = p1->prev;
    }
    return 0;
}
int list_printfl_cu(list_1 mylist_head, list_1 mylist_tail, int judge)
{
    int n = 0;
    struct Flat* p1;
    if (mylist_head->next == NULL)
    {
        logError(0);
        return -1;
    }
    p1 = mylist_head->next;
    while (p1 != NULL && judge == 1)
    {
        if (p1->agency != NULL)
        {
            n++;
            printf("%d:\t", n);
            printf("%s\t", p1->number);//这里需要更改成序号
            printf("%4.2f平方米\n", p1->Area);
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
                printf("南\n");
                break;
            case 3:
                printf("西\n");
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
    p1 = mylist_tail;
    assert(p1);
    while (p1->prev != NULL && judge == 2)
    {
        if (p1->agency != NULL)
        {
            n++;
            printf("%d:\t", n);
            assert(p1);
            printf("%s\t", p1->number);//这里需要更改成序号
            printf("%4.2f平方米\n", p1->Area);
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
                printf("南\n");
                break;
            case 3:
                printf("西\n");
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
        p1 = p1->prev;
    }
    return 0;
}
