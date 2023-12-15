#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_functions.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/**
 * main - ..
 * Return: ..
 */
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	int i;

	while (1)
	{
		displayPrompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		parseInput(input, command, args);
		executeCommand(command, args);

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
	}
	return (0);
}
