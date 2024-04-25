//ÈÕÖ¾
#include"temphead.h"

void logError(int kind)
{
	time_t now = time(NULL);
	struct tm* local = localtime(&now);
	FILE* fp;
	fp = fopen("log.txt", "a");
	char tempstr[20] = { 0 };
	sprintf(tempstr, "%d-%d-%d %d:%d:%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
	fputs(tempstr, fp);
	switch (kind)
	{
	case 0:
		color(4);
		printf("[ERROR]A pointer points to NULL.Please check the log.\n");
		color(7);
		char temp[] = "[ERROR]A pointer points to NULL.\n";
		fputs(temp,fp);
		fclose(fp);
		break;
	case 2:
	{
		char temp[] = "[ERROR]Can't open the file!\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	}
	exit(-1);
}

void logInfo(int kind)
{
	time_t now = time(NULL);
	struct tm* local = localtime(&now);
	FILE* fp;
	fp = fopen("log.txt", "a");
	char tempstr[20] = { 0 };
	sprintf(tempstr, "%d-%d-%d %d:%d:%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
	fputs(tempstr, fp);
	switch (kind)
	{
	case 1:
	{
		char temp[] = "[Info]A user logged in.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 2:
	{
		char temp[] = "[Info]A user logged out.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 3:
	{
		char temp[] = "[Info]A user has registered.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 4:
	{
		char temp[] = "[Info]A user deleted it.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 5:
	{
		char temp[] = "[Info]The file has been modified.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 6:
	{
		char temp[] = "[Info]Search successful.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	}
}

void logWarning(int kind)
{
	time_t now = time(NULL);
	struct tm* local = localtime(&now);
	FILE* fp;
	fp = fopen("log.txt", "a");
	char tempstr[20] = { 0 };
	sprintf(tempstr, "%d-%d-%d %d:%d:%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
	fputs(tempstr, fp);
	switch (kind)
	{
	case 1:
	{
		char temp[] = "[Warn]Search failed.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	case 2:
	{
		char temp[] = "[Warn]User login failed.\n";
		fputs(temp, fp);
		fclose(fp);
		break;
	}
	}
}