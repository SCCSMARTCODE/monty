#include "monty.h"
/**
 * file_processor - the brain of the system
 * @file: command file
 * @stack: top of the stack
 * Return: sucess
 */

int file_processor(char *file, stack_t **stack)
{
	stack_t *help_stack = NULL;
	FILE *_file;
	int del;
	size_t len = 0;
	char *buf = NULL, *full_instruction;
	ssize_t f_d;
	unsigned int line_no = 1;
	instruct check_instruction;

	_file = fopen(file, "r");
	if (!_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((f_d = getline(&buf, &len, _file)) != -1)
	{
		full_instruction = buf_tok(buf);
		if (full_instruction == NULL || full_instruction[0] == '#')
		{
			line_no++;
			continue;
		}
		check_instruction = check_i(full_instruction, line_no);
		if (!check_instruction)
		{
			free_last(buf, *stack, _file);
			exit(EXIT_FAILURE);	}
		help_stack = *stack;
		check_instruction(stack, line_no);
		del = help_full(full_instruction, *stack, help_stack);
		if (del == -1)
		{
			free_last(buf, *stack, _file);
			exit(EXIT_FAILURE);
		}
		line_no++;
	}
	free_last(buf, *stack, _file);
	return (EXIT_SUCCESS);
}

/**
 * free_last - the total free man
 * @buf: first free arg
 * @stack: 2nd free arg
 * @_file: 3rd free arg
 */
void free_last(char *buf, stack_t *stack, FILE *_file)
{
	int file_closing;

	free(buf);
	free_dlistint(stack);
	file_closing = fclose(_file);
	if (file_closing == -1)
	{
		exit(-1);
	}
}


/**
 * end_process - by exiting failure and freeing stack
 * @stack: stack pointer
 * Return: error
 */

int end_process(stack_t **stack)
{
	if (*stack != NULL)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * buf_tok - tokenize the function
 * @str: buffer
 * Return: tokenized string
 */
char *buf_tok(char *str)
{
	char *token;

	if (str == NULL)
	{
		return (NULL);
	}
	token = strtok(str, "\n\t ");

	return (token);
}


/**
 * check_i - check if command is present
 * @line: buffer
 * @line_no: line no
 * Return: instruction if present else NULL
 */
instruct check_i(char *line, unsigned int line_no)
{
	int index = 0;
	instruction_t command[] = {
		{"push", push_c},
		{"pall", pall_c},
		{"pop", pop_c},
		{"pint", pint_c},
		{"add", add_c},
		{"swap", swap_c},
		{"nop", nop_c},
		{"sub", sub_c},
		{"div", div_c},
		{"mod", mod_c},
		{"mul", mul_c},
		{"pchar", pchar_c},
		{"pstr", pstr_c},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

	while (command[index].f != NULL && strcmp(command[index].opcode, line) != 0)
	{
		index++;
	}

	if (index == 17)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, line);
		return (NULL);
	}
	return (command[index].f);

}
