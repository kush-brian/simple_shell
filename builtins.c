#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_functions.h"

void exitShell() {
    printf("Exiting the shell.\n");
    exit(EXIT_SUCCESS);
}

void printEnvironment()
{
        extern char **environ;

        for (char **env = environ; *env != NULL; env++)
        {
                printf("%s\n", *env);
        }
}
