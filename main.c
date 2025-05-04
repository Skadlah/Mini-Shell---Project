/*
Name:
Date:
Description:
sample i/p:
sample o/p:
 */
int res=0;
char *input;
char *prompt;
#include "main.h"
int main()
{
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);
    system("clear");
    int ret;
    prompt = malloc(11 * sizeof(char));
    if (prompt == NULL)
    {
	printf("Memory allocation failed\n");
	return 1;
    }
    strcpy(prompt, "minishell$");

    input = malloc(30 * sizeof(char));
    if (input == NULL)
    {
	printf("Memory allocation failed\n");
	free(prompt); 
	return 1;
    }
    display_prompt(prompt, input);
    
    free(prompt);
    free(input);

    return 0;
}


