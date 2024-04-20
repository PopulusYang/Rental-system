#include "list.h"
#include "temphead.h"


//文件读写功能
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
	//似乎完工了
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
	//似乎完工了
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

	fclose(fp);
	return true;
}