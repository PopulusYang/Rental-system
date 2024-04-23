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
*����log.c
*************/
void logError(int kind);
void logInfo(int kind);
void logWarning(int kind);

/***********************
����information_search.c
************************/


int* string_seach(char* input, struct Agency* ah, struct Customer* ch, struct Flat* fh, struct Appointment* aph, int kind);

int toward_search(list_1 mylist_head, int i);//�������

//�����������н�ķ���
int toward_search_cu(list_1 mylist_head, int i);
//��������û���н�ķ���
int toward_search_ag(list_1 mylist_head, int i);

//��Χ�������н�ķ���
int range_search_cu(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2);
//��Χ����û���н�ķ���
int range_search_ag(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2);
/*********
����sort.c
**********/


//��������ð��)(���������
void bubbleSort_Area(Flat** head, int jug);

/***************
����listwriting
***************/

//ɾ���ض�����
int DelListall(list_1 mylist, int t); //iΪɾ�������
//�ӳ�Customer����
int extendCustomer(char* Account, char* key, struct Customer* p1, struct Customer* p2, struct Customer* tail);
//�ӳ�Agency����
int extendAgency(char* Account, char* key, struct Agency* p1, struct Agency* head, struct Agency* tail);
//�ӳ�Admin����
int extendAdmin(char* Account, char* key, struct Admin* p1, struct Admin* p2, struct Admin* tail);
//�ӳ�Flat����д��
int extend_writeFlat(list_1 p1, list_1 head, list_1 tail, char* city, float area, int t, int floor, float rent, int shi, int ting,struct Agency* ag);
//���ķ�����Ϣ
int fl_change(list_1 fl_p1);
//���Ҳ���������һ����Χ�ڵķ�����Ϣ
//l��rΪ���Ҷ˵�
//jugΪ����or����
int range_search_Area(int l, int r, Flat* mylist_head, list_1 mylist_tail, int jug, int jug2);//�Է������Ϊ����
//�ӳ�extendApm����
int extendApm(struct Appointment* p, struct Appointment* tail, struct Appintment* head, int year, int month, int day, struct Flat* flat, struct Customer* custom);


/***********
����others.c
************/


//nΪ�ַ�����,�����ַ�����ַ
char* radom_string(int n);

//nΪ���ָ���,�����ַ�����ַ
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
����color.c
***********/
void color(short x);
void loading();

/************
����output.c
************/

//�������
int list_printfl(list_1 mylist_head, list_1 mylist_tail, int judge);//��ӡ����

//��ӡ���н�ķ���
int list_printfl_ag(list_1 mylist_head, list_1 mylist_tail, int judge);
//��ӡû���н�ķ���
int list_printfl_cu(list_1 mylist_head, list_1 mylist_tail, int judge);
/************
����filecach.h
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
