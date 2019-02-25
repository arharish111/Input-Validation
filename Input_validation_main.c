#include <stdio.h>

#include "argument_check.h"
#include "operation_execution.h"

int main(int nagrs,char **args)
{
	if(checkForCorrectArguments(nagrs,args))
	{
		performOperationBasedOnMode(args);
	}
	return 0;
}