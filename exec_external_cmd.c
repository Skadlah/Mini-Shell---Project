/*
Name:
Date:
Description:
sample i/p:
sample o/p:
 */
#include "main.h"

int cid;
int count=0;
void exec_external_cmd(char *input) {
    int stat;
    int i=0;
    while(input[i] != '\0')
    {
	//printf("1");
	if (input[i] == '|')
	{
	    count++;
	    break;
	}
	i++;
    }
    //printf("%d",count);
    if (count == 0) {
	cid = fork();
	if (cid == 0) {
	    char *cmds[5] = {NULL};
	    get_cmds(input, cmds);
	    execvp(cmds[0], cmds);
	    perror("execvp failed");
	} 
	else {
	    waitpid(cid, &stat, WUNTRACED);
	    memset(input, 0, 30);
	    if (WIFEXITED(stat)) {
		printf("child exited normally with %d\n", WEXITSTATUS(stat));
	    } 
	    else if (WIFSIGNALED(stat))
	    {
		printf("child exited normally with %d\n",WTERMSIG(stat));
	    }
	    else if (WIFSTOPPED(stat))
	    {
		printf("child stopped with %d\n",WSTOPSIG(stat));
	    }
	}
    }
    else
    {
	//printf("success");
	char *cmds[10] = {NULL};
	get_cmds(input,cmds);
	npipe(cmds);
    }
}
