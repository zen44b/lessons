#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define APP_VERSION "0.1.1"

/*******functions*******/
void helpCommand(void);
void idiotCommand(void);
void versionCommand(void);

void InvokeCommands(const char * const commands[], const unsigned int count);

void ArgumentValidator(const int const amount,const char * const flags[]);
/***********************/
/*Approved for use flags*/
const char * const ValidFlags[] =	{"--version","--help","--idiot"}; //allowed flags

void(*commandStore[])(void) =		{ versionCommand , helpCommand , idiotCommand}; //maped functions (same names&order as allowed flags)

const int const ValidFlagsCount = sizeof ValidFlags / sizeof ValidFlags[0]; 
// massive of pointers to strings (char massives)[*][*][*] \ [*] //size of massive divide by one index size.


int incorrectFlagIndex = -1; //flag check status			


int main(const int const argc,const char * const argv[])
{
	//check if argv exists
	if(argc>1)ArgumentValidator(argc,argv);
		else {
			printf("No flags recieved.\n");
			exit(EXIT_SUCCESS);
		}

		InvokeCommands(argv,argc);

		return EXIT_SUCCESS;
}


void versionCommand(void)
{
	printf("App version: %s\n", APP_VERSION);
}

void helpCommand(void) //help print function
{
	printf("%s:\n\n\t\tDisplays the version of the programm\n",ValidFlags[0]);
	printf("%s:\n\n\t\tDisplays this message.\n",ValidFlags[1]);
	printf("%s:\n\n\t\tIdiot cloner with super option\n",ValidFlags[2]);

}
void idiotCommand(void)
{

	printf("Please enter how many idiots you want:__\b\b");
	int idiot_multyplier = 9238529;
	scanf("%d", &idiot_multyplier);

	printf("Please enter super idiot step:__\b\b");
	int idiot_multyplier_step = 9238529;
	scanf("%d", &idiot_multyplier_step);

	for(int i = 1;i < idiot_multyplier;i++)
	{
		if((i%idiot_multyplier_step) == 0 ) printf("COOOMMMBBOOO!!! %dx SUPER ",idiot_multyplier_step);

		printf("IDIOT\n");

	}
}

void ArgumentValidator(const int const amount,const char * const flags[])
{ 

for(int i = 1; i < amount; i++)
{

				
				incorrectFlagIndex = -1;
				for(int j = 0; j < ValidFlagsCount; j++) 
				{
					if(strcmp(flags[i],ValidFlags[j]) == 0) //if flag match
					{

						incorrectFlagIndex = -1;
						break;

					}	
					else 
					{
						incorrectFlagIndex = i;
					}
				}	//for j allowed				
				
			if(incorrectFlagIndex > -1)	printf("\x1b[31m[!]\x1b[0mError: incorrect flag (\x1b[31m%s\x1b[0m)\n[*]Type \x1b[32m--help\x1b[0m to see available flags\n", flags[incorrectFlagIndex]);
			
} //for i (input)
if(incorrectFlagIndex == -1)	printf("[*] All the flags found valid.\n");
	else exit(EXIT_FAILURE);
} //function ArgumentValidator end


void InvokeCommands(const char * const command[], const unsigned int count)
{	
	for(int i = 1;i < count; i++){
		for(int j = 0;j < ValidFlagsCount; j++)
		{
			if(strcmp(command[i], ValidFlags[j]) == 0) commandStore[j]();
		}

	}
}