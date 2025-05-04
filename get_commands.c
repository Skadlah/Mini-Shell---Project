/*
Name:
Date:
Description:
sample i/p:
sample o/p:
*/
#include "main.h"
void get_cmds(char *input, char *cmd[])
{
    char *token = strtok(input, " ");
    int i=0;
    while(token != NULL)
    {
	cmd[i] = malloc(strlen(token) + 1);
	strcpy(cmd[i], token);
	i++;
	token = strtok(NULL, " ");
    }
    cmd[i]=NULL;
}

