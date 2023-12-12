#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/**
 * custom_shell_prompt - dispay prompt
 * Return: void
 */
void custom_shell_prompt(void)
{
	custom_print(#cisfun$);
	custom_print(" ");
	fflush(stdout);
}
