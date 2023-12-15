#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_functions.h"

void displayPrompt()
{
	printf("$ ");
}

int executeCommand(char *command, char *args[])
{
	int status = 0;

	if (strcmp(command, "exit") == 0)
	{
		exitShell();
	}
	else if (strcmp(command, "env") == 0)
	{
		printEnvironment();
		return (0);
	}

	status = executeCommandWithPath(command, args);

	return (status);
}

void **parseInput(char *input, char *command, char *args[])
{
	int i = 0;
	char *token = strtok(input, " ");

	while (token != NULL)
	{
		if (i == 0)
		{
			strcpy(command, token);
		}
		else
		{
			args[i - 1] = strdup(token);
		}
		token = strtok(NULL, " ");
		i++;
	}
	args[i - 1] = NULL;
}
