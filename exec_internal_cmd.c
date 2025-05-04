/*
Name:
Date:
Description:
sample i/p:
sample o/p:
*/
#include "main.h"
char *get_current_dir_name(void);
void exec_internal_cmd(char *input)
{
    //char *cmd[] = {NULL};
   // get_cmds(input, cmd);
    if (!strcmp(input, "pwd"))
    {
	//memset(input, 0, 30);
	char *ptr = get_current_dir_name();
	printf("%s\n",ptr);
    }
    else if (!strcmp(input, "exit"))
    {
	//memset(input, 0, 30);
	exit(0);
    }
    else if (!strncmp(input,"cd ", 3))
    {
	printf("came\n");
	chdir(input + 3);
	//memset(input, 0, 30);
	//execvp(cmd[0],cmd);
    }
    memset(input, 0, 30);

}


