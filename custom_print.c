#include "shell.h"
#include <string.h>
#include <unistd.h>
/**
 * custom_print - Whitney and Kuria cutom print function
 * @input: Message to be printed out
 * Return: 0 successful
 */
void custom_print(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
