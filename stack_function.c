#include "monty.h"

/**
 * push_c - push val
 * @stack: top pointer
 * @line_no: line in command file
 */
void push_c(stack_t **stack, unsigned int line_no)
{
	int x = 0;
	char *input_val = NULL;

	input_val = strtok(NULL, "\n\t ");

	if (isnumber(input_val) == 1 && input_val != NULL)
	{
		x = atoi(input_val);
		add_dnodeint(stack, x);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		end_process(stack);
	}
}

/**
 * pall_c - push val
 * @stack: top pointer
 * @line_no: line in command file
 */

void pall_c(stack_t **stack, unsigned int line_no)
{
	stack_t *head = *stack;

	UNUSED(line_no);

	if (head == NULL)
	{
		end_process(stack);
	}

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
