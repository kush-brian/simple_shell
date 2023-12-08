#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Entry
 * Return: 0 successful
 */
int main(void)
{
	char line[MAX_LINE];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(line, MAX_LINE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		line[strcspn(line, "\n")] = '\0';

		if (strlen(line) == 0)
		{
			continue;
		}
		if (shell_run(line) != 0)
		{
			fprintf(stderr, "%s: command not found\n", line);
		}
	}
	return (0);
