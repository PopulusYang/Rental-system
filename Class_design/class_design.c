#define _CRT_SECURE_NO_WARNINGS
#include"temphead.h"
#include"list.h"
#pragma warning(disable:6031) 
typedef struct Flat Flat, * list_1;



int main()
{
    struct Admin* ad_p1, * ad_p2, * ad_tail, * ad_head;//构建链表
    ad_p1 = (struct Admin*)malloc(sizeof(struct Admin));//申请空间
    if (ad_p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;

    }
    ad_tail = ad_p1;//标记头尾
    ad_head = ad_p1;
    ad_p2 = ad_p1;
    ad_tail->next = NULL;
    ad_head->prev = NULL;


    struct Agency* ag_p1, * ag_p2, * ag_tail, * ag_head;//构建链表
    ag_p1 = (struct Agency*)malloc(sizeof(struct Agency));//申请空间
    if (ag_p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;

    }
    ag_tail = ag_p1;//标记头尾
    ag_head = ag_p1;
    ag_p2 = ag_p1;
    ag_tail->next = NULL;
    ag_head->prev = NULL;


    struct Customer* cu_p1, * cu_p2, * cu_tail, * cu_head;//构建链表
    cu_p1 = (struct Customer*)malloc(sizeof(struct Customer));//申请空间
    if (cu_p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;
    }
    cu_tail = cu_p1;//标记头尾
    cu_head = cu_p1;
    cu_p2 = cu_p1;
    cu_tail->next = NULL;
    cu_head->prev = NULL;



    struct Flat* fl_p1, * fl_p2, * fl_tail, * fl_head;//构建链表
    fl_p1 = (struct Flat*)malloc(sizeof(struct Flat));//申请空间
    if (fl_p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        logError(0);
        return -1;
    }
    fl_tail = fl_p1;//标记头尾
    fl_head = fl_p1;
    fl_p2 = fl_p1;
    fl_tail->next = NULL;
    fl_head->prev = NULL;

    struct Appointment* ap_p, * ap_tail, * ap_head,* ap_p2;//构建预约信息链表
    ap_p2 = NULL;
    ap_p = (struct Appointment*)malloc(sizeof(struct Appointment));
    if (ap_p == NULL)//注意安全摸摸哒
    {
        logError(0);
        return -1;
    }
    ap_tail = ap_p;//标记头尾
    ap_head = ap_p;
    ap_tail->next = NULL;
    //数据读取
    filecachAD_read(&ad_tail);
    filecachAG_read(&ag_tail);
    filecachCU_read(&cu_tail);
    filecachFL_read(&fl_tail,ag_head);
    filecachAP_read(&ap_tail,cu_head,fl_head);

    void choose();
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;
    //0:登录界面 1：身份主菜单 2：管理员主菜单 3：中介主菜单 4：租客主菜单
    int choice_5;//选择排序方式用
    int choice_6;//选择具体查询内容
    int jug = 0;//身份验证用//字符串查找用
    int jug2 = 1, jug3 = 1;//注册用
    int jug4 = 1;//让ad_p1->effective只执行一次
    int jug5 = 0;//搜索用
    int jug6 = 0;//选择用
    int jug7 = 0;//选择正反排序用
    int jug8 = 1;//功能管理下级
    int jug9 = 1;//信息管理中下级

    char input_string[50] = { '\0' };
    char input_account[20] = { '\0' };
    char input_key[20] = { '\0' };
    char input_key_2[20] = { '\0' };
    char* build_invitation;
    build_invitation = NULL;
    char input_invitation[20] = { '\0' };
    char input_phonenumber[12] = { '\0' };
    int* tempIntPtr;
    tempIntPtr = NULL;
    int fl_number = 0;
    fl_number=countNumberFL(fl_head);


    int year = 0, month = 0, day = 0;
    //清理过期的预约
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    ap_p = ap_head->next;
    while (ap_p != NULL)
    {
        if (ap_p->year < local->tm_year || (ap_p->year == local->tm_year && ap_p->month < local->tm_mon) || (ap_p->year == local->tm_year && ap_p->month == local->tm_mon && ap_p->day < local->tm_mday))
        {
            ap_p2 = ap_p;
            ap_p = ap_p->prev;
            if (ap_p2->next == NULL)
            {
                ap_p2->prev->next = NULL;
                free(ap_p2);
            }
            else
            {
                ap_p2->next->prev = ap_p2->prev;
                ap_p2->prev->next = ap_p2->next;
                free(ap_p2);
            }
            ap_p2 = NULL;
        }
        ap_p = ap_p->next;
    }


    loading();
    printf("数据加载完成，按下回车以继续");
    choose();
    while (choice_0)
    {
        printf("******登    录******\n");
        printf("**                **\n");
        printf("**0.  关    闭    **\n");
        printf("**1.  登    录    **\n");
        printf("**2.  注    册    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("请选择功能：");
        scanf_s("%d", &choice_0);
        choose();
        switch (choice_0)
        {
        case 0:
            break;
        case 1:
            printf("******身份选择******\n");
            printf("**                **\n");
            printf("**0.  退    出    **\n");
            printf("**1.  管 理 员    **\n");
            printf("**2.  中    介    **\n");
            printf("**3.  租    客    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("请选择身份：");
            scanf_s("%d", &choice_1);
            choose();


            //调用函数
            switch (choice_1)
            {
            case 0:
                break;
            case 1://管理员
                printf("请输入账户（account）：");
                scanf("%s", input_account);
                ad_p1 = ad_head->next;
                if (ad_p1 == NULL)
                {
                    logError(0);
                    return -1;
                }
                while (1)
                {
                    if (!strcmp(input_account, ad_p1->Account))
                    {
                        printf("请输入密码（key）:");
                        scanf("%s", input_key);
                        if (!strcmp(input_key, ad_p1->Key))
                        {
                            printf("登录成功，欢迎，管理员%s\n", ad_p1->Account);
                            printf("回车以继续\n");
                            getchar();
                            jug = 1;
                            choose();
                        }
                        else
                        {
                            printf("密码错误\n");
                            printf("回车以继续\n");
                            getchar();
                            jug = 0;
                            choose();
                        }
                        break;
                    }
                    ad_p1 = ad_p1->next;
                    if (ad_p1 == NULL)
                    {
                        printf("找不到对象\n");
                        printf("回车以继续\n");
                        getchar();
                        jug = 0;
                        choose();
                        break;
                    }
                }
                while (jug && ad_p1 != NULL)
                {
                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     注    销       **\n");
                    printf("**1.     信息管理       **\n");//完工
                    printf("**2.     看房管理       **\n");//未士兑已完工
                    printf("**3.     信息查询       **\n");//完工
                    printf("**4.     信息排序       **\n");//未士兑施工中
                    printf("**5.     信息统计       **\n");//施工中
                    printf("**6.     更改密码       **\n");//完工
                    printf("**7.    生成邀请码      **\n");//完工
                    printf("**8.     删除账户       **\n");//完工
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("请选择功能：");
                    scanf_s("%d", &choice_2);
                    choose();

                    switch (choice_2)
                    {
                    case 0:
                        jug = 0;
                        ad_p1 = ad_tail;
                        break;
                    case 1:
                        //已完成
                        while (jug8)
                        {
                            printf("*********信息管理*********\n");
                            printf("**                      **\n");
                            printf("**0.     返    回       **\n");
                            printf("**1.     人员管理       **\n");
                            printf("**2.     房源管理       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            printf("请选择功能：");
                            scanf_s("%d", &choice_2);
                            choose();
                            switch (choice_2)
                            {
                            case 0:
                                jug8 = 0;
                                break;
                            case 1://人员管理
                                //完工
                                while (jug9)
                                {
                                    printf("*********人员管理*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     返    回       **\n");
                                    printf("**1.     员工管理       **\n");
                                    printf("**2.   租客信息管理     **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("请选择功能：");
                                    scanf_s("%d", &choice_2);
                                    choose();
                                    switch (choice_2)
                                    {
                                    case 0:
                                        jug9 = 0;
                                        break;
                                    case 1:
                                        //完工
                                        printf("*********员工管理*********\n");
                                        printf("**                      **\n");
                                        printf("**0.     返    回       **\n");
                                        printf("**1.     信息修改       **\n");
                                        printf("**2.     删除员工       **\n");
                                        printf("**3.     增加员工       **\n");
                                        printf("**                      **\n");
                                        printf("**************************\n");
                                        printf("请选择功能：");
                                        scanf_s("%d", &choice_2);
                                        choose();
                                        switch (choice_2)
                                        {
                                        case 0:
                                            break;
                                        case 1:
                                            //完工
                                            //搜索
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("请输入员工信息（最多50个字符）：");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("很凄惨，我们的应用没有人在用。\n");
                                                printf("回车以继续\n");
                                                getchar();
                                                choose();
                                                break;
                                            }
                                            tempIntPtr++;
                                            for (int i = 0; i != *(tempIntPtr - 1); i++)
                                            {
                                                ag_p1 = ag_head->next;
                                                for (int j = 0; j != tempIntPtr[i]; j++)
                                                    ag_p1 = ag_p1->next;
                                                if (!strcmp(ag_p1->Number, input_string) || !strcmp(ag_p1->Name, input_string) || !strcmp(ag_p1->Account, input_string) || !strcmp(ag_p1->phone_n, input_string))
                                                {
                                                    jug5 = 1;
                                                    break;
                                                }
                                            }
                                            if (jug5)
                                            {
                                                choose(0);
                                                printf("成功找到对象\n");
                                                printf("编号\t\t姓名\t\t账号\t\t电话\n");
                                                printf("%s\t%s\t\t%s\t\t%s\n", ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                printf("*********信息修改*********\n");
                                                printf("**                      **\n");
                                                printf("**0.     返    回       **\n");
                                                printf("**1.     重置密码       **\n");
                                                printf("**2.     修改姓名       **\n");
                                                printf("**3.     修改电话       **\n");
                                                printf("**                      **\n");
                                                printf("**************************\n");
                                                printf("请选择功能：");
                                                scanf_s("%d", &choice_2);
                                                choose();
                                                switch (choice_2)
                                                {
                                                case 0:
                                                    break;
                                                case 1:
                                                    while (1)
                                                    {
                                                        memset(input_key, 0, sizeof(input_key));
                                                        memset(input_key_2, 0, sizeof(input_key_2));
                                                        printf("请输入密码：");
                                                        scanf("%s", input_key);
                                                        printf("请确认密码：");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            strcpy(ag_p1->Key, input_key);
                                                            printf("修改成功!\n");
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("两次输入不一样的嘞\n");
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("请输入新的姓名:");
                                                    scanf("%s", input_string);
                                                    strcpy(ag_p1->Name, input_string);
                                                    printf("修改成功！\n");
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                case 3:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("请输入新的电话号码:");
                                                    scanf("%s", input_string);
                                                    while (strlen(input_string) != 11)
                                                    {
                                                        choose();
                                                        printf("无效的电话号码！\n");
                                                        printf("请输入正确的的电话号码:");
                                                        memset(input_string, 0, sizeof(input_string));
                                                        scanf("%s", input_string);
                                                    }
                                                    strcpy(ag_p1->phone_n, input_string);
                                                    printf("修改成功！\n");
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                }
                                                jug5 = 0;//初始化
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("找不到您输入的内容。\n");
                                                    printf("按下回车以继续");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("您输入的内容比较模糊，为您找到以下内容\n");
                                                    printf("序号\t\t编号\t\t姓名\t\t账号\t\t电话\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        ag_p1 = ag_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            ag_p1 = ag_p1->next;
                                                        printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", i + 1, ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                    }
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 2:
                                            //完工
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("请输入员工信息（最多50个字符）：");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("很凄惨，我们的应用没有人在用。\n");
                                                printf("回车以继续\n");
                                                getchar();
                                                choose();
                                                break;
                                            }
                                            tempIntPtr++;
                                            for (int i = 0; i != *(tempIntPtr - 1); i++)
                                            {
                                                ag_p1 = ag_head->next;
                                                for (int j = 0; j != tempIntPtr[i]; j++)
                                                    ag_p1 = ag_p1->next;
                                                if (!strcmp(ag_p1->Number, input_string) || !strcmp(ag_p1->Name, input_string) || !strcmp(ag_p1->Account, input_string) || !strcmp(ag_p1->phone_n, input_string))
                                                {
                                                    jug5 = 1;
                                                    break;
                                                }
                                            }
                                            if (jug5)
                                            {
                                                choose();
                                                printf("成功找到对象\n");
                                                printf("编号\t\t姓名\t\t账号\t\t电话\n");
                                                printf("%s\t%s\t\t%s\t\t%s\n", ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                printf("您确定要删除该员工吗？\n1确认\t 2取消：\n");
                                                printf("您的选择：");
                                                scanf("%d", &jug6);
                                                if (jug6 == 1)
                                                {
                                                    if (ag_p1->next == NULL)
                                                    {
                                                        ag_tail = ag_p1->prev;
                                                        ag_p1->prev->next = NULL;
                                                        free(ag_p1);
                                                    }
                                                    else
                                                    {
                                                        ag_p1->prev->next = ag_p1->next;
                                                        ag_p1->next->prev = ag_p1->prev;
                                                        free(ag_p1);
                                                    }
                                                    ag_p1 = NULL;
                                                }
                                                jug6 = 0;
                                                jug5 = 0;//初始化
                                                printf("删除成功！\n");
                                                printf("回车以继续\n");
                                                getchar();
                                                choose();
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("找不到您输入的内容。\n");
                                                    printf("按下回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("您输入的内容比较模糊，为您找到以下内容\n");
                                                    printf("序号\t\t编号\t\t姓名\t\t账号\t\t电话\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        ag_p1 = ag_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            ag_p1 = ag_p1->next;
                                                        printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", i + 1, ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                    }
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 3:
                                            //完工
                                            while (jug2)
                                            {
                                                memset(input_account, 0, sizeof(input_account));
                                                memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                printf("请输入电话号码：(11位)");
                                                scanf("%s", input_phonenumber);
                                                while (strlen(input_phonenumber) != 11)
                                                {
                                                    choose();
                                                    printf("无效的电话号码！\n");
                                                    printf("请输入正确的的电话号码:");
                                                    memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                    scanf("%s", input_phonenumber);
                                                }
                                                printf("请输入账户：（20个字符）");
                                                scanf("%s", input_account);
                                                ag_p1 = ag_head->next;
                                                while (1)
                                                {
                                                    if (ag_p1 == NULL)
                                                    {
                                                        printf("请输入密码：");
                                                        scanf("%s", input_key);
                                                        printf("请确认密码：");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            extendAgency(input_account, input_key, ag_p1, ag_head, ag_tail);
                                                            ag_tail = ag_tail->next;
                                                            ag_p1 = ag_tail;
                                                            strcpy(ag_p1->phone_n, input_phonenumber);
                                                            printf("注册成功！\n");
                                                            printf("该用户的编号为%s\n", ag_p1->Number);
                                                            printf("请输入用户的姓名：");
                                                            scanf("%s", ag_p1->Name);
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                            jug2 = 0;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("两次输入不一样的嘞");
                                                            printf("回车以继续");
                                                            getchar();
                                                            choose();
                                                            ag_p1 = ag_head->next;
                                                            break;
                                                        }
                                                    }
                                                    if (!strcmp(input_account, ag_p1->Account) || !strcmp(input_phonenumber, ag_p1->phone_n))
                                                    {
                                                        ag_p1 = ag_head->next;
                                                        printf("该用户已经存在\n");
                                                        printf("按回车以继续\n");
                                                        getchar();
                                                        choose();
                                                        break;
                                                    }
                                                    ag_p1 = ag_p1->next;

                                                }
                                            }
                                            jug2 = 1;
                                            break;
                                        }
                                        break;
                                    case 2:
                                        //完工
                                        printf("*******租客信息管理*******\n");
                                        printf("**                      **\n");
                                        printf("**0.     返    回       **\n");
                                        printf("**1.     信息修改       **\n");
                                        printf("**2.     删除账户       **\n");
                                        printf("**3.     增加账户       **\n");
                                        printf("**4.   封禁信息管理     **\n");
                                        printf("**                      **\n");
                                        printf("**************************\n");
                                        printf("请选择功能：");
                                        scanf_s("%d", &choice_2);
                                        choose();
                                        switch (choice_2)
                                        {
                                        case 0:
                                            choice_2 = 1;
                                            break;
                                        case 1:
                                            //完工
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("请输入用户信息（最多50个字符）：");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("很凄惨，我们的应用没有人在用。");
                                                printf("回车以继续");
                                                getchar();
                                                choose();
                                                break;
                                            }
                                            tempIntPtr++;
                                            for (int i = 0; i != *(tempIntPtr - 1); i++)
                                            {
                                                cu_p1 = cu_head->next;
                                                for (int j = 0; j != tempIntPtr[i]; j++)
                                                    cu_p1 = cu_p1->next;
                                                if (!strcmp(cu_p1->Name, input_string) || !strcmp(cu_p1->Account, input_string) || !strcmp(cu_p1->phone_n, input_string))
                                                {
                                                    jug5 = 1;
                                                    break;
                                                }
                                            }
                                            if (jug5)
                                            {
                                                choose(0);
                                                printf("成功找到对象\n");
                                                printf("姓名\t\t账号\t\t电话\n");
                                                printf("%s\t\t%s\t\t%s\n", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                printf("*********信息修改*********\n");
                                                printf("**                      **\n");
                                                printf("**0.     返    回       **\n");
                                                printf("**1.     重置密码       **\n");
                                                printf("**2.     修改姓名       **\n");
                                                printf("**3.     修改电话       **\n");
                                                printf("**                      **\n");
                                                printf("**************************\n");
                                                printf("请选择功能：");
                                                scanf_s("%d", &choice_2);
                                                choose();
                                                switch (choice_2)
                                                {
                                                case 0:
                                                    choice_2 = 1;
                                                    break;
                                                case 1:
                                                    while (1)
                                                    {
                                                        memset(input_key, 0, sizeof(input_key));
                                                        memset(input_key_2, 0, sizeof(input_key_2));
                                                        printf("请输入密码：");
                                                        scanf("%s", input_key);
                                                        printf("请确认密码：");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            strcpy(cu_p1->Key, input_key);
                                                            printf("修改成功!\n");
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("两次输入不一样的嘞");
                                                            printf("回车以继续");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("请输入新的姓名:");
                                                    scanf("%s", input_string);
                                                    strcpy(cu_p1->Name, input_string);
                                                    printf("修改成功！\n");
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                case 3:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("请输入新的电话号码:");
                                                    scanf("%s", input_string);
                                                    while (strlen(input_string) != 11)
                                                    {
                                                        choose();
                                                        printf("无效的电话号码！\n");
                                                        printf("请输入正确的的电话号码:");
                                                        memset(input_string, 0, sizeof(input_string));
                                                        scanf("%s", input_string);
                                                    }
                                                    strcpy(cu_p1->phone_n, input_string);
                                                    printf("修改成功！\n");
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                }
                                                jug5 = 0;//初始化
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("找不到您输入的内容。\n");
                                                    printf("按下回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("您输入的内容比较模糊，为您找到以下内容\n");
                                                    printf("序号\t\t姓名\t\t账号\t\t电话\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        cu_p1 = cu_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            cu_p1 = cu_p1->next;
                                                        printf("%d\t\t%s\t\t%s\t\t%s\n", i + 1, cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    }
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 2:
                                            //完工
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("请输入用户信息（最多50个字符）：");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("很凄惨，我们的应用没有人在用。");
                                                printf("回车以继续");
                                                getchar();
                                                choose();
                                                break;
                                            }
                                            tempIntPtr++;
                                            for (int i = 0; i != *(tempIntPtr - 1); i++)
                                            {
                                                cu_p1 = cu_head->next;
                                                for (int j = 0; j != tempIntPtr[i]; j++)
                                                    cu_p1 = cu_p1->next;
                                                if (!strcmp(cu_p1->Name, input_string) || !strcmp(cu_p1->Account, input_string) || !strcmp(cu_p1->phone_n, input_string))
                                                {
                                                    jug5 = 1;
                                                    break;
                                                }
                                            }
                                            if (jug5)
                                            {
                                                choose(0);
                                                printf("成功找到对象\n");
                                                printf("姓名\t\t账号\t\t电话\n");
                                                printf("%s\t\t%s\t\t%s\n", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                printf("您确定要删除该用户吗？1确认 2取消：");
                                                scanf("%d", &jug6);
                                                if (jug6 == 1)
                                                {
                                                    if (cu_p1->next == NULL)
                                                    {
                                                        cu_tail = cu_p1->prev;
                                                        cu_p1->prev->next = NULL;
                                                        free(cu_p1);
                                                    }
                                                    else
                                                    {
                                                        cu_p1->prev->next = cu_p1->next;
                                                        cu_p1->next->prev = cu_p1->prev;
                                                        free(cu_p1);
                                                    }
                                                    cu_p1 = NULL;
                                                }
                                                jug6 = 0;
                                                jug5 = 0;//初始化
                                                printf("删除成功！\n");
                                                printf("回车以继续\n");
                                                getchar();
                                                choose();
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("找不到您输入的内容。\n");
                                                    printf("按下回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("您输入的内容比较模糊，为您找到以下内容\n");
                                                    printf("序号\t\t姓名\t\t账号\t\t电话\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        cu_p1 = cu_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            cu_p1 = cu_p1->next;
                                                        printf("%d\t\t%s\t\t%s\t\t%s\n", i + 1, cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    }
                                                    printf("回车以继续\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 3:
                                            //完工
                                            while (jug2)
                                            {
                                                memset(input_account, 0, sizeof(input_account));
                                                memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                printf("请输入电话号码：(11位)");
                                                scanf("%s", input_phonenumber);
                                                while (strlen(input_phonenumber) != 11)
                                                {
                                                    choose();
                                                    printf("无效的电话号码！\n");
                                                    printf("请输入正确的的电话号码:");
                                                    memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                    scanf("%s", input_phonenumber);
                                                }
                                                printf("请输入账户：（20个字符）");
                                                scanf("%s", input_account);
                                                cu_p1 = cu_head->next;
                                                while (1)
                                                {
                                                    if (cu_p1 == NULL)
                                                    {
                                                        printf("请输入密码：");
                                                        scanf("%s", input_key);
                                                        printf("请确认密码：");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            extendCustomer(input_account, input_key, cu_p1, cu_p2, cu_tail);
                                                            cu_tail = cu_tail->next;
                                                            cu_p1 = cu_tail;
                                                            strcpy(cu_p1->phone_n, input_phonenumber);
                                                            printf("注册成功！\n");
                                                            printf("请输入用户的姓名：");
                                                            scanf("%s", cu_p1->Name);
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                            jug2 = 0;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("两次输入不一样的嘞");
                                                            printf("回车以继续");
                                                            getchar();
                                                            choose();
                                                            cu_p1 = cu_head->next;
                                                            break;
                                                        }
                                                    }
                                                    if (!strcmp(input_account, cu_p1->Account) || !strcmp(input_phonenumber, cu_p1->phone_n))
                                                    {
                                                        cu_p1 = cu_head->next;
                                                        printf("该用户已经存在\n");
                                                        printf("按回车以继续\n");
                                                        getchar();
                                                        choose();
                                                        break;
                                                    }
                                                    cu_p1 = cu_p1->next;
                                                }
                                            }
                                            jug2 = 1;
                                            break;
                                        case 4:
                                            //完工
                                            printf("*******封禁信息管理*******\n");
                                            printf("**                      **\n");
                                            printf("**0.     返    回       **\n");
                                            printf("**1.     封禁账户       **\n");
                                            printf("**2.     解封账户       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            printf("请选择功能：");
                                            scanf_s("%d", &choice_2);
                                            choose();
                                            switch (choice_2)
                                            {
                                            case 0:
                                                choice_2 = 1;
                                                break;
                                            case 1:
                                                //完工
                                                memset(input_string, 0, sizeof(input_string));
                                                printf("请输入用户信息（最多50个字符）：");
                                                scanf("%s", input_string);
                                                tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                                if (*tempIntPtr == 0)
                                                {
                                                    printf("很凄惨，我们的应用没有人在用。");
                                                    printf("回车以继续");
                                                    getchar();
                                                    choose();
                                                    break;
                                                }
                                                tempIntPtr++;
                                                for (int i = 0; i != *(tempIntPtr - 1); i++)
                                                {
                                                    cu_p1 = cu_head->next;
                                                    for (int j = 0; j != tempIntPtr[i]; j++)
                                                        cu_p1 = cu_p1->next;
                                                    if (!strcmp(cu_p1->Name, input_string) || !strcmp(cu_p1->Account, input_string) || !strcmp(cu_p1->phone_n, input_string))
                                                    {
                                                        jug5 = 1;
                                                        break;
                                                    }
                                                }
                                                if (jug5)
                                                {
                                                    choose();
                                                    printf("成功找到对象\n");
                                                    printf("姓名\t\t账号\t\t电话\t\t状态\n");
                                                    printf("%s\t\t%s\t\t%s\t\t", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    switch (cu_p1->statment)
                                                    {
                                                    case 1:
                                                        printf("正常\n");
                                                        break;
                                                    case 0:
                                                        printf("封禁\n");
                                                    }
                                                    if (cu_p1->statment == 0)
                                                    {
                                                        printf("该用户已被封禁");
                                                        printf("回车以继续\n");
                                                        getchar();
                                                        choose();
                                                    }
                                                    if (cu_p1->statment == 1)
                                                    {
                                                        printf("您确定要封禁该用户吗？1确认 2取消：");
                                                        scanf("%d", &jug6);
                                                        if (jug6 == 1)
                                                        {
                                                            cu_p1->statment = 0;
                                                            printf("操作成功！\n");
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                        }
                                                    }
                                                }
                                                break;
                                            case 2:
                                                //完工
                                                memset(input_string, 0, sizeof(input_string));
                                                printf("请输入用户信息（最多50个字符）：");
                                                scanf("%s", input_string);
                                                tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                                if (*tempIntPtr == 0)
                                                {
                                                    printf("很凄惨，我们的应用没有人在用。");
                                                    printf("回车以继续");
                                                    getchar();
                                                    choose();
                                                    break;
                                                }
                                                tempIntPtr++;
                                                for (int i = 0; i != *(tempIntPtr - 1); i++)
                                                {
                                                    cu_p1 = cu_head->next;
                                                    for (int j = 0; j != tempIntPtr[i]; j++)
                                                        cu_p1 = cu_p1->next;
                                                    if (!strcmp(cu_p1->Name, input_string) || !strcmp(cu_p1->Account, input_string) || !strcmp(cu_p1->phone_n, input_string))
                                                    {
                                                        jug5 = 1;
                                                        break;
                                                    }
                                                }
                                                if (jug5)
                                                {
                                                    choose(0);
                                                    printf("成功找到对象\n");
                                                    printf("姓名\t\t账号\t\t电话\t\t状态\n");
                                                    printf("%s\t\t%s\t\t%s\t\t", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    switch (cu_p1->statment)
                                                    {
                                                    case 1:
                                                        printf("正常\n");
                                                        break;
                                                    case 0:
                                                        printf("封禁\n");
                                                    }
                                                    if (cu_p1->statment == 0)
                                                    {
                                                        printf("该用户状态正常");
                                                        printf("回车以继续\n");
                                                        getchar();
                                                        choose();
                                                    }
                                                    if (cu_p1->statment == 1)
                                                    {
                                                        printf("您确定要解封该用户吗？1确认 2取消：");
                                                        scanf("%d", &jug6);
                                                        if (jug6 == 1)
                                                        {
                                                            cu_p1->statment = 1;
                                                            printf("操作成功！\n");
                                                            printf("回车以继续\n");
                                                            getchar();
                                                            choose();
                                                        }
                                                    }
                                                }
                                                break;
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                }
                           
                                break;
                            case 2://房源管理
                                //已完成
                                jug9 = 1;
                                while (jug9 != 0)
                                {
                                    if (fl_number == 0)
                                    {
                                        printf("很遗憾，目前并没有房源\n");
                                        printf("是否录入房源\n");
                                        printf("1:是\t2:否\n");
                                        scanf("%d", &choice_2);
                                        if (choice_2 == 1)
                                        {
                                            int input_number;
                                            printf("请输入增加房源数量：");
                                            scanf("%d", &input_number);
                                            fl_number = fl_number + input_number;
                                            printf("请按照城市/面积/室/厅/朝向/楼层/租金顺序输入\n");
                                            for (int i = 0; i < input_number; i++)
                                            {
                                                char city[20];
                                                float Area;
                                                int shi;
                                                int ting;
                                                int t;
                                                int floor;
                                                float rent;
                                                scanf("%s", city);
                                                scanf("%f %d %d %d %d %f", &Area, &shi, &ting, &t, &floor, &rent);
                                                printf("信息录入成功\n");
                                                printf("目前有%d个房源\n", fl_number);
                                                printf("按下回车以继续\n");
                                                getchar();
                                                choose();
                                                break;
                                            }
                                        }
                                        if (choice_2 == 0)
                                        {
                                            choose();
                                            break;
                                        }


                                    }
                                    printf("*********房源管理*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     返    回       **\n");
                                    printf("**1.     信息修改       **\n");
                                    printf("**2.     删除房源       **\n");
                                    printf("**3.     增加房源       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("请选择功能：");
                                    scanf_s("%d", &choice_2);
                                    choose();
                                    switch (choice_2)
                                    {
                                    case 0:
                                    {
                                        jug9 = 0;
                                        break;
                                    }
                                    case 1://信息修改
                                    {
                                        printf("请输入希望修改的房屋序号（最多10个字符）：");
                                        scanf("%s", input_string);
                                        tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 4);
                                        tempIntPtr++;
                                        for (int i = 0; i != *(tempIntPtr - 1); i++)
                                        {
                                            fl_p1 = fl_head->next;
                                            for (int j = 0; j != tempIntPtr[i]; j++)
                                                fl_p1 = fl_p1->next;
                                            if (!strcmp(fl_p1->number, input_string))
                                            {
                                                jug5 = 1;
                                                break;
                                            }
                                        }
                                        if (jug5)
                                        {
                                            fl_change(fl_p1);
                                            printf("房屋信息已修改\n");
                                            printf("按下回车以继续\n");
                                            getchar();
                                            choose();
                                            jug5 = 0;//初始化
                                        }
                                        else
                                            if (*(tempIntPtr - 1) == 0)
                                            {
                                                printf("找不到您输入的内容。\n");
                                                printf("按下回车以继续\n");
                                                getchar();
                                                choose();
                                            }
                                            else
                                            {
                                                printf("您输入的内容比较模糊，为您找到以下内容\n");
                                                printf("序号\t\t编号\t\t姓名\t\t账号\t\t电话\n");
                                                for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                {
                                                    ag_p1 = ag_head->next;
                                                    for (int j = 0; j < *(tempIntPtr + i); j++)
                                                        ag_p1 = ag_p1->next;
                                                    printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", i + 1, ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                }
                                                printf("回车以继续\n");
                                                getchar();
                                                choose();
                                            }
                                        break;
                                    }
                                    case 2://删除房源
                                    {
                                        printf("请输入希望删除的房屋序号（最多10个字符）：");
                                        scanf("%s", input_string);
                                        tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 4);
                                        if (*tempIntPtr == 0)
                                        {
                                            printf("很凄惨，我们的应用没有房在用。");
                                            printf("回车以继续");
                                            getchar();
                                            choose();
                                            break;
                                        }
                                        tempIntPtr++;
                                        int t = 0;//删除的链表序号
                                        for (int i = 0; i != *(tempIntPtr - 1); i++)
                                        {
                                            fl_p1 = fl_head->next;
                                            for (int j = 0; j != tempIntPtr[i]; j++)
                                            {
                                                fl_p1 = fl_p1->next;
                                                if (!strcmp(fl_p1->number, input_string))
                                                {
                                                    t = tempIntPtr[i];
                                                    jug5 = 1;
                                                    break;
                                                }
                                            }
                                            if (jug5)
                                            {
                                                break;
                                            }
                                        }

                                        DelListall(fl_head, t);
                                        fl_number--;
                                        jug5 = 0;//初始化
                                        printf("该信息已经删除\n");
                                        printf("目前有%d个房源\n", fl_number);
                                        printf("按下回车以继续\n");
                                        getchar();
                                        choose();
                                        break;
                                    }
                                    case 3://增加房源
                                    {//此处大括号是因为声明局部变量
                                        int input_number;
                                        printf("请输入增加房源数量：");
                                        scanf("%d", &input_number);
                                        fl_number = fl_number + input_number;
                                        printf("请按照城市/面积/室/厅/朝向/楼层/租金顺序输入\n");
                                        for (int i = 0; i < input_number; i++)
                                        {
                                            char city[20];
                                            float Area;
                                            int shi;
                                            int ting;
                                            int t;
                                            int floor;
                                            float rent;
                                            scanf("%s", city);
                                            scanf("%f %d %d %d %d %f", &Area, &shi, &ting, &t, &floor, &rent);
                                            printf("信息录入成功\n");
                                            printf("目前有%d个房源\n", fl_number);
                                            printf("按下回车以继续\n");
                                            getchar();
                                            choose();
                                            break;
                                        }
                                    }
                                    }
                                }
                                break;
                            }
                        }
                        jug8 = 1;
                        break;
                    case 2://看房管理
                        //施工中
                        printf("*********看房管理*********\n");
                        printf("**                      **\n");
                        printf("**0.     返    回       **\n");
                        printf("**1.   预约信息处理     **\n");
                        printf("**2.   预约信息查询     **\n");
                        printf("**                      **\n");
                        printf("**************************\n");
                        scanf("%d", &choice_2);
                        switch (choice_2)
                        {
                        case 0:
                            break;
                        case 1:
                            printf("请输入您想要处理的预约信息:");
                            memset(input_string, 0, sizeof(input_string));
                            scanf("%s", input_string);
                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                            if (*tempIntPtr == 0)
                            {
                                printf("找不到该预约信息");
                                printf("回车以继续");
                                getchar();
                                choose();
                                break;
                            }
                            tempIntPtr++;
                            for (int i = 0; i != *(tempIntPtr - 1); i++)
                            {
                                ap_p = ap_head->next;
                                for (int j = 0; j != tempIntPtr[i]; j++)
                                    ap_p = ap_p->next;
                                if (!strcmp(ap_p->Number, input_string) || !strcmp(ap_p->custom->Account, input_string) || !strcmp(ap_p->custom->Name, input_string) || !strcmp(ap_p->custom->phone_n, input_string) || !strcmp(ap_p->flat->number, input_string))
                                {
                                    jug5 = 1;
                                    break;
                                }
                            }
                            if (jug5)
                            {
                                choose();
                                printf("成功找到对象\n");
                                printf("编号\t\t时间\t\t租客\t\t房源编号\n");
                                printf("%s\t%d:%d:%d\t%s\t\t%s\n", ap_p->Number, ap_p->year,ap_p->month,ap_p->day, ap_p->custom->Account, ap_p->flat->number);
                                printf("*********预约信息*********\n");
                                printf("**                      **\n");
                                printf("**0.     返    回       **\n");
                                printf("**1.     删    除       **\n");
                                printf("**2.     修改时间       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &choice_2);
                                switch (choice_2)
                                {
                                case 0:
                                    break;
                                    
                                case 1:
                                    printf("您确定要删除该预约信息吗？1确认 2取消：");
                                    scanf("%d", &jug6);
                                    if (jug6 == 1)
                                    {
                                        if (ap_p->next == NULL)
                                        {
                                            ap_tail = ap_p->prev;
                                            ap_p->prev->next = NULL;
                                            free(ap_p);
                                        }
                                        else
                                        {
                                            ap_p->prev->next = ap_p->next;
                                            ap_p->next->prev = ap_p->prev;
                                            free(ap_p);
                                        }
                                        ap_p = NULL;
                                    }
                                    printf("删除成功！\n");
                                    printf("回车以继续\n");
                                    getchar();
                                    choose();
                                    break;
                                case 2:
                                {
                                    printf("请输入新时间（年 月 日）:");
                                    year, month, day;
                                    scanf("%d%d%d", &year, &month, &day);
                                    time_t now = time(NULL);
                                    struct tm* local = localtime(&now);
                                    if (year < local->tm_year || (year == local->tm_year && month < local->tm_mon) || (year == local->tm_year && month == local->tm_mon && day < local->tm_mday))
                                        printf("无效的时间\n");
                                    else
                                    {
                                        ap_p->year = year;
                                        ap_p->month = month;
                                        ap_p->day = day;
                                        printf("修改成功！\n");
                                    }
                                }
                                    printf("回车以继续\n");
                                    getchar();
                                    choose();
                                    break;
                                }
                                jug6 = 0;
                                jug5 = 0;//初始化
                            }
                            else
                                if (*(tempIntPtr - 1) == 0)
                                {
                                    printf("找不到您输入的内容。\n");
                                    printf("按下回车以继续\n");
                                    getchar();
                                    choose();
                                }
                                else
                                {
                                    printf("您输入的内容比较模糊，为您找到以下内容\n");
                                    printf("编号\t\t时间\t\t租客\t\t房源编号\n");
                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                    {
                                        ap_p = ap_head->next;
                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                            ap_p = ap_p->next;
                                        printf("%s\t%d:%d:%d\t%s\t\t%s\n", ap_p->Number, ap_p->year, ap_p->month, ap_p->day, ap_p->custom->Account, ap_p->flat->number);
                                    }
                                    printf("回车以继续\n");
                                    getchar();
                                    choose();
                                }
                            free(tempIntPtr - 1);
                            tempIntPtr = NULL;
                            break;
                        case 2:
                            printf("请输入信息:");
                            memset(input_string, 0, sizeof(input_string));
                            scanf("%s", input_string);
                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                            if (*tempIntPtr == 0)
                            {
                                printf("找不到该预约信息");
                                printf("回车以继续");
                                getchar();
                                choose();
                                break;
                            }
                            tempIntPtr++;
                            if (*(tempIntPtr - 1) == 0)
                            {
                                printf("找不到您输入的内容。\n");
                                printf("按下回车以继续\n");
                                getchar();
                                choose();
                            }
                            else
                            {
                                printf("为您找到以下内容\n");
                                printf("编号\t\t时间\t\t租客\t\t房源编号\n");
                                for (int i = 0; i < *(tempIntPtr - 1); i++)
                                {
                                    ap_p = ap_head->next;
                                    for (int j = 0; j < *(tempIntPtr + i); j++)
                                        ap_p = ap_p->next;
                                    printf("%s\t%d:%d:%d\t%s\t\t%s\n", ap_p->Number, ap_p->year, ap_p->month, ap_p->day, ap_p->custom->Account, ap_p->flat->number);
                                }
                                printf("回车以继续\n");
                                getchar();
                                choose();
                            }
                            free(tempIntPtr - 1);
                            tempIntPtr = NULL;
                            break;
                        }
                        break;
                    case 3://信息查询
                   
                            printf("*********查询方式*********\n");
                            printf("**                      **\n");
                            printf("**0.     返    回       **\n");
                            printf("**1.     范围查找       **\n");
                            printf("**2.     具体查找       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            scanf("%d", &choice_6);
                            choose();
                            switch (choice_6)
                            {
                            case 0:
                              break;
                            case 1:
                                printf("*********查询方式*********\n");
                                printf("**                      **\n");
                                printf("**1.     租    金       **\n");
                                printf("**2.     楼    层       **\n");
                                printf("**3.     面    积       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &choice_6);
                                choose();
                                int left = 0;
                                int right = 0;

                                printf("*********排序方式*********\n");
                                printf("**                      **\n");
                                printf("**1.     从小到大       **\n");
                                printf("**2.     从大到小       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &jug7);
                                printf("请输入左右范围:\n");
                                printf("左:");
                                scanf("%d", &left);
                                printf("\n右:");
                                scanf("%d", &right);
                                choose();
                                int t;
                                t=range_search_Area(left, right, fl_head, fl_tail, choice_6, jug7);
                                printf("共有%d间房子符合标准\n",t);
                                printf("按下回车以继续\n");
                                getchar();
                                choose();
                                break;
                            case 2:
                                printf("*********查询方式*********\n");
                                printf("**                      **\n");
                                printf("**1.     城    市       **\n");
                                printf("**2.     中    介       **\n");
                                printf("**3.     编    号       **\n");
                                printf("**4.     朝    向       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &choice_6);
                                switch (choice_6)
                                {
                                case 0:
                                    break;
                                case 1:
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    break;
                                case 4:
                                    break;

                                }
                                break;
                            }
                            
                 
             
                        break;
                    case 4://信息排序并输出
                        //施工中
                        printf("*********查看房源*********\n");
                        printf("**                      **\n");
                        printf("**0.     返    回       **\n");
                        printf("**1.     租    金       **\n");
                        printf("**2.     层    数       **\n");
                        printf("**3.     房产面积       **\n");
                        printf("**                      **\n");
                        printf("**************************\n");
                        scanf("%d", &choice_5);
                        if(choice_5==0)
                        {
                            choose();
                            break;
                        }
                        else
                        {
                            bubbleSort_Area(&fl_head, choice_5);
                            choose();
                            printf("*********排序方式*********\n");
                            printf("**                      **\n");
                            printf("**1.     从小到大       **\n");
                            printf("**2.     从大到小       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            scanf("%d", &jug7);
                            choose();
                            list_printfl(fl_head, fl_tail, jug7);
                            printf("按下回车以继续\n");
                            getchar();
                            choose();
                            break;
                        }
                    case 5://信息统计
                        //完工
                        printf("访问人数：我们没有接入互联网\n");
                        printf("管理员数量：%d\n", countNumberAD(ad_head));
                        printf("中介人员数量：%d\n", countNumberAG(ag_head));
                        printf("租客人员数量：%d\n", countNumberCU(cu_head));
                        printf("房源数量：%d\n", countNumberFL(fl_head));
                        printf("预约总数：%d\n", countNumberAP(ap_head));
                        printf("按下回车以继续\n");
                        choose();
                        break;
                    case 6:
                        while (1)
                        {
                            memset(input_key, 0, sizeof(input_key));
                            memset(input_key_2, 0, sizeof(input_key_2));
                            printf("请输入密码：");
                            scanf("%s", input_key);
                            printf("请确认密码：");
                            scanf("%s", input_key_2);
                            if (!strcmp(input_key, input_key_2))
                            {
                                strcpy(ad_p1->Key, input_key);
                                printf("修改成功!\n");
                                printf("回车以继续\n");
                                getchar();
                                choose();
                                break;
                            }
                            else
                            {
                                printf("两次输入不一样的嘞");
                                printf("回车以继续");
                                getchar();
                                choose();
                                break;
                            }
                        }
                        break;
                    case 7://生成邀请码
                        build_invitation = radom_string(19);
                        if (build_invitation == NULL)
                            return -1;
                        printf("新的邀请码为：%s\n", build_invitation);
                        printf("回车以继续\n");
                        strcpy(ad_p1->invitation, build_invitation);
                        ad_p1->effective = 1;
                        free(build_invitation);
                        choose();
                        break;
                    case 8:
                        if (ad_p1->prev->prev == NULL && ad_p1->next == NULL)
                        {
                            printf("你是最后一个管理员，别删了兄弟\n");
                            printf("回车以继续");
                            getchar();
                            choose();
                            break;
                        }
                        printf("您确定要删除您的账户吗？1确定 2取消；");
                        scanf("%d", &jug6);
                        if (jug6 == 1)
                        {
                            if (ad_p1->next == NULL)
                            {
                                ad_p1->prev->next = NULL;
                                free(ad_p1);
                                ad_p1 = NULL;
                            }
                            else
                            {
                                ad_p1->prev->next = ad_p1->next;
                                ad_p1->next->prev = ad_p1->prev;
                                free(ad_p1);
                                ad_p1 = NULL;
                            }
                            printf("操作成功\n");
                            printf("回车以继续");
                            getchar();
                            choose();
                        }
                        break;
                    }
                   
                }
                break;
            case 2://中介
                printf("请输入账户（account）：");
                scanf("%s", input_account);
                ag_p1 = ag_head->next;
                if (ag_p1 == NULL)
                {
                    logError(0);
                    return -1;
                }
                while (1)
                {
                    if (!strcmp(input_account, ag_p1->Account))
                    {
                        printf("请输入密码（key）:");
                        scanf("%s", input_key);
                        if (!strcmp(input_key, ag_p1->Key))
                        {
                            printf("登录成功，欢迎，中介员工%s\n", ag_p1->Name);
                            printf("回车以继续\n");
                            getchar();
                            jug = 1;
                            choose();
                        }
                        else
                        {
                            printf("密码错误\n");
                            printf("回车以继续\n");
                            getchar();
                            jug = 0;
                            choose();
                        }
                        break;
                    }
                    ag_p1 = ag_p1->next;
                    if (ag_p1 == NULL)
                    {
                        printf("找不到对象\n");
                        printf("回车以继续\n");
                        getchar();
                        jug = 0;
                        choose();
                        break;
                    }
                }
                while (jug)
                {
                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     注    销       **\n");
                    printf("**1.     看房管理       **\n");
                    printf("**2.     租房管理       **\n");
                    printf("**3.     信息查询       **\n");
                    printf("**4.     信息排序       **\n");
                    printf("**5.     信息统计       **\n");
                    printf("**6.     更改密码       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("请选择功能：");
                    scanf_s("%d", &choice_3);
                    choose();
                    switch (choice_3)
                    {
                    case 0:
                        jug = 0;
                        ag_p1 = ag_tail;
                        break;
                    case 1:
                        //空闲中
                        break;
                    case 2:
                        //空闲中
                        break;
                    case 3:
                        //空闲中
                        break;
                    case 4:
                        //空闲中
                        break;
                    case 5:
                        //空闲中
                        break;
                    case 6:
                        //空闲中
                        break;

                    }
                }
                break;
            case 3://租客
                printf("请输入账户（account）：");
                scanf("%s", input_account);
                cu_p1 = cu_head->next;
                if (cu_p1 == NULL)
                {
                    logError(0);
                    return -1;
                }
                while (1)
                {
                    if (!strcmp(input_account, cu_p1->Account))
                    {
                        printf("请输入密码（key）:");
                        scanf("%s", input_key);
                        if (cu_p1->statment == 0)
                        {
                            printf("抱歉，您因为违反我们的条例而被封禁。如有问题请联系管理员\n");
                            printf("回车以继续");
                            getchar();
                            choose();
                            jug = 0;
                            break;
                        }
                        if (!strcmp(input_key, cu_p1->Key))
                        {
                            printf("登录成功，欢迎，亲爱的%s\n", cu_p1->Account);
                            printf("回车以继续\n");
                            getchar();
                            jug = 1;
                            choose();
                        }
                        else
                        {
                            printf("密码错误\n");
                            printf("回车以继续\n");
                            getchar();
                            jug = 0;
                            choose();
                        }
                        break;
                    }
                    cu_p1 = cu_p1->next;
                    if (cu_p1 == NULL)
                    {
                        printf("找不到对象\n");
                        printf("回车以继续\n");
                        getchar();
                        jug = 0;
                        choose();
                        break;
                    }
                }
                while (jug)
                {
                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     注    销       **\n");
                    printf("**1.     个人信息       **\n");
                    printf("**2.     看房预约       **\n");
                    printf("**3.     信息查询       **\n");
                    printf("**4.     信息排序       **\n");
                    printf("**5.     信息统计       **\n");
                    printf("**6.     更改密码       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("请选择功能：");
                    scanf_s("%d", &choice_4);
                    choose();
                    switch (choice_4)
                    {
                    case 0:
                        jug = 0;
                        cu_p1 = cu_tail;
                        break;
                    case 1:
                        //空闲中
                        break;
                    case 2:
                        //空闲中
                        break;
                    case 3:
                        //空闲中
                        break;
                    case 4:
                        //空闲中
                        break;
                    case 5:
                        //空闲中
                        break;
                    case 6:
                        //空闲中
                        break;

                    }
                }
                break;
            }
            break;
        case 2:
            printf("******身份选择******\n");
            printf("**                **\n");
            printf("**0.  退    出    **\n");
            printf("**1.  管 理 员    **\n");
            printf("**2.  中    介    **\n");
            printf("**3.  租    客    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("请选择身份：");
            scanf_s("%d", &choice_5);
            choose();
            switch (choice_5)
            {
            case 1:
                printf("请输入邀请码：");
                scanf("%s", input_invitation);
                ad_p1 = ad_head->next;
                while (jug3)
                {
                    while (!strcmp(input_invitation, ad_p1->invitation) && jug2 && ad_p1->effective == 1)
                    {
                        if (jug4)
                        {
                            ad_p2 = ad_p1;
                            jug4 = 0;
                        }
                        memset(input_account, 0, sizeof(input_account));
                        printf("请输入账户：（20个字符）");
                        scanf("%s", input_account);
                        ad_p1 = ad_head->next;
                        while (1)
                        {
                            if (ad_p1 == NULL)
                            {
                                printf("请输入密码：");
                                scanf("%s", input_key);
                                printf("请确认密码：");
                                scanf("%s", input_key_2);
                                if (!strcmp(input_key, input_key_2))
                                {
                                    ad_p2->effective = 0;
                                    extendAdmin(input_account, input_key, ad_p1, ad_p2, ad_tail);
                                    ad_tail = ad_tail->next;
                                    ad_p2 = ad_tail;
                                    ad_p1 = ad_tail;
                                    printf("注册成功！");
                                    printf("回车以继续");
                                    getchar();
                                    choose();
                                    jug2 = 0;
                                    jug3 = 0;
                                    break;
                                }
                                else
                                {
                                    printf("两次输入不一样的嘞");
                                    printf("回车以继续");
                                    getchar();
                                    choose();
                                    ad_p1 = ad_head->next;
                                    break;
                                }
                            }
                            if (!strcmp(input_account, ad_p1->Account))
                            {
                                ad_p1 = ad_head->next;
                                printf("该用户已经存在\n");
                                printf("按回车以继续\n");
                                getchar();
                                choose();
                                break;
                            }
                            ad_p1 = ad_p1->next;
                        }
                    }
                    if (jug2 == 1)
                    {
                        ad_p1 = ad_p1->next;
                        if (ad_p1 == NULL)
                        {
                            printf("无效或过期的的邀请码!\n");
                            printf("回车以继续\n");
                            getchar();
                            choose();
                            jug3 = 0;
                        }
                    }
                }
                jug2 = 1;
                jug3 = 1;
                jug4 = 1;
                break;
            case 2:
                printf("请输入邀请码：");
                scanf("%s", input_invitation);
                ad_p1 = ad_head->next;
                while (jug3)
                {
                    while (!strcmp(input_invitation, ad_p1->invitation) && jug2 && ad_p1->effective == 1)
                    {
                        if (jug4)
                        {
                            ad_p2 = ad_p1;
                            jug4 = 0;
                        }
                        memset(input_account, 0, sizeof(input_account));
                        memset(input_phonenumber, 0, sizeof(input_phonenumber));
                        printf("请输入电话号码：(11位)");
                        scanf("%s", input_phonenumber);
                        while (strlen(input_phonenumber) != 11)
                        {
                            choose();
                            printf("无效的电话号码！\n");
                            printf("请输入正确的的电话号码:");
                            memset(input_phonenumber, 0, sizeof(input_phonenumber));
                            scanf("%s", input_phonenumber);
                        }
                        printf("请输入账户：（20个字符）");
                        scanf("%s", input_account);
                        ag_p1 = ag_head->next;
                        while (1)
                        {
                            if (ag_p1 == NULL)
                            {
                                printf("请输入密码：");
                                scanf("%s", input_key);
                                printf("请确认密码：");
                                scanf("%s", input_key_2);
                                if (!strcmp(input_key, input_key_2))
                                {
                                    ad_p2->effective = 0;
                                    extendAgency(input_account, input_key, ag_p1, ag_head, ag_tail);
                                    ag_tail = ag_tail->next;
                                    ag_p2 = ag_tail;
                                    ag_p1 = ag_tail;
                                    strcpy(ag_p1->phone_n, input_phonenumber);
                                    printf("注册成功！\n");
                                    printf("您的编号为%s\n", ag_p1->Number);
                                    printf("请输入您的姓名：");
                                    scanf("%s", ag_p1->Name);
                                    printf("回车以继续\n");
                                    getchar();
                                    choose();
                                    jug2 = 0;
                                    jug3 = 0;
                                    break;
                                }
                                else
                                {
                                    printf("两次输入不一样的嘞");
                                    printf("回车以继续");
                                    getchar();
                                    choose();
                                    ag_p1 = ag_head->next;
                                    break;
                                }
                            }
                            if (!strcmp(input_account, ag_p1->Account) || !strcmp(input_phonenumber, ag_p1->phone_n))
                            {
                                ag_p1 = ag_head->next;
                                printf("该用户已经存在\n");
                                printf("按回车以继续\n");
                                getchar();
                                choose();
                                break;
                            }
                            ag_p1 = ag_p1->next;
                        }
                    }
                    if (jug2 == 1)
                    {
                        ad_p1 = ad_p1->next;
                        if (ad_p1 == NULL)
                        {
                            printf("无效或过期的的邀请码!\n");
                            printf("回车以继续\n");
                            getchar();
                            choose();
                            jug3 = 0;
                        }
                    }
                }
                jug2 = 1;
                jug3 = 1;
                break;
            case 3:
                while (jug2)
                {
                    memset(input_account, 0, sizeof(input_account));
                    memset(input_phonenumber, 0, sizeof(input_phonenumber));
                    printf("请输入电话号码：(11位)");
                    scanf("%s", input_phonenumber);
                    while (strlen(input_phonenumber) != 11)
                    {
                        choose();
                        printf("无效的电话号码！\n");
                        printf("请输入正确的的电话号码:");
                        memset(input_phonenumber, 0, sizeof(input_phonenumber));
                        scanf("%s", input_phonenumber);
                    }
                    printf("请输入账户：（20个字符）");
                    scanf("%s", input_account);
                    cu_p1 = cu_head->next;
                    while (1)
                    {
                        if (cu_p1 == NULL)
                        {
                            printf("请输入密码：");
                            scanf("%s", input_key);
                            printf("请确认密码：");
                            scanf("%s", input_key_2);
                            if (!strcmp(input_key, input_key_2))
                            {
                                extendCustomer(input_account, input_key, cu_p1, cu_p2, cu_tail);
                                cu_tail = cu_tail->next;
                                cu_p2 = cu_tail;
                                cu_p1 = cu_tail;
                                strcpy(cu_p1->phone_n, input_phonenumber);
                                printf("注册成功！\n");

                                printf("请输入您的姓名：");
                                scanf("%s", cu_p1->Name);
                                printf("回车以继续\n");
                                getchar();
                                choose();
                                jug2 = 0;
                                break;
                            }
                            else
                            {
                                printf("两次输入不一样的嘞");
                                printf("回车以继续");
                                getchar();
                                choose();
                                cu_p1 = cu_head->next;
                                break;
                            }
                        }
                        if (!strcmp(input_account, cu_p1->Account) || !strcmp(input_phonenumber, cu_p1->phone_n))
                        {
                            cu_p1 = cu_head->next;
                            printf("该用户已经存在\n");
                            printf("按回车以继续\n");
                            getchar();
                            choose();
                            break;
                        }
                        cu_p1 = cu_p1->next;
                    }
                }
                break;
            default:
                break;
            }
            break;

        }
    }
    filecachAD_write(ad_head);
    filecachAG_write(ag_head);
    filecachCU_write(cu_head);
    filecachAP_write(ap_head);
    filecachFL_write(fl_head);
    return 0;
}
static void choose()//用于清屏
{
    char wait;
    //getchar();             //吃'\n'
    scanf("%c", &wait);
    if (wait == '\n')
        system("cls");
    else
        choose();
}