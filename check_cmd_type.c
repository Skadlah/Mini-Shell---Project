/*

Name:
Date:
Description:
sample i/p:
sample o/p:
 */

#include "main.h"

int check_cmd_type(char *input)
{
    char *builtins[] = {"echo","printf","read","cd","pwd","pushd","popd","dirs","let","eval","set","unset","export","declare","typeset","readonly","getopts","source","exit","exec","shopt","caller","true","type","hash","bind","help",NULL};
    for (int i=0; builtins[i] != NULL;i++)
    {
	if (!strcmp(builtins[i], input))
	{
	    return BUILTIN;
	}
    }
    char buff[BUFF_SIZE];
    int read_bytes;
    int fd = open("external_cmd.txt", O_RDONLY);
    
    int ret = 1;

    while(ret != 0)
    {
	int i = 0;
	while(ret = read(fd, &buff[i], 1))
	{

	    if (buff[i] == '\n')
	    {
		buff[i] = '\0';
		break;
	    }
	    i++;
	}
	if(!strncmp(input, buff, strlen(buff)))
	{
	    return EXTERNAL;
	}
    }
    return NO_COMMAND;
}


