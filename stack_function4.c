#include "monty.h"

struct data_s
{
	int stack_mode;
	stack_t *stack;
};

struct data_s data;

#define STACK 0
#define QUEUE 1

struct data_s data;
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;
	stack_t *tmp = NULL;

	UNUSED(line_no);

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	tmp = current->prev;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
	tmp->next = NULL;
}


/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void stack(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	data.stack_mode = STACK;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack.
 * @line_no: The line number in the bytecode file.
 */
void queue(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	data.stack_mode = QUEUE;
}

