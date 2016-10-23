#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERSION_NUMBER "1.0.1a"

/*massives*/
/*func prototypes*/

void FlagValidator(const int const flagCount,const char * const flagValues[]);
void helpCmd(void);
void versionCmd(void);
void InvokeCommand(const int const amount, const char * const command[]);
/*****************/

const char * const AllowedFlags[] ={"--help","--version"};

void (*CommandStore[])(void) = {helpCmd, versionCmd};

const int AllowedFlagsCount = sizeof(AllowedFlags) / sizeof(AllowedFlags[0]);


/*****!-MAIN FUNCTION-!*****/
int main(const int const argc,const char * const argv[])
{

	if(argc > 1) FlagValidator(argc,argv);
	else 
	{
		printf("No flags has been recieved\tterminating.\nHave a good day:)\n");
		exit(EXIT_SUCCESS);
	}
	InvokeCommand(argc,argv);


}
/*****!-MAIN FUNCTION-!*****/


/*ALL-OTHER-FUNCTIONS*/

void FlagValidator(const int const flagCount,const char * const flagValue[])
{
	int incorrectFlagIndex = -1;
		for(int i = 1;i < flagCount; i++)
		{
			for(int j = 0;j < AllowedFlagsCount; j++)
			{
				if(strcmp(flagValue[i],AllowedFlags[j]) == 0)
				{
					incorrectFlagIndex = -1;
					break;
				} else incorrectFlagIndex = i;
			}
		}
	if(incorrectFlagIndex > -1)
		{
			printf("[-]Incorrect flag was given: [%s]\n[!]Please use --help to see available flags\n",flagValue[incorrectFlagIndex]);
			exit(EXIT_FAILURE);
		}
}

/*********************/

void helpCmd(void)
{
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	printf("---------!!!!!HELP!!!!!-----------\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
}

void versionCmd(void)
{
	printf("App version: %s\n", VERSION_NUMBER);
}

void InvokeCommand(const int const amount, const char * const command[])
{
	for(int i = 0;i < amount; i++)
	{
		for(int j = 0; j < AllowedFlagsCount; j++)
		{
			if(strcmp(command[i],AllowedFlags[j]) == 0)
			{
				CommandStore[j]();
			}
		}
	}
}