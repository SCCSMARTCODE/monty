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


/**
 * help_full - the end checker
 * @str: lol
 * @stack: stack value
 * @help_stack: stack support
 * Return: 0 or -1 as the case mabe
 */
int help_full(char *str, stack_t *stack, stack_t *help_stack)
{
	char *push = "push", *pall = "pall";

	if (str == push)
	{
		if (stack == help_stack)
			return (-1);
	}
	else if (str == pall)
	{
		if (stack == NULL)
		{
			return (-1);
		}
	}
	return (0);
}

