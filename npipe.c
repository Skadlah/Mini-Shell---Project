/*
Name:
Date:
Description:
sample i/p:
sample o/p:
 */
#include "main.h"

void npipe(char *argv[]) {
    int argc = 0;
    int i = 0;
    while (argv[i] != NULL) {
	argc++;
	i++;
    }

    int posarr[10];
    posarr[0] = 0;
    int j = 1;
    int count = 0;
    for (int i = 0; i < argc; i++) {
	if (!strcmp(argv[i], "|")) {  
	    argv[i] = NULL;
	    posarr[j] = i + 1;
	    j++;
	    count++;
	}
    }
    int fd[2];
    int in_fd = 0;  
    for (int i = 0; i <= count; i++) {
	pipe(fd);
	int pid = fork();
	if (pid == 0) {  
	    close(fd[0]);  
	    dup2(in_fd, 0);  
	    if (i != count) {
		dup2(fd[1], 1);  
	    }
	    close(fd[1]);
	    execvp(argv[posarr[i]], &argv[posarr[i]]);
	    perror("execvp failed");
	    exit(1);
	} else {  
	    wait(NULL);
	    close(fd[1]);  
	    in_fd = fd[0];
	}
    }
}




