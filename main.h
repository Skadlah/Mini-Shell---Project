#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFF_SIZE 50
#define BUILTIN		1
#define EXTERNAL	2
#define NO_COMMAND  3

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct sll
{
    int id;
    char cmd_name[20];
    struct sll *prev;
    struct sll *next;
}node;

void display_prompt(char *prompt, char *input);
void get_cmds(char *input, char *cmds[]);
int check_cmd_type(char *command);
//void echo(char *input_string, int status);
void exec_internal_cmd(char *input);
void exec_external_cmd(char *input);
void sigint_handler(int signum);
void sigtstp_handler(int signum);
void npipe(char **);
void print_list(node *head);
void insert_last(node **head, node **tail, int ,char **);
#endif

/*
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    //Create a node
    Dlist *new = malloc (sizeof(Dlist));

    //Validation
    if (new == NULL)
    {
	return FAILURE;
    }

    //Assigning the data value and the addesses to the node
    new->data = data;
    new->prev = *tail;
    new->next = NULL;

    //If first node, then head value is also set to the address of the new node
    if(*head == NULL)
    {
	*head = new;
    }
    //If tail is not NULL, assigning the adddress of the current node to the next pointer of the previous node
    if (*tail != NULL)
    {
	new->prev->next = new;
    }
    //Assigning the address of the created node to the tail pointer
    *tail = new;
    return SUCCESS;
}
*/
