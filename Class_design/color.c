#include <stdio.h>
#include<Windows.h>

//�ֲ�����ı���ɫ
void color(short x)
{
    if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
    else//Ĭ�ϵ���ɫ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//0-15��ɫ�ֱ�Ϊ����ɫ/����/��ɫ/ǳ��/���/��ɫ/����/��ɫ��0-7��
//                ��ɫ/����/����/��ɫ/ǳ��/����/����/���ף�8-15)
void loading()
{
    int i, j = 0;
    printf("���ڶ�ȡ������...\n");
    for (i = 0; i <= 15; i++)
    {
        color(i);
        for (j = 0; j < i; j++)
        {
            printf("=");
        }
        printf(">");
        fflush(stdout);
        Sleep(1);
        printf("\r");
    }
    color(7);
    printf("\n");
}