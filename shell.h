#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>


void custom_shell_prompt(void);
void custom_print(FILE *stream, const char *format, ...);
void shell_run(const char *input);
#endif
