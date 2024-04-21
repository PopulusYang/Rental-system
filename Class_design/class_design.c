#define _CRT_SECURE_NO_WARNINGS
#include"temphead.h"
#include"list.h"
#pragma warning(disable:6031) 
typedef struct Flat Flat, * list_1;



int main()
{
    struct Admin* ad_p1, * ad_p2, * ad_tail, * ad_head;//��������
    ad_p1 = (struct Admin*)malloc(sizeof(struct Admin));//����ռ�
    if (ad_p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;

    }
    ad_tail = ad_p1;//���ͷβ
    ad_head = ad_p1;
    ad_p2 = ad_p1;
    ad_tail->next = NULL;
    ad_head->prev = NULL;


    struct Agency* ag_p1, * ag_p2, * ag_tail, * ag_head;//��������
    ag_p1 = (struct Agency*)malloc(sizeof(struct Agency));//����ռ�
    if (ag_p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;

    }
    ag_tail = ag_p1;//���ͷβ
    ag_head = ag_p1;
    ag_p2 = ag_p1;
    ag_tail->next = NULL;
    ag_head->prev = NULL;


    struct Customer* cu_p1, * cu_p2, * cu_tail, * cu_head;//��������
    cu_p1 = (struct Customer*)malloc(sizeof(struct Customer));//����ռ�
    if (cu_p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;
    }
    cu_tail = cu_p1;//���ͷβ
    cu_head = cu_p1;
    cu_p2 = cu_p1;
    cu_tail->next = NULL;
    cu_head->prev = NULL;



    struct Flat* fl_p1, * fl_p2, * fl_tail, * fl_head;//��������
    fl_p1 = (struct Flat*)malloc(sizeof(struct Flat));//����ռ�
    if (fl_p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        logError(0);
        return -1;
    }
    fl_tail = fl_p1;//���ͷβ
    fl_head = fl_p1;
    fl_p2 = fl_p1;
    fl_tail->next = NULL;
    fl_head->prev = NULL;

    struct Appointment* ap_p, * ap_tail, * ap_head,* ap_p2;//����ԤԼ��Ϣ����
    ap_p2 = NULL;
    ap_p = (struct Appointment*)malloc(sizeof(struct Appointment));
    if (ap_p == NULL)//ע�ⰲȫ������
    {
        logError(0);
        return -1;
    }
    ap_tail = ap_p;//���ͷβ
    ap_head = ap_p;
    ap_tail->next = NULL;
    //���ݶ�ȡ
    filecachAD_read(&ad_tail);
    filecachAG_read(&ag_tail);
    filecachCU_read(&cu_tail);
    filecachFL_read(&fl_tail,ag_head);
    filecachAP_read(&ap_tail,cu_head,fl_head);

    void choose();
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;
    //0:��¼���� 1��������˵� 2������Ա���˵� 3���н����˵� 4��������˵�
    int choice_5;//ѡ������ʽ��
    int choice_6;//ѡ������ѯ����
    int jug = 0;//�����֤��//�ַ���������
    int jug2 = 1, jug3 = 1;//ע����
    int jug4 = 1;//��ad_p1->effectiveִֻ��һ��
    int jug5 = 0;//������
    int jug6 = 0;//ѡ����
    int jug7 = 0;//ѡ������������
    int jug8 = 1;//���ܹ����¼�
    int jug9 = 1;//��Ϣ�������¼�

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
    //������ڵ�ԤԼ
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
    printf("���ݼ�����ɣ����»س��Լ���");
    choose();
    while (choice_0)
    {
        printf("******��    ¼******\n");
        printf("**                **\n");
        printf("**0.  ��    ��    **\n");
        printf("**1.  ��    ¼    **\n");
        printf("**2.  ע    ��    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("��ѡ���ܣ�");
        scanf_s("%d", &choice_0);
        choose();
        switch (choice_0)
        {
        case 0:
            break;
        case 1:
            printf("******���ѡ��******\n");
            printf("**                **\n");
            printf("**0.  ��    ��    **\n");
            printf("**1.  �� �� Ա    **\n");
            printf("**2.  ��    ��    **\n");
            printf("**3.  ��    ��    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("��ѡ����ݣ�");
            scanf_s("%d", &choice_1);
            choose();


            //���ú���
            switch (choice_1)
            {
            case 0:
                break;
            case 1://����Ա
                printf("�������˻���account����");
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
                        printf("���������루key��:");
                        scanf("%s", input_key);
                        if (!strcmp(input_key, ad_p1->Key))
                        {
                            printf("��¼�ɹ�����ӭ������Ա%s\n", ad_p1->Account);
                            printf("�س��Լ���\n");
                            getchar();
                            jug = 1;
                            choose();
                        }
                        else
                        {
                            printf("�������\n");
                            printf("�س��Լ���\n");
                            getchar();
                            jug = 0;
                            choose();
                        }
                        break;
                    }
                    ad_p1 = ad_p1->next;
                    if (ad_p1 == NULL)
                    {
                        printf("�Ҳ�������\n");
                        printf("�س��Լ���\n");
                        getchar();
                        jug = 0;
                        choose();
                        break;
                    }
                }
                while (jug && ad_p1 != NULL)
                {
                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ע    ��       **\n");
                    printf("**1.     ��Ϣ����       **\n");//�깤
                    printf("**2.     ��������       **\n");//δʿ�����깤
                    printf("**3.     ��Ϣ��ѯ       **\n");//�깤
                    printf("**4.     ��Ϣ����       **\n");//δʿ��ʩ����
                    printf("**5.     ��Ϣͳ��       **\n");//ʩ����
                    printf("**6.     ��������       **\n");//�깤
                    printf("**7.    ����������      **\n");//�깤
                    printf("**8.     ɾ���˻�       **\n");//�깤
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_2);
                    choose();

                    switch (choice_2)
                    {
                    case 0:
                        jug = 0;
                        ad_p1 = ad_tail;
                        break;
                    case 1:
                        //�����
                        while (jug8)
                        {
                            printf("*********��Ϣ����*********\n");
                            printf("**                      **\n");
                            printf("**0.     ��    ��       **\n");
                            printf("**1.     ��Ա����       **\n");
                            printf("**2.     ��Դ����       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            printf("��ѡ���ܣ�");
                            scanf_s("%d", &choice_2);
                            choose();
                            switch (choice_2)
                            {
                            case 0:
                                jug8 = 0;
                                break;
                            case 1://��Ա����
                                //�깤
                                while (jug9)
                                {
                                    printf("*********��Ա����*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     ��    ��       **\n");
                                    printf("**1.     Ա������       **\n");
                                    printf("**2.   �����Ϣ����     **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("��ѡ���ܣ�");
                                    scanf_s("%d", &choice_2);
                                    choose();
                                    switch (choice_2)
                                    {
                                    case 0:
                                        jug9 = 0;
                                        break;
                                    case 1:
                                        //�깤
                                        printf("*********Ա������*********\n");
                                        printf("**                      **\n");
                                        printf("**0.     ��    ��       **\n");
                                        printf("**1.     ��Ϣ�޸�       **\n");
                                        printf("**2.     ɾ��Ա��       **\n");
                                        printf("**3.     ����Ա��       **\n");
                                        printf("**                      **\n");
                                        printf("**************************\n");
                                        printf("��ѡ���ܣ�");
                                        scanf_s("%d", &choice_2);
                                        choose();
                                        switch (choice_2)
                                        {
                                        case 0:
                                            break;
                                        case 1:
                                            //�깤
                                            //����
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("������Ա����Ϣ�����50���ַ�����");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("����ң����ǵ�Ӧ��û�������á�\n");
                                                printf("�س��Լ���\n");
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
                                                printf("�ɹ��ҵ�����\n");
                                                printf("���\t\t����\t\t�˺�\t\t�绰\n");
                                                printf("%s\t%s\t\t%s\t\t%s\n", ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                printf("*********��Ϣ�޸�*********\n");
                                                printf("**                      **\n");
                                                printf("**0.     ��    ��       **\n");
                                                printf("**1.     ��������       **\n");
                                                printf("**2.     �޸�����       **\n");
                                                printf("**3.     �޸ĵ绰       **\n");
                                                printf("**                      **\n");
                                                printf("**************************\n");
                                                printf("��ѡ���ܣ�");
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
                                                        printf("���������룺");
                                                        scanf("%s", input_key);
                                                        printf("��ȷ�����룺");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            strcpy(ag_p1->Key, input_key);
                                                            printf("�޸ĳɹ�!\n");
                                                            printf("�س��Լ���\n");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("�������벻һ������\n");
                                                            printf("�س��Լ���\n");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("�������µ�����:");
                                                    scanf("%s", input_string);
                                                    strcpy(ag_p1->Name, input_string);
                                                    printf("�޸ĳɹ���\n");
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                case 3:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("�������µĵ绰����:");
                                                    scanf("%s", input_string);
                                                    while (strlen(input_string) != 11)
                                                    {
                                                        choose();
                                                        printf("��Ч�ĵ绰���룡\n");
                                                        printf("��������ȷ�ĵĵ绰����:");
                                                        memset(input_string, 0, sizeof(input_string));
                                                        scanf("%s", input_string);
                                                    }
                                                    strcpy(ag_p1->phone_n, input_string);
                                                    printf("�޸ĳɹ���\n");
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                }
                                                jug5 = 0;//��ʼ��
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("�Ҳ�������������ݡ�\n");
                                                    printf("���»س��Լ���");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("����������ݱȽ�ģ����Ϊ���ҵ���������\n");
                                                    printf("���\t\t���\t\t����\t\t�˺�\t\t�绰\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        ag_p1 = ag_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            ag_p1 = ag_p1->next;
                                                        printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", i + 1, ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                    }
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 2:
                                            //�깤
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("������Ա����Ϣ�����50���ַ�����");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("����ң����ǵ�Ӧ��û�������á�\n");
                                                printf("�س��Լ���\n");
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
                                                printf("�ɹ��ҵ�����\n");
                                                printf("���\t\t����\t\t�˺�\t\t�绰\n");
                                                printf("%s\t%s\t\t%s\t\t%s\n", ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                printf("��ȷ��Ҫɾ����Ա����\n1ȷ��\t 2ȡ����\n");
                                                printf("����ѡ��");
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
                                                jug5 = 0;//��ʼ��
                                                printf("ɾ���ɹ���\n");
                                                printf("�س��Լ���\n");
                                                getchar();
                                                choose();
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("�Ҳ�������������ݡ�\n");
                                                    printf("���»س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("����������ݱȽ�ģ����Ϊ���ҵ���������\n");
                                                    printf("���\t\t���\t\t����\t\t�˺�\t\t�绰\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        ag_p1 = ag_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            ag_p1 = ag_p1->next;
                                                        printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", i + 1, ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                    }
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 3:
                                            //�깤
                                            while (jug2)
                                            {
                                                memset(input_account, 0, sizeof(input_account));
                                                memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                printf("������绰���룺(11λ)");
                                                scanf("%s", input_phonenumber);
                                                while (strlen(input_phonenumber) != 11)
                                                {
                                                    choose();
                                                    printf("��Ч�ĵ绰���룡\n");
                                                    printf("��������ȷ�ĵĵ绰����:");
                                                    memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                    scanf("%s", input_phonenumber);
                                                }
                                                printf("�������˻�����20���ַ���");
                                                scanf("%s", input_account);
                                                ag_p1 = ag_head->next;
                                                while (1)
                                                {
                                                    if (ag_p1 == NULL)
                                                    {
                                                        printf("���������룺");
                                                        scanf("%s", input_key);
                                                        printf("��ȷ�����룺");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            extendAgency(input_account, input_key, ag_p1, ag_head, ag_tail);
                                                            ag_tail = ag_tail->next;
                                                            ag_p1 = ag_tail;
                                                            strcpy(ag_p1->phone_n, input_phonenumber);
                                                            printf("ע��ɹ���\n");
                                                            printf("���û��ı��Ϊ%s\n", ag_p1->Number);
                                                            printf("�������û���������");
                                                            scanf("%s", ag_p1->Name);
                                                            printf("�س��Լ���\n");
                                                            getchar();
                                                            choose();
                                                            jug2 = 0;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("�������벻һ������");
                                                            printf("�س��Լ���");
                                                            getchar();
                                                            choose();
                                                            ag_p1 = ag_head->next;
                                                            break;
                                                        }
                                                    }
                                                    if (!strcmp(input_account, ag_p1->Account) || !strcmp(input_phonenumber, ag_p1->phone_n))
                                                    {
                                                        ag_p1 = ag_head->next;
                                                        printf("���û��Ѿ�����\n");
                                                        printf("���س��Լ���\n");
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
                                        //�깤
                                        printf("*******�����Ϣ����*******\n");
                                        printf("**                      **\n");
                                        printf("**0.     ��    ��       **\n");
                                        printf("**1.     ��Ϣ�޸�       **\n");
                                        printf("**2.     ɾ���˻�       **\n");
                                        printf("**3.     �����˻�       **\n");
                                        printf("**4.   �����Ϣ����     **\n");
                                        printf("**                      **\n");
                                        printf("**************************\n");
                                        printf("��ѡ���ܣ�");
                                        scanf_s("%d", &choice_2);
                                        choose();
                                        switch (choice_2)
                                        {
                                        case 0:
                                            choice_2 = 1;
                                            break;
                                        case 1:
                                            //�깤
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("�������û���Ϣ�����50���ַ�����");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("����ң����ǵ�Ӧ��û�������á�");
                                                printf("�س��Լ���");
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
                                                printf("�ɹ��ҵ�����\n");
                                                printf("����\t\t�˺�\t\t�绰\n");
                                                printf("%s\t\t%s\t\t%s\n", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                printf("*********��Ϣ�޸�*********\n");
                                                printf("**                      **\n");
                                                printf("**0.     ��    ��       **\n");
                                                printf("**1.     ��������       **\n");
                                                printf("**2.     �޸�����       **\n");
                                                printf("**3.     �޸ĵ绰       **\n");
                                                printf("**                      **\n");
                                                printf("**************************\n");
                                                printf("��ѡ���ܣ�");
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
                                                        printf("���������룺");
                                                        scanf("%s", input_key);
                                                        printf("��ȷ�����룺");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            strcpy(cu_p1->Key, input_key);
                                                            printf("�޸ĳɹ�!\n");
                                                            printf("�س��Լ���\n");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("�������벻һ������");
                                                            printf("�س��Լ���");
                                                            getchar();
                                                            choose();
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("�������µ�����:");
                                                    scanf("%s", input_string);
                                                    strcpy(cu_p1->Name, input_string);
                                                    printf("�޸ĳɹ���\n");
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                case 3:
                                                    memset(input_string, 0, sizeof(input_string));
                                                    printf("�������µĵ绰����:");
                                                    scanf("%s", input_string);
                                                    while (strlen(input_string) != 11)
                                                    {
                                                        choose();
                                                        printf("��Ч�ĵ绰���룡\n");
                                                        printf("��������ȷ�ĵĵ绰����:");
                                                        memset(input_string, 0, sizeof(input_string));
                                                        scanf("%s", input_string);
                                                    }
                                                    strcpy(cu_p1->phone_n, input_string);
                                                    printf("�޸ĳɹ���\n");
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                    break;
                                                }
                                                jug5 = 0;//��ʼ��
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("�Ҳ�������������ݡ�\n");
                                                    printf("���»س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("����������ݱȽ�ģ����Ϊ���ҵ���������\n");
                                                    printf("���\t\t����\t\t�˺�\t\t�绰\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        cu_p1 = cu_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            cu_p1 = cu_p1->next;
                                                        printf("%d\t\t%s\t\t%s\t\t%s\n", i + 1, cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    }
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 2:
                                            //�깤
                                            memset(input_string, 0, sizeof(input_string));
                                            printf("�������û���Ϣ�����50���ַ�����");
                                            scanf("%s", input_string);
                                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                            if (*tempIntPtr == 0)
                                            {
                                                printf("����ң����ǵ�Ӧ��û�������á�");
                                                printf("�س��Լ���");
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
                                                printf("�ɹ��ҵ�����\n");
                                                printf("����\t\t�˺�\t\t�绰\n");
                                                printf("%s\t\t%s\t\t%s\n", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                printf("��ȷ��Ҫɾ�����û���1ȷ�� 2ȡ����");
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
                                                jug5 = 0;//��ʼ��
                                                printf("ɾ���ɹ���\n");
                                                printf("�س��Լ���\n");
                                                getchar();
                                                choose();
                                            }
                                            else
                                                if (*(tempIntPtr - 1) == 0)
                                                {
                                                    printf("�Ҳ�������������ݡ�\n");
                                                    printf("���»س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                                else
                                                {
                                                    printf("����������ݱȽ�ģ����Ϊ���ҵ���������\n");
                                                    printf("���\t\t����\t\t�˺�\t\t�绰\n");
                                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                    {
                                                        cu_p1 = cu_head->next;
                                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                                            cu_p1 = cu_p1->next;
                                                        printf("%d\t\t%s\t\t%s\t\t%s\n", i + 1, cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    }
                                                    printf("�س��Լ���\n");
                                                    getchar();
                                                    choose();
                                                }
                                            free(tempIntPtr - 1);
                                            tempIntPtr = NULL;
                                            break;
                                        case 3:
                                            //�깤
                                            while (jug2)
                                            {
                                                memset(input_account, 0, sizeof(input_account));
                                                memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                printf("������绰���룺(11λ)");
                                                scanf("%s", input_phonenumber);
                                                while (strlen(input_phonenumber) != 11)
                                                {
                                                    choose();
                                                    printf("��Ч�ĵ绰���룡\n");
                                                    printf("��������ȷ�ĵĵ绰����:");
                                                    memset(input_phonenumber, 0, sizeof(input_phonenumber));
                                                    scanf("%s", input_phonenumber);
                                                }
                                                printf("�������˻�����20���ַ���");
                                                scanf("%s", input_account);
                                                cu_p1 = cu_head->next;
                                                while (1)
                                                {
                                                    if (cu_p1 == NULL)
                                                    {
                                                        printf("���������룺");
                                                        scanf("%s", input_key);
                                                        printf("��ȷ�����룺");
                                                        scanf("%s", input_key_2);
                                                        if (!strcmp(input_key, input_key_2))
                                                        {
                                                            extendCustomer(input_account, input_key, cu_p1, cu_p2, cu_tail);
                                                            cu_tail = cu_tail->next;
                                                            cu_p1 = cu_tail;
                                                            strcpy(cu_p1->phone_n, input_phonenumber);
                                                            printf("ע��ɹ���\n");
                                                            printf("�������û���������");
                                                            scanf("%s", cu_p1->Name);
                                                            printf("�س��Լ���\n");
                                                            getchar();
                                                            choose();
                                                            jug2 = 0;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("�������벻һ������");
                                                            printf("�س��Լ���");
                                                            getchar();
                                                            choose();
                                                            cu_p1 = cu_head->next;
                                                            break;
                                                        }
                                                    }
                                                    if (!strcmp(input_account, cu_p1->Account) || !strcmp(input_phonenumber, cu_p1->phone_n))
                                                    {
                                                        cu_p1 = cu_head->next;
                                                        printf("���û��Ѿ�����\n");
                                                        printf("���س��Լ���\n");
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
                                            //�깤
                                            printf("*******�����Ϣ����*******\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     ����˻�       **\n");
                                            printf("**2.     ����˻�       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            printf("��ѡ���ܣ�");
                                            scanf_s("%d", &choice_2);
                                            choose();
                                            switch (choice_2)
                                            {
                                            case 0:
                                                choice_2 = 1;
                                                break;
                                            case 1:
                                                //�깤
                                                memset(input_string, 0, sizeof(input_string));
                                                printf("�������û���Ϣ�����50���ַ�����");
                                                scanf("%s", input_string);
                                                tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                                if (*tempIntPtr == 0)
                                                {
                                                    printf("����ң����ǵ�Ӧ��û�������á�");
                                                    printf("�س��Լ���");
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
                                                    printf("�ɹ��ҵ�����\n");
                                                    printf("����\t\t�˺�\t\t�绰\t\t״̬\n");
                                                    printf("%s\t\t%s\t\t%s\t\t", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    switch (cu_p1->statment)
                                                    {
                                                    case 1:
                                                        printf("����\n");
                                                        break;
                                                    case 0:
                                                        printf("���\n");
                                                    }
                                                    if (cu_p1->statment == 0)
                                                    {
                                                        printf("���û��ѱ����");
                                                        printf("�س��Լ���\n");
                                                        getchar();
                                                        choose();
                                                    }
                                                    if (cu_p1->statment == 1)
                                                    {
                                                        printf("��ȷ��Ҫ������û���1ȷ�� 2ȡ����");
                                                        scanf("%d", &jug6);
                                                        if (jug6 == 1)
                                                        {
                                                            cu_p1->statment = 0;
                                                            printf("�����ɹ���\n");
                                                            printf("�س��Լ���\n");
                                                            getchar();
                                                            choose();
                                                        }
                                                    }
                                                }
                                                break;
                                            case 2:
                                                //�깤
                                                memset(input_string, 0, sizeof(input_string));
                                                printf("�������û���Ϣ�����50���ַ�����");
                                                scanf("%s", input_string);
                                                tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 2);
                                                if (*tempIntPtr == 0)
                                                {
                                                    printf("����ң����ǵ�Ӧ��û�������á�");
                                                    printf("�س��Լ���");
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
                                                    printf("�ɹ��ҵ�����\n");
                                                    printf("����\t\t�˺�\t\t�绰\t\t״̬\n");
                                                    printf("%s\t\t%s\t\t%s\t\t", cu_p1->Name, cu_p1->Account, cu_p1->phone_n);
                                                    switch (cu_p1->statment)
                                                    {
                                                    case 1:
                                                        printf("����\n");
                                                        break;
                                                    case 0:
                                                        printf("���\n");
                                                    }
                                                    if (cu_p1->statment == 0)
                                                    {
                                                        printf("���û�״̬����");
                                                        printf("�س��Լ���\n");
                                                        getchar();
                                                        choose();
                                                    }
                                                    if (cu_p1->statment == 1)
                                                    {
                                                        printf("��ȷ��Ҫ�����û���1ȷ�� 2ȡ����");
                                                        scanf("%d", &jug6);
                                                        if (jug6 == 1)
                                                        {
                                                            cu_p1->statment = 1;
                                                            printf("�����ɹ���\n");
                                                            printf("�س��Լ���\n");
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
                            case 2://��Դ����
                                //�����
                                jug9 = 1;
                                while (jug9 != 0)
                                {
                                    if (fl_number == 0)
                                    {
                                        printf("���ź���Ŀǰ��û�з�Դ\n");
                                        printf("�Ƿ�¼�뷿Դ\n");
                                        printf("1:��\t2:��\n");
                                        scanf("%d", &choice_2);
                                        if (choice_2 == 1)
                                        {
                                            int input_number;
                                            printf("���������ӷ�Դ������");
                                            scanf("%d", &input_number);
                                            fl_number = fl_number + input_number;
                                            printf("�밴�ճ���/���/��/��/����/¥��/���˳������\n");
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
                                                printf("��Ϣ¼��ɹ�\n");
                                                printf("Ŀǰ��%d����Դ\n", fl_number);
                                                printf("���»س��Լ���\n");
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
                                    printf("*********��Դ����*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     ��    ��       **\n");
                                    printf("**1.     ��Ϣ�޸�       **\n");
                                    printf("**2.     ɾ����Դ       **\n");
                                    printf("**3.     ���ӷ�Դ       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("��ѡ���ܣ�");
                                    scanf_s("%d", &choice_2);
                                    choose();
                                    switch (choice_2)
                                    {
                                    case 0:
                                    {
                                        jug9 = 0;
                                        break;
                                    }
                                    case 1://��Ϣ�޸�
                                    {
                                        printf("������ϣ���޸ĵķ�����ţ����10���ַ�����");
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
                                            printf("������Ϣ���޸�\n");
                                            printf("���»س��Լ���\n");
                                            getchar();
                                            choose();
                                            jug5 = 0;//��ʼ��
                                        }
                                        else
                                            if (*(tempIntPtr - 1) == 0)
                                            {
                                                printf("�Ҳ�������������ݡ�\n");
                                                printf("���»س��Լ���\n");
                                                getchar();
                                                choose();
                                            }
                                            else
                                            {
                                                printf("����������ݱȽ�ģ����Ϊ���ҵ���������\n");
                                                printf("���\t\t���\t\t����\t\t�˺�\t\t�绰\n");
                                                for (int i = 0; i < *(tempIntPtr - 1); i++)
                                                {
                                                    ag_p1 = ag_head->next;
                                                    for (int j = 0; j < *(tempIntPtr + i); j++)
                                                        ag_p1 = ag_p1->next;
                                                    printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", i + 1, ag_p1->Number, ag_p1->Name, ag_p1->Account, ag_p1->phone_n);
                                                }
                                                printf("�س��Լ���\n");
                                                getchar();
                                                choose();
                                            }
                                        break;
                                    }
                                    case 2://ɾ����Դ
                                    {
                                        printf("������ϣ��ɾ���ķ�����ţ����10���ַ�����");
                                        scanf("%s", input_string);
                                        tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 4);
                                        if (*tempIntPtr == 0)
                                        {
                                            printf("����ң����ǵ�Ӧ��û�з����á�");
                                            printf("�س��Լ���");
                                            getchar();
                                            choose();
                                            break;
                                        }
                                        tempIntPtr++;
                                        int t = 0;//ɾ�����������
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
                                        jug5 = 0;//��ʼ��
                                        printf("����Ϣ�Ѿ�ɾ��\n");
                                        printf("Ŀǰ��%d����Դ\n", fl_number);
                                        printf("���»س��Լ���\n");
                                        getchar();
                                        choose();
                                        break;
                                    }
                                    case 3://���ӷ�Դ
                                    {//�˴�����������Ϊ�����ֲ�����
                                        int input_number;
                                        printf("���������ӷ�Դ������");
                                        scanf("%d", &input_number);
                                        fl_number = fl_number + input_number;
                                        printf("�밴�ճ���/���/��/��/����/¥��/���˳������\n");
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
                                            printf("��Ϣ¼��ɹ�\n");
                                            printf("Ŀǰ��%d����Դ\n", fl_number);
                                            printf("���»س��Լ���\n");
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
                    case 2://��������
                        //ʩ����
                        printf("*********��������*********\n");
                        printf("**                      **\n");
                        printf("**0.     ��    ��       **\n");
                        printf("**1.   ԤԼ��Ϣ����     **\n");
                        printf("**2.   ԤԼ��Ϣ��ѯ     **\n");
                        printf("**                      **\n");
                        printf("**************************\n");
                        scanf("%d", &choice_2);
                        switch (choice_2)
                        {
                        case 0:
                            break;
                        case 1:
                            printf("����������Ҫ�����ԤԼ��Ϣ:");
                            memset(input_string, 0, sizeof(input_string));
                            scanf("%s", input_string);
                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                            if (*tempIntPtr == 0)
                            {
                                printf("�Ҳ�����ԤԼ��Ϣ");
                                printf("�س��Լ���");
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
                                printf("�ɹ��ҵ�����\n");
                                printf("���\t\tʱ��\t\t���\t\t��Դ���\n");
                                printf("%s\t%d:%d:%d\t%s\t\t%s\n", ap_p->Number, ap_p->year,ap_p->month,ap_p->day, ap_p->custom->Account, ap_p->flat->number);
                                printf("*********ԤԼ��Ϣ*********\n");
                                printf("**                      **\n");
                                printf("**0.     ��    ��       **\n");
                                printf("**1.     ɾ    ��       **\n");
                                printf("**2.     �޸�ʱ��       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &choice_2);
                                switch (choice_2)
                                {
                                case 0:
                                    break;
                                    
                                case 1:
                                    printf("��ȷ��Ҫɾ����ԤԼ��Ϣ��1ȷ�� 2ȡ����");
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
                                    printf("ɾ���ɹ���\n");
                                    printf("�س��Լ���\n");
                                    getchar();
                                    choose();
                                    break;
                                case 2:
                                {
                                    printf("��������ʱ�䣨�� �� �գ�:");
                                    year, month, day;
                                    scanf("%d%d%d", &year, &month, &day);
                                    time_t now = time(NULL);
                                    struct tm* local = localtime(&now);
                                    if (year < local->tm_year || (year == local->tm_year && month < local->tm_mon) || (year == local->tm_year && month == local->tm_mon && day < local->tm_mday))
                                        printf("��Ч��ʱ��\n");
                                    else
                                    {
                                        ap_p->year = year;
                                        ap_p->month = month;
                                        ap_p->day = day;
                                        printf("�޸ĳɹ���\n");
                                    }
                                }
                                    printf("�س��Լ���\n");
                                    getchar();
                                    choose();
                                    break;
                                }
                                jug6 = 0;
                                jug5 = 0;//��ʼ��
                            }
                            else
                                if (*(tempIntPtr - 1) == 0)
                                {
                                    printf("�Ҳ�������������ݡ�\n");
                                    printf("���»س��Լ���\n");
                                    getchar();
                                    choose();
                                }
                                else
                                {
                                    printf("����������ݱȽ�ģ����Ϊ���ҵ���������\n");
                                    printf("���\t\tʱ��\t\t���\t\t��Դ���\n");
                                    for (int i = 0; i < *(tempIntPtr - 1); i++)
                                    {
                                        ap_p = ap_head->next;
                                        for (int j = 0; j < *(tempIntPtr + i); j++)
                                            ap_p = ap_p->next;
                                        printf("%s\t%d:%d:%d\t%s\t\t%s\n", ap_p->Number, ap_p->year, ap_p->month, ap_p->day, ap_p->custom->Account, ap_p->flat->number);
                                    }
                                    printf("�س��Լ���\n");
                                    getchar();
                                    choose();
                                }
                            free(tempIntPtr - 1);
                            tempIntPtr = NULL;
                            break;
                        case 2:
                            printf("��������Ϣ:");
                            memset(input_string, 0, sizeof(input_string));
                            scanf("%s", input_string);
                            tempIntPtr = string_seach(input_string, ag_head, cu_head, fl_head, ap_head, 1);
                            if (*tempIntPtr == 0)
                            {
                                printf("�Ҳ�����ԤԼ��Ϣ");
                                printf("�س��Լ���");
                                getchar();
                                choose();
                                break;
                            }
                            tempIntPtr++;
                            if (*(tempIntPtr - 1) == 0)
                            {
                                printf("�Ҳ�������������ݡ�\n");
                                printf("���»س��Լ���\n");
                                getchar();
                                choose();
                            }
                            else
                            {
                                printf("Ϊ���ҵ���������\n");
                                printf("���\t\tʱ��\t\t���\t\t��Դ���\n");
                                for (int i = 0; i < *(tempIntPtr - 1); i++)
                                {
                                    ap_p = ap_head->next;
                                    for (int j = 0; j < *(tempIntPtr + i); j++)
                                        ap_p = ap_p->next;
                                    printf("%s\t%d:%d:%d\t%s\t\t%s\n", ap_p->Number, ap_p->year, ap_p->month, ap_p->day, ap_p->custom->Account, ap_p->flat->number);
                                }
                                printf("�س��Լ���\n");
                                getchar();
                                choose();
                            }
                            free(tempIntPtr - 1);
                            tempIntPtr = NULL;
                            break;
                        }
                        break;
                    case 3://��Ϣ��ѯ
                   
                            printf("*********��ѯ��ʽ*********\n");
                            printf("**                      **\n");
                            printf("**0.     ��    ��       **\n");
                            printf("**1.     ��Χ����       **\n");
                            printf("**2.     �������       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            scanf("%d", &choice_6);
                            choose();
                            switch (choice_6)
                            {
                            case 0:
                              break;
                            case 1:
                                printf("*********��ѯ��ʽ*********\n");
                                printf("**                      **\n");
                                printf("**1.     ��    ��       **\n");
                                printf("**2.     ¥    ��       **\n");
                                printf("**3.     ��    ��       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &choice_6);
                                choose();
                                int left = 0;
                                int right = 0;

                                printf("*********����ʽ*********\n");
                                printf("**                      **\n");
                                printf("**1.     ��С����       **\n");
                                printf("**2.     �Ӵ�С       **\n");
                                printf("**                      **\n");
                                printf("**************************\n");
                                scanf("%d", &jug7);
                                printf("���������ҷ�Χ:\n");
                                printf("��:");
                                scanf("%d", &left);
                                printf("\n��:");
                                scanf("%d", &right);
                                choose();
                                int t;
                                t=range_search_Area(left, right, fl_head, fl_tail, choice_6, jug7);
                                printf("����%d�䷿�ӷ��ϱ�׼\n",t);
                                printf("���»س��Լ���\n");
                                getchar();
                                choose();
                                break;
                            case 2:
                                printf("*********��ѯ��ʽ*********\n");
                                printf("**                      **\n");
                                printf("**1.     ��    ��       **\n");
                                printf("**2.     ��    ��       **\n");
                                printf("**3.     ��    ��       **\n");
                                printf("**4.     ��    ��       **\n");
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
                    case 4://��Ϣ�������
                        //ʩ����
                        printf("*********�鿴��Դ*********\n");
                        printf("**                      **\n");
                        printf("**0.     ��    ��       **\n");
                        printf("**1.     ��    ��       **\n");
                        printf("**2.     ��    ��       **\n");
                        printf("**3.     �������       **\n");
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
                            printf("*********����ʽ*********\n");
                            printf("**                      **\n");
                            printf("**1.     ��С����       **\n");
                            printf("**2.     �Ӵ�С       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            scanf("%d", &jug7);
                            choose();
                            list_printfl(fl_head, fl_tail, jug7);
                            printf("���»س��Լ���\n");
                            getchar();
                            choose();
                            break;
                        }
                    case 5://��Ϣͳ��
                        //�깤
                        printf("��������������û�н��뻥����\n");
                        printf("����Ա������%d\n", countNumberAD(ad_head));
                        printf("�н���Ա������%d\n", countNumberAG(ag_head));
                        printf("�����Ա������%d\n", countNumberCU(cu_head));
                        printf("��Դ������%d\n", countNumberFL(fl_head));
                        printf("ԤԼ������%d\n", countNumberAP(ap_head));
                        printf("���»س��Լ���\n");
                        choose();
                        break;
                    case 6:
                        while (1)
                        {
                            memset(input_key, 0, sizeof(input_key));
                            memset(input_key_2, 0, sizeof(input_key_2));
                            printf("���������룺");
                            scanf("%s", input_key);
                            printf("��ȷ�����룺");
                            scanf("%s", input_key_2);
                            if (!strcmp(input_key, input_key_2))
                            {
                                strcpy(ad_p1->Key, input_key);
                                printf("�޸ĳɹ�!\n");
                                printf("�س��Լ���\n");
                                getchar();
                                choose();
                                break;
                            }
                            else
                            {
                                printf("�������벻һ������");
                                printf("�س��Լ���");
                                getchar();
                                choose();
                                break;
                            }
                        }
                        break;
                    case 7://����������
                        build_invitation = radom_string(19);
                        if (build_invitation == NULL)
                            return -1;
                        printf("�µ�������Ϊ��%s\n", build_invitation);
                        printf("�س��Լ���\n");
                        strcpy(ad_p1->invitation, build_invitation);
                        ad_p1->effective = 1;
                        free(build_invitation);
                        choose();
                        break;
                    case 8:
                        if (ad_p1->prev->prev == NULL && ad_p1->next == NULL)
                        {
                            printf("�������һ������Ա����ɾ���ֵ�\n");
                            printf("�س��Լ���");
                            getchar();
                            choose();
                            break;
                        }
                        printf("��ȷ��Ҫɾ�������˻���1ȷ�� 2ȡ����");
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
                            printf("�����ɹ�\n");
                            printf("�س��Լ���");
                            getchar();
                            choose();
                        }
                        break;
                    }
                   
                }
                break;
            case 2://�н�
                printf("�������˻���account����");
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
                        printf("���������루key��:");
                        scanf("%s", input_key);
                        if (!strcmp(input_key, ag_p1->Key))
                        {
                            printf("��¼�ɹ�����ӭ���н�Ա��%s\n", ag_p1->Name);
                            printf("�س��Լ���\n");
                            getchar();
                            jug = 1;
                            choose();
                        }
                        else
                        {
                            printf("�������\n");
                            printf("�س��Լ���\n");
                            getchar();
                            jug = 0;
                            choose();
                        }
                        break;
                    }
                    ag_p1 = ag_p1->next;
                    if (ag_p1 == NULL)
                    {
                        printf("�Ҳ�������\n");
                        printf("�س��Լ���\n");
                        getchar();
                        jug = 0;
                        choose();
                        break;
                    }
                }
                while (jug)
                {
                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ע    ��       **\n");
                    printf("**1.     ��������       **\n");
                    printf("**2.     �ⷿ����       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_3);
                    choose();
                    switch (choice_3)
                    {
                    case 0:
                        jug = 0;
                        ag_p1 = ag_tail;
                        break;
                    case 1:
                        //������
                        break;
                    case 2:
                        //������
                        break;
                    case 3:
                        //������
                        break;
                    case 4:
                        //������
                        break;
                    case 5:
                        //������
                        break;
                    case 6:
                        //������
                        break;

                    }
                }
                break;
            case 3://���
                printf("�������˻���account����");
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
                        printf("���������루key��:");
                        scanf("%s", input_key);
                        if (cu_p1->statment == 0)
                        {
                            printf("��Ǹ������ΪΥ�����ǵ��������������������������ϵ����Ա\n");
                            printf("�س��Լ���");
                            getchar();
                            choose();
                            jug = 0;
                            break;
                        }
                        if (!strcmp(input_key, cu_p1->Key))
                        {
                            printf("��¼�ɹ�����ӭ���װ���%s\n", cu_p1->Account);
                            printf("�س��Լ���\n");
                            getchar();
                            jug = 1;
                            choose();
                        }
                        else
                        {
                            printf("�������\n");
                            printf("�س��Լ���\n");
                            getchar();
                            jug = 0;
                            choose();
                        }
                        break;
                    }
                    cu_p1 = cu_p1->next;
                    if (cu_p1 == NULL)
                    {
                        printf("�Ҳ�������\n");
                        printf("�س��Լ���\n");
                        getchar();
                        jug = 0;
                        choose();
                        break;
                    }
                }
                while (jug)
                {
                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ע    ��       **\n");
                    printf("**1.     ������Ϣ       **\n");
                    printf("**2.     ����ԤԼ       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_4);
                    choose();
                    switch (choice_4)
                    {
                    case 0:
                        jug = 0;
                        cu_p1 = cu_tail;
                        break;
                    case 1:
                        //������
                        break;
                    case 2:
                        //������
                        break;
                    case 3:
                        //������
                        break;
                    case 4:
                        //������
                        break;
                    case 5:
                        //������
                        break;
                    case 6:
                        //������
                        break;

                    }
                }
                break;
            }
            break;
        case 2:
            printf("******���ѡ��******\n");
            printf("**                **\n");
            printf("**0.  ��    ��    **\n");
            printf("**1.  �� �� Ա    **\n");
            printf("**2.  ��    ��    **\n");
            printf("**3.  ��    ��    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("��ѡ����ݣ�");
            scanf_s("%d", &choice_5);
            choose();
            switch (choice_5)
            {
            case 1:
                printf("�����������룺");
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
                        printf("�������˻�����20���ַ���");
                        scanf("%s", input_account);
                        ad_p1 = ad_head->next;
                        while (1)
                        {
                            if (ad_p1 == NULL)
                            {
                                printf("���������룺");
                                scanf("%s", input_key);
                                printf("��ȷ�����룺");
                                scanf("%s", input_key_2);
                                if (!strcmp(input_key, input_key_2))
                                {
                                    ad_p2->effective = 0;
                                    extendAdmin(input_account, input_key, ad_p1, ad_p2, ad_tail);
                                    ad_tail = ad_tail->next;
                                    ad_p2 = ad_tail;
                                    ad_p1 = ad_tail;
                                    printf("ע��ɹ���");
                                    printf("�س��Լ���");
                                    getchar();
                                    choose();
                                    jug2 = 0;
                                    jug3 = 0;
                                    break;
                                }
                                else
                                {
                                    printf("�������벻һ������");
                                    printf("�س��Լ���");
                                    getchar();
                                    choose();
                                    ad_p1 = ad_head->next;
                                    break;
                                }
                            }
                            if (!strcmp(input_account, ad_p1->Account))
                            {
                                ad_p1 = ad_head->next;
                                printf("���û��Ѿ�����\n");
                                printf("���س��Լ���\n");
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
                            printf("��Ч����ڵĵ�������!\n");
                            printf("�س��Լ���\n");
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
                printf("�����������룺");
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
                        printf("������绰���룺(11λ)");
                        scanf("%s", input_phonenumber);
                        while (strlen(input_phonenumber) != 11)
                        {
                            choose();
                            printf("��Ч�ĵ绰���룡\n");
                            printf("��������ȷ�ĵĵ绰����:");
                            memset(input_phonenumber, 0, sizeof(input_phonenumber));
                            scanf("%s", input_phonenumber);
                        }
                        printf("�������˻�����20���ַ���");
                        scanf("%s", input_account);
                        ag_p1 = ag_head->next;
                        while (1)
                        {
                            if (ag_p1 == NULL)
                            {
                                printf("���������룺");
                                scanf("%s", input_key);
                                printf("��ȷ�����룺");
                                scanf("%s", input_key_2);
                                if (!strcmp(input_key, input_key_2))
                                {
                                    ad_p2->effective = 0;
                                    extendAgency(input_account, input_key, ag_p1, ag_head, ag_tail);
                                    ag_tail = ag_tail->next;
                                    ag_p2 = ag_tail;
                                    ag_p1 = ag_tail;
                                    strcpy(ag_p1->phone_n, input_phonenumber);
                                    printf("ע��ɹ���\n");
                                    printf("���ı��Ϊ%s\n", ag_p1->Number);
                                    printf("����������������");
                                    scanf("%s", ag_p1->Name);
                                    printf("�س��Լ���\n");
                                    getchar();
                                    choose();
                                    jug2 = 0;
                                    jug3 = 0;
                                    break;
                                }
                                else
                                {
                                    printf("�������벻һ������");
                                    printf("�س��Լ���");
                                    getchar();
                                    choose();
                                    ag_p1 = ag_head->next;
                                    break;
                                }
                            }
                            if (!strcmp(input_account, ag_p1->Account) || !strcmp(input_phonenumber, ag_p1->phone_n))
                            {
                                ag_p1 = ag_head->next;
                                printf("���û��Ѿ�����\n");
                                printf("���س��Լ���\n");
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
                            printf("��Ч����ڵĵ�������!\n");
                            printf("�س��Լ���\n");
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
                    printf("������绰���룺(11λ)");
                    scanf("%s", input_phonenumber);
                    while (strlen(input_phonenumber) != 11)
                    {
                        choose();
                        printf("��Ч�ĵ绰���룡\n");
                        printf("��������ȷ�ĵĵ绰����:");
                        memset(input_phonenumber, 0, sizeof(input_phonenumber));
                        scanf("%s", input_phonenumber);
                    }
                    printf("�������˻�����20���ַ���");
                    scanf("%s", input_account);
                    cu_p1 = cu_head->next;
                    while (1)
                    {
                        if (cu_p1 == NULL)
                        {
                            printf("���������룺");
                            scanf("%s", input_key);
                            printf("��ȷ�����룺");
                            scanf("%s", input_key_2);
                            if (!strcmp(input_key, input_key_2))
                            {
                                extendCustomer(input_account, input_key, cu_p1, cu_p2, cu_tail);
                                cu_tail = cu_tail->next;
                                cu_p2 = cu_tail;
                                cu_p1 = cu_tail;
                                strcpy(cu_p1->phone_n, input_phonenumber);
                                printf("ע��ɹ���\n");

                                printf("����������������");
                                scanf("%s", cu_p1->Name);
                                printf("�س��Լ���\n");
                                getchar();
                                choose();
                                jug2 = 0;
                                break;
                            }
                            else
                            {
                                printf("�������벻һ������");
                                printf("�س��Լ���");
                                getchar();
                                choose();
                                cu_p1 = cu_head->next;
                                break;
                            }
                        }
                        if (!strcmp(input_account, cu_p1->Account) || !strcmp(input_phonenumber, cu_p1->phone_n))
                        {
                            cu_p1 = cu_head->next;
                            printf("���û��Ѿ�����\n");
                            printf("���س��Լ���\n");
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
static void choose()//��������
{
    char wait;
    //getchar();             //��'\n'
    scanf("%c", &wait);
    if (wait == '\n')
        system("cls");
    else
        choose();
}