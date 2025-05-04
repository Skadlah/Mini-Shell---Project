/*
Name:
Date:
Description:
sample i/p:
sample o/p:
 */
extern int res;
#include "main.h"
void display_prompt(char *prompt, char *input)
{
    while(1)
    {
	int st;
	    memset(input, 0, 30);
	printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET, prompt);
	scanf("%[^\n]", input);
	getchar();
	
	int newlen = strlen(input)+1;
	printf(ANSI_COLOR_CYAN);
	if (!strncmp("PS1=", input, 4))
	{
	    if (input[4] != ' ')
	    {
		free(prompt);
		prompt = malloc((newlen) * sizeof(char));
		if (prompt == NULL)
		{
		    printf("Memory allocation failed\n");
		    exit(1);
		}
		strcpy(prompt, &input[4]);
	    }
	}
	else if (!strcmp(input, "echo $$"))
	{
	    printf("the current process id is %d\n",getpid());
	}
	else if (!strcmp(input, "echo $?"))
	{
	    if(WIFEXITED(st))
	    {
		printf("exit status of process is %d\n",WEXITSTATUS(st));
	    }
	}
	else if (!strcmp(input,"echo $SHELL"))
	{
	    char *arr = getenv("SHELL");
	    printf("%s\n",arr);
	}
	else
	{
	    res = check_cmd_type(input);
	    if (res == EXTERNAL)
	    {
		exec_external_cmd(input);
	    }
	    else if (res == BUILTIN)
	    {
		exec_internal_cmd(input);
	    }
	}
    }
}



