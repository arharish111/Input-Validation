#include <stdio.h>
#include <string.h>

#include "argument_check.h"

int checkForCorrectArguments(int numberOfArgs,char **arguments)
{
	int result;
	switch(numberOfArgs)
	{
		case 1:
		{
			printErrorMessage();
			result = 0;
			break;
		}
		case 2:
		{
			if(!strcmp("LIST",arguments[1]))
			{
				result = 1;
			}
			else
			{
				printErrorMessage();
				result = 0;
			}
			break;
		}
		case 3:
		{
			if(!strcmp("DEL",arguments[1]))
			{
				result = 1;
			}
			else
			{
				printErrorMessage();
				result = 0;
			}
			break;
		}
		case 4:
		{
			if(!strcmp("ADD",arguments[1]))
			{
				result = 1;
			}
			else
			{
				printErrorMessage();
				result = 0;
			}
			break;
		}
		default:
		result = 0;
		break;
	}
	return result;
}

void printErrorMessage()
{
	printf("Wrong Input.\nCorrect Usage:\n<executable name> <mode> <arguments>\nLIST mode does not require any arguments");
}