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
		return;
	}

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * pop_c - pop's ooout the first element in stack
 * @head: stack pointer
 * @line_no: line of opcode occurance
 *
 */

void pop_c(stack_t **head, unsigned int line_no)
{
	stack_t *ptr = *head;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		return;
	}
	deleteFirstElement(head);
}

/**
 * pint_c - pop's ooout the first element in stack
 * @head: stack pointer
 * @line_no: line of opcode occurance
 *
 */

void pint_c(stack_t **head, unsigned int line_no)
{
	stack_t *head_h = *head;

	if (head_h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		return;
	}
	printf("%d\n", head_h->n);
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
