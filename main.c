#include "monty.h"

/**
 * main - the main function
 * @argc: arg1
 * @argv: arg2
 * Return: success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_processor(argv[1], &stack);

	return (EXIT_SUCCESS);
}
