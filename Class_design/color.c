#include <stdio.h>
#include<Windows.h>

//局部字体改变颜色
void color(short x)
{
    if (x >= 0 && x <= 15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
    else//默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//0-15颜色分别为：黑色/深蓝/绿色/浅蓝/深红/紫色/土黄/白色（0-7）
//                灰色/中蓝/亮绿/青色/浅红/亮紫/亮黄/亮白（8-15)
void loading()
{
    int i, j = 0;
    printf("正在读取数据中...\n");
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