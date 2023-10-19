#include "monty.h"
/**
 * swap_c - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void swap_c(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		return;
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add_c - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void add_c(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		return;
	}

	(*stack)->next->n += (*stack)->n;
	pop_c(stack, line_no);
}

/**
 * nop_c - Removes the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void nop_c(stack_t **stack, unsigned int line_no)
{
	UNUSED(stack);
	UNUSED(line_no);
}
