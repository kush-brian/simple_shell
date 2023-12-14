#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_functions.h"

int executeCommandWithPath(char *command, char *args[]) {
    if (strcmp(command, "exit") == 0) {
        exitShell();
    }
    else if (strcmp(command, "env") == 0)
    {
            printEnvironment();
            return (0);
    }

    int status = 0;

    // Check if the command exists in PATH
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    while (dir != NULL) {
        char path_command[MAX_COMMAND_LENGTH];
        snprintf(path_command, sizeof(path_command), "%s/%s", dir, command);

        if (access(path_command, X_OK) == 0) {
            // Command found in the current directory in PATH
            int pid = fork();

            if (pid == -1) {
                perror("Error forking");
                status = -1;
            } else if (pid == 0) {
                // Child process
                if (execv(path_command, args) == -1) {
                    perror("Error executing command");
                    exit(EXIT_FAILURE);
                }
            } else {
                // Parent process
                waitpid(pid, &status, 0);
            }

            free(path_copy);
            return status;
        }

        dir = strtok(NULL, ":");
    }

    // Command not found in PATH
    printf("Command not found: %s\n", command);
    free(path_copy);
    return -1;
}
