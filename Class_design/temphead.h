#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "list.h"
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <time.h> 
#include<Windows.h>
#include<assert.h>
#include <stdbool.h>
typedef struct Flat Flat, * list_1;


/*********
*来自log.c
*************/
void logError(int kind);
void logInfo(int kind);
void logWarning(int kind);

/***********************
来自information_search.c
************************/


int* string_seach(char* input, struct Agency* ah, struct Customer* ch, struct Flat* fh, struct Appointment* aph, int kind);

int toward_search(list_1 mylist_head, int i);//朝向查找

//朝向搜索有中介的房产
int toward_search_cu(list_1 mylist_head, int i);
//朝向搜索没有中介的房产
int toward_search_ag(list_1 mylist_head, int i);

//范围搜索有中介的房产
int range_search_cu(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2);
//范围搜索没有中介的房产
int range_search_ag(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2);
/*********
来自sort.c
**********/


//链表排序（冒泡)(房子面积）
void bubbleSort_Area(Flat** head, int jug);

/***************
来自listwriting
***************/

//删除特定数据
int DelListall(list_1 mylist, int t); //i为删除的序号
//延长Customer链表
int extendCustomer(char* Account, char* key, struct Customer* p1, struct Customer* p2, struct Customer* tail);
//延长Agency链表
int extendAgency(char* Account, char* key, struct Agency* p1, struct Agency* head, struct Agency* tail);
//延长Admin链表
int extendAdmin(char* Account, char* key, struct Admin* p1, struct Admin* p2, struct Admin* tail);
//延长Flat链表并写入
int extend_writeFlat(list_1 p1, list_1 head, list_1 tail, char* city, float area, int t, int floor, float rent, int shi, int ting,struct Agency* ag);
//更改房产信息
int fl_change(list_1 fl_p1);
//查找操作，查找一个范围内的房产信息
//l和r为左右端点
//jug为正序or倒序
int range_search_Area(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2);//以房产面积为例子
//延长extendApm链表
int extendApm(struct Appointment* p, struct Appointment* tail, struct Appintment* head, int year, int month, int day, struct Flat* flat, struct Customer* custom);


/***********
来自others.c
************/


//n为字符个数,返回字符串地址
char* radom_string(int n);

//n为数字个数,返回字符串地址
char* radom_number(int n);

int checkRecurFL(char* num, struct Flat* head);
int checkRecurAG(char* num, struct Agency* aghead);
int checkRecurAP(char* num, struct Appointment* aphead);

int countNumberAD(struct Admin* head);

int countNumberFL(struct Flat* head);

int countNumberAG(struct Agency* head);

int countNumberCU(struct Customer* head);

int countNumberAP(struct Appointment* head);


void removeDuplicates(int* arr, int* length);
/**********
来自color.c
***********/
void color(short x);
void loading();

/************
来自output.c
************/

//输出房痔
int list_printfl(list_1 mylist_head, list_1 mylist_tail, int judge);//打印链表

//打印有中介的房产
int list_printfl_ag(list_1 mylist_head, list_1 mylist_tail, int judge);
//打印没有中介的房产
int list_printfl_cu(list_1 mylist_head, list_1 mylist_tail, int judge);
/************
来自filecach.h
*************/

bool filecachAD_write(struct Admin* head);
bool filecachAD_read(struct Admin** tailp);

bool filecachAG_write(struct Agency* head);
bool filecachAG_read(struct Agency** tailp);

bool filecachCU_write(struct Customer* head);
bool filecachCU_read(struct Customer** tailp);

bool filecachFL_write(struct Flat* head);
bool filecachFL_read(struct Flat** tailp, struct Agency* head, struct Customer* chead);

bool filecachAP_write(struct Appointment* head);
bool filecachAP_read(struct Appointment** tailp, struct Customer* chead, struct Flat* fhead);
