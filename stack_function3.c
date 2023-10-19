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

