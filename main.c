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
	char *push = "push", *pall = "pall", *pint = "pint", *pop = "pop";
	char *add = "add", *swap = "swap", *nop = "nop";

	if (strcmp(str, push) == 0)
	{
		if (stack == help_stack)
			return (-1);
	}
	else if (strcmp(str, pall) == 0)
	{
		if (stack == NULL)
		{
			return (0);
		}
	}
	else if (strcmp(str, pint) == 0)
	{
		if (stack == NULL)
		{
			return (-1);
		}
	}
	else if (strcmp(str, pop) == 0)
	{
		if (stack == NULL)
		{
			return (-1);
		}
	}
	else if (strcmp(str, add) == 0 || strcmp(str, swap) == 0)
	{
		if (stack == NULL || stack->next == NULL)
		{
			return (-1);
		}
	}
	else if (strcmp(str, nop) == 0)
	{
		return (0);
	}
	return (0);
}

