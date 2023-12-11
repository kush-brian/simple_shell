#include <stdio.h>
/**
 * main - loop past ac
 * @argv: Vector
 * @argc:counter
 * Return: 0 indicates success
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	for (int i = 0; argv[i] != NULL; i++)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}
	return (0);
}
