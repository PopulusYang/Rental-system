﻿#include "list.h"
#include "temphead.h"


bool filecachAD_write(struct Admin* head)
{
	FILE* fp;
	fp = fopen("admin.bin", "wb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Admin* p;
	p = head->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct Admin), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}
bool filecachAD_read(struct Admin** tailp)
{
	FILE* fp;
	fp = fopen("admin.bin", "rb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Admin* p;
	p = NULL;
	while (!feof(fp))
	{
		p = (struct Admin*)malloc(sizeof(struct Admin));
		assert(p);
		fread(p, sizeof(struct Admin), 1, fp);
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}
	assert(p);
	*tailp = p->prev;
	p->prev->next = NULL;
	free(p);
	p = NULL;
	fclose(fp);
	return true;
}

bool filecachAG_write(struct Agency* head)
{
	FILE* fp;
	fp = fopen("agency.bin", "wb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Agency* p;
	p = head->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct Agency), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}
bool filecachAG_read(struct Agency** tailp)
{
	FILE* fp;
	fp = fopen("agency.bin", "rb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Agency* p;
	p = NULL;
	while (!feof(fp))
	{
		p = (struct Agency*)malloc(sizeof(struct Agency));
		assert(p);
		fread(p, sizeof(struct Agency), 1, fp);
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}
	assert(p);
	*tailp = p->prev;
	p->prev->next = NULL;
	free(p);
	p = NULL;
	fclose(fp);
	return true;
}

bool filecachCU_write(struct Customer* head)
{
	FILE* fp;
	fp = fopen("customer.bin", "wb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Customer* p;
	p = head->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct Customer), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}
bool filecachCU_read(struct Customer** tailp)
{
	FILE* fp;
	fp = fopen("customer.bin", "rb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Customer* p;
	p = NULL;
	while (!feof(fp))
	{
		p = (struct Customer*)malloc(sizeof(struct Customer));
		assert(p);
		fread(p, sizeof(struct Customer), 1, fp);
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}
	assert(p);
	*tailp = p->prev;
	p->prev->next = NULL;
	free(p);
	p = NULL;
	fclose(fp);
	return true;
}

bool filecachFL_write(struct Flat* head)
{
	FILE* fp;
	fp = fopen("flat.bin", "wb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Flat* p;
	p = head->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct Flat), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}
bool filecachFL_read(struct Flat** tailp,struct Agency* head, struct Customer* chead)
{
	struct Agency* p1;
	struct Customer* p2;
	p1 = NULL;
	FILE* fp;
	fp = fopen("flat.bin", "rb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Flat* p;
	p = NULL;
	while (!feof(fp))
	{
		p = (struct Flat*)malloc(sizeof(struct Flat));
		assert(p);
		fread(p, sizeof(struct Flat), 1, fp);
		p1 = head->next;
		while (p1 != NULL)
		{
			if (!strcmp(p->agposition, p1->Number))
				break;
			p1 = p1->next;
		}
		p->agency = p1;
		p2 = chead->next;
		while (p2 != NULL)
		{
			if (!strcmp(p->cuposition, p2->Account))
				break;
			p2 = p2->next;
		}
		p->custome = p2;
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}
	assert(p);
	*tailp = p->prev;
	p->prev->next = NULL;
	free(p);
	p = NULL;
	fclose(fp);
	return true;
}

bool filecachAP_write(struct Appointment* head)
{
	FILE* fp;
	fp = fopen("appointment.bin", "wb");
	if (fp == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Appointment* p;
	p = head->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct Appointment), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}
bool filecachAP_read(struct Appointment** tailp, struct Customer* chead, struct Flat* fhead)
{
	struct Customer* cp = NULL;
	struct Flat* fp = NULL;
	FILE* file;
	file = fopen("appointment.bin", "rb");
	if (file == NULL)
	{
		printf("Can't open the file!\n");
		logError(2);
		return false;
	}
	struct Appointment* p;
	p = NULL;
	while (!feof(file))
	{
		p = (struct Appointment*)malloc(sizeof(struct Appointment));
		assert(p);
		fread(p, sizeof(struct Appointment), 1, file);
		cp = chead->next;
		while (cp != NULL)
		{
			if (!strcmp(p->cuposition, cp->Account))
				break;
			cp = cp->next;
		}				
		p->custom = cp;
		fp = fhead->next;
		while (fp != NULL)
		{
			if (!strcmp(p->flposition, fp->number))
				break;
			fp = fp->next;
		}			
		p->flat = fp;
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}
	assert(p);
	*tailp = p->prev;
	p->prev->next = NULL;
	free(p);
	p = NULL;
	fclose(file);
	return true;
}