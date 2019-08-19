#include<stdio.h>
#include<string.h>
#include "operation_execution.h"
#include "database.h"
#include "validation.h"

int performOperationBasedOnMode(char **arguments)
{
	if(checkForDatabaseConnectionAndCreateTable())
	{
		if(!strcmp("ADD",arguments[1]))
		{
			if(validateName(arguments[2]) && validateNumber(arguments[3]))
			{
				return insertIntoDatabase(arguments[2],arguments[3]);
			}
			else
			{
				fprintf(stderr,"%s\n","Invalid Input");
				return 0;
			}
		}
		else if(!strcmp("DEL",arguments[1]))
		{
			if(validateName(arguments[2]))
			{
				return deleteEntryByName(arguments[2]);
			}
			else if(validateNumber(arguments[2]))
			{
				return deleteEntryByNumber(arguments[2]);
			}
			else
			{
				fprintf(stderr,"%s\n","Invalid Input");
				return 0;
			}
		}
		else if(!strcmp("LIST",arguments[1]))
		{
			if(displayList())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			fprintf(stderr,"%s\n","Invalid Input");
			return 0;
		}
	}
	else
	{
		return 0;
	}
}