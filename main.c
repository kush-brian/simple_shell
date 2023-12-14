// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_functions.h"

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        displayPrompt();

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle end-of-file condition (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the newline character at the end of the input
        input[strcspn(input, "\n")] = '\0';

        // Parse input into command and arguments
        parseInput(input, command, args);

        // Execute the entered command with arguments
        executeCommand(command, args);

        // Free memory allocated for arguments
        for (int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
    }

    return 0;
}

