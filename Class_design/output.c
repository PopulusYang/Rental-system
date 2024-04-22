#include "list.h"
#include "temphead.h"



//�����ӡ
//judge�����ж��������ӡ
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
        printf("%s\t", p1->number);//������Ҫ���ĳ����
        printf("%4.2fƽ����\n", p1->Area);
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
    p1 = mylist_tail;
    assert(p1);
    while (p1->prev != NULL && judge == 2)
    {
        n++;
        printf("%d:\t", n);
        assert(p1);
        printf("%s\t", p1->number);//������Ҫ���ĳ����
        printf("%4.2fƽ����\n", p1->Area);
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
            printf("%s\t", p1->number);//������Ҫ���ĳ����
            printf("%4.2fƽ����\n", p1->Area);
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
            printf("%s\t", p1->number);//������Ҫ���ĳ����
            printf("%4.2fƽ����\n", p1->Area);
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
            printf("%s\t", p1->number);//������Ҫ���ĳ����
            printf("%4.2fƽ����\n", p1->Area);
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
            printf("%s\t", p1->number);//������Ҫ���ĳ����
            printf("%4.2fƽ����\n", p1->Area);
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
        }
        p1 = p1->prev;
    }
    return 0;
}
