#include "monty.h"
/**
 * mul_c - Multiplies the second top element by the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void mul_c(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		return;
	}

	(*stack)->next->n *= (*stack)->n;
	pop_c(stack, line_no);
}

/**
 * mod_c - Computes the remainder of the division of the second top element by the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void mod_c(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		return;
	}

	(*stack)->next->n %= (*stack)->n;
	pop_c(stack, line_no);
}

/**
 * pchar_c - Prints the character at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void pchar_c(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		return;
	}

	putchar((*stack)->n);
	putchar('\n');
}


/**
 * pstr_c - Prints the string starting at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void pstr_c(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;

	UNUSED(line_no);

	while (current != NULL && current->n != 0)
	{
		if (current->n >= 1 && current->n <= 127)
			putchar(current->n);
		else
			break;
		current = current->next;
	}

	putchar('\n');
}


/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;
	stack_t *tmp = current->next;

	UNUSED(line_no);

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	(*stack)->next = NULL;
	*stack = tmp;
	tmp->prev = NULL;
}

