#pragma once
#include "temphead.h"
#include <stdbool.h>
#pragma warning(disable:6031) 
typedef struct Flat Flat, * list_1;
//链表声明
enum Toward//朝向，包括东南西北东南东北西南西北
{
    E = 1, S, W, N, SE, NE, SW, NW
};

struct Admin//管理员
{
    char Account[20];
    char Key[20];
    struct Admin* prev;
    struct Admin* next;
    char invitation[20];//邀请码，每个管理员限有一个
    int effective;//邀请码的有效性
};

struct Agency//中介
{
    char Account[20];//中介ID直接作为其账户
    char phone_n[12];
    char Key[20];//密码
    char Name[50];//姓名
    char Number[9];
    struct Agency* prev;
    struct Agency* next;
};

struct Customer//租客
{
    char Account[20];
    char Key[20];
    char phone_n[12];
    char Name[50];//姓名
    struct Customer* prev;
    struct Customer* next;
    int statment;
};

struct Flat//房痔
{
    struct Flat* prev;
    struct Flat* next;
    float Area;//面积
    char city[20];//所在位置
    char number[9];//编号
    enum Toward toward;//朝向
    int shi;
    int ting;//几室几厅
    int floor;//在几楼
    float rent, agency_fee, deposit;//费用，包括租金、中介费、押金
    struct Agency* agency;//中介
    char agposition[9];
    bool statment;
};


struct Appointment//预约
{
    struct Appointment* next;
    struct Appointment* prev;
    int year;
    int month;
    int day;
    char Number[9];
    struct Customer* custom;
    struct Flat* flat;
    char cuposition[20];
    char flposition[9];
};
