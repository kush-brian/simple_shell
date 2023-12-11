#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - entry point
 * Description: 'output of possible singke digit combinations'
 * Return: Always 0
 */

int main(void)
{
	int t;
	int x;

	for (t = '0'; t < '9'; t++)
	{
		for (x = t + 1; x <= '9'; x++)
		{
			if (x != t)
			{
				putchar(t);
				putchar(x);
				if (t == '8' && x == '9')
					continue;
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
