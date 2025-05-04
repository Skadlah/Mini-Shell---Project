/*
Name:
Date:
Description:
sample i/p:
sample o/p:
 */
#include "main.h"
extern int cid;
extern char *input;
extern char *prompt;
void insert_last(node **head, node **tail, int data,char **input)
{
    //Create a node
    node *new = malloc (sizeof(node));

    //Assigning the data value and the addesses to the node
    new->id = cid;
    strcpy(new->cmd_name, *input); 
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
}

void print_list(node *head)
{
    /* Assigning the temp value as head */
    node *temp = head;
    printf("child [%d] stopped         %s\n", temp ->id, temp->cmd_name);
    //memset(temp -> cmd_name,0,20);
}

void sigint_handler(int signum)
{
    kill(cid, SIGINT);
    printf("\n");
    //display_prompt(prompt, input);
}

void sigtstp_handler(int signum)
{
    node *head = NULL;
    node *tail = NULL;
    insert_last(&head, &tail, cid, &input);
    kill(cid,SIGTSTP);
    printf("\n");
    print_list(head);
}

