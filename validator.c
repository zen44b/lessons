#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//[*][*][*] \ [*]
const char * const ValidFlags[] = {"--flag1", "--flag2", "--flag3","--help"};
const int const ValidFlagsCount = sizeof ValidFlags / sizeof ValidFlags[0]; // massive of pointers to strings (char massives)[*][*][*] \ [*]

void PrintHelp(void) 
{
printf("%s:\n\n\t\tUsage guide\n",ValidFlags[0]);
printf("%s:\n\n\t\tUsage guide\n",ValidFlags[1]);
printf("%s:\n\n\t\tUsage guide\n",ValidFlags[2]);
printf("%s:\n\n\t\tDisplays this message\n",ValidFlags[3]);
exit(0);
}


/*VALIDATION FUNCTION 						\/INPUT\/*/
void ArgumentValidator(const int const amount,const char * const flags[])
{
bool FlagExist = false;



for(int i = 1; i < amount; i++){

				FlagExist = false;
				int incorrectFlagIndex = -1;
				for(int j = 0; j < ValidFlagsCount; j++) {
					if(strcmp(flags[i],"--help") == 0) 
					{
						PrintHelp();
						break;
					}

					if(strcmp(flags[i],ValidFlags[j]) == 0) 
					{

						//printf("[+]STRIKE!\n");
						FlagExist = true;
						int incorrectFlagIndex = -1;
						break;

					}	
					else 
					{
						incorrectFlagIndex = i;
					}
}						
			if(FlagExist == true){
				printf("[*] All the flags found valid.\n");
			}
			if(!FlagExist){
				printf("\x1b[31m[!]\x1b[0mError: incorrect flag (\x1b[31m%s\x1b[0m)\n[*]Type \x1b[32m--help\x1b[0m to see available flags\n", flags[incorrectFlagIndex]);
			}
}
}


int main(const int const argc,const char * const argv[])
{
	
	if(argc>1){
		ArgumentValidator(argc,argv);
		return EXIT_SUCCESS;
	} else 
		printf("No flags recieved.\nEXIT_FAILURE\n");
		exit(EXIT_FAILURE);


}
