#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * get_input - function to act as a command line interpreter
 * @size: size to be allocated
 * Return: void
 */
void get_input(size_t size)
{
	char *input = (char *)malloc(size);

	if (input == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		custom_print("$ ");

		if (fgets(input, size, stdin) == NULL)
		{
			if (feof(stdin))
			{
				custom_print("\n");
				free(input);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("fgets");
				free(input);
				exit(EXIT_FAILURE);
			}
		}
		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0)
		{
			continue;
		}
		if (shell_run(input) != 0)
		{
			custom_print(stderr, "%s: command not found\n", input);
		}
	}
	free(input);
}
