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
