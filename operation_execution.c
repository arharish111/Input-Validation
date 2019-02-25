#include<stdio.h>
#include<string.h>
#include "operation_execution.h"
#include "database.h"
#include "validation.h"

void performOperationBasedOnMode(char **arguments)
{
	if(checkForDatabaseConnectionAndCreateTable())
	{
		if(!strcmp("ADD",arguments[1]))
		{
			// if(validateName(arguments[2]))
			// {
				// validateNumber(arguments[3]);
			// }
			printf("inside ADD\n");
		}
		else if(!strcmp("DEL",arguments[1]))
		{
			
		}
	}
	
}