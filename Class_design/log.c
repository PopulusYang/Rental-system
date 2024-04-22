//»’÷æ
#include"temphead.h"

void logError(int kind)
{
	switch (kind)
	{
	case 0:
		color(4);
		printf("[ERROR]A pointer points to NULL.Please check the log.\n");
		color(7);
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[ERROR]A pointer points to NULL.\n";
		fputs(temp,fp);
		fclose(fp);
		break;
	case 2:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[ERROR]Can't open the file!\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	}
}

void logInfo(int kind)
{
	switch (kind)
	{
	case 1:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Info]A user logged in.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 2:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Info]A user logged out.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 3:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Info]A user has registered.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 4:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Info]A user deleted it.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 5:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Info]The file has been modified.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 6:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Info]Search successful.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	}
}

void logWarning(int kind)
{
	switch (kind)
	{
	case 1:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Warn]Search failed.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 2:
	{
		FILE* fp;
		fp = fopen("log.txt", "a");
		char temp[] = "[Warn]User login failed.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	}
}