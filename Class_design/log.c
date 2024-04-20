//»’÷æ
#include"temphead.h"

void logError(int kind)
{
	switch (kind)
	{
	case 0:
		color(4);
		printf("[ERROR]A pointer points to NULL.Please check the log.");
		color(7);
		break;
	case 1:

		break;
	}
}

void logInfo()
{

}

void logWarning()
{

}