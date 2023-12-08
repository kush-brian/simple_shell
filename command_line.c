#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - Enntry point
 *
 * Return: 0 Always Successful
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("getline");

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
	free(line);
	return (0);
}
