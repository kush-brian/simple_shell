#include <stdio.h>
#include <unistd.h>
/**
 * main - function that prints out pid
 * Return: 0 successful
 */

int main(void)
{
	pid_t parent_process_id;

	parent_process_id = getpid();

	printf("Parent PID: %u\n", parent_process_id);
	return (0);
}
