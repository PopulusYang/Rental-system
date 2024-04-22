#pragma once
#include "temphead.h"
#include <stdbool.h>
#pragma warning(disable:6031) 
typedef struct Flat Flat, * list_1;
//��������
enum Toward//���򣬰��������������϶�����������
{
    E = 1, S, W, N, SE, NE, SW, NW
};

struct Admin//����Ա
{
    char Account[20];
    char Key[20];
    struct Admin* prev;
    struct Admin* next;
    char invitation[20];//�����룬ÿ������Ա����һ��
    int effective;//���������Ч��
};

struct Agency//�н�
{
    char Account[20];//�н�IDֱ����Ϊ���˻�
    char phone_n[12];
    char Key[20];//����
    char Name[50];//����
    char Number[9];
    struct Agency* prev;
    struct Agency* next;
};

struct Customer//���
{
    char Account[20];
    char Key[20];
    char phone_n[12];
    char Name[50];//����
    struct Customer* prev;
    struct Customer* next;
    int statment;
};

struct Flat//����
{
    struct Flat* prev;
    struct Flat* next;
    float Area;//���
    char city[20];//����λ��
    char number[9];//���
    enum Toward toward;//����
    int shi;
    int ting;//���Ҽ���
    int floor;//�ڼ�¥
    float rent, agency_fee, deposit;//���ã���������н�ѡ�Ѻ��
    struct Agency* agency;//�н�
    char agposition[9];
    bool statment;
};


struct Appointment//ԤԼ
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
