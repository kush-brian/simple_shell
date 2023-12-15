#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10
#include <sys/wait.h>

void displayPrompt();
int executeCommand(char *command, char *args[]);
void parseInput(char *input, char *command, char *args[]);
void exitShell();
int executeCommandWithPath(char *command, char *args[]);
void printEnvironment();

#endif /* SHELL_FUNCTIONS_H */
