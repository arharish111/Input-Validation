#include <stdio.h>
#include <regex.h>
#include <sys/types.h>
#include "validation.h"
#include <stdlib.h>

int validateName(char* name)
{
	//printf("Here in name\n");
	regex_t *namePattern = (regex_t*)malloc(sizeof(namePattern));
    int result;
    char *regex = (char*)malloc(sizeof(regex));
    regex = "^[A-Z]((['][A-Z][a-z]*)|([a-z]*))(([,])? [A-Z]((['][A-Z][a-z]*)|([a-z]*))( |-)?([A-Z]([a-z]*|[.]))?)?$";
    result = regcomp(namePattern,regex,REG_EXTENDED);
    if(result==0)
    {
        //printf("Done");
        result = regexec(namePattern,name,0,NULL,0);
        if(result==0)
        {
            //printf("Accept");
        }
        else
        {
			//fprintf(stderr,"%s\n","Invalid Input");
			regfree(namePattern);
			//free(regex);
			return 0;
        }
    }
    else
    {
        printf("error");
		regfree(namePattern);
		//free(regex);
		return 0;
    }
	regfree(namePattern);
	//free(regex);
	return 1;
}
int validateNumber(char* number)
{
	regex_t *numberPattern = (regex_t*)malloc(sizeof(numberPattern));
    int result;
    char *numberRegex = (char*)malloc(sizeof(numberRegex));
    numberRegex = "^(([0-9]{5}([.][0-9]{5})?)|([0-9]{3}([-][0-9]{4})|([0-9]{3} [0-9]{1} [0-9]{3} [0-9]{3} [0-9]{4})|([0-9]{3} [0-9]{3} [0-9]{3} [0-9]{4})))$";
    result = regcomp(numberPattern,numberRegex,REG_EXTENDED);
    if(result==0)
    {
        //printf("Done1");
        result = regexec(numberPattern,number,0,NULL,0);
        if(result==0)
        {
            //printf("Accept1");
        }
        else
        {
            regex_t *pattern1 = (regex_t*)malloc(sizeof(pattern1));
            numberRegex = "^(([+]?[0-9]{1})?[(][0-9]{3}[)][0-9]{3}[-][0-9]{4})|[+][0-9]{2} [(][0-9]{2}[)] [0-9]{3}[-][0-9]{4}$";
            result = regcomp(pattern1,numberRegex,REG_EXTENDED);
            //printf("\n%d",result);
            if(result==0)
            {
                //printf("Done2");
                result = regexec(pattern1,number,0,NULL,0);
                if(result==0)
                {
                    //printf("Accept2");
					regfree(pattern1);
                }
                else
                {
                    //fprintf(stderr,"%s\n","Invalid Input");
					regfree(pattern1);
					return 0;
                }
            }
            else
            {
                printf("error2");
				regfree(pattern1);
				return 0;
            }
        }
    }
    else
    {
        printf("error1");
		return 0;
    }
	regfree(numberPattern);
	return 1;
}