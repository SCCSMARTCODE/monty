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
	int file_closing, del;
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
			free(buf);
			free_dlistint(*stack);
			file_closing = fclose(_file);
		        if (file_closing == -1)
		        {
		                exit(-1);
        		}
			exit(EXIT_FAILURE);
		}
		help_stack = *stack;
		check_instruction(stack, line_no);
		del = help_full(full_instruction, *stack, help_stack);
		line_no++;
	}
	free(buf);
	free_dlistint(*stack);
	file_closing = fclose(_file);
	if (file_closing == -1)
	{
		exit(-1);
	}
	if (del == -1)
	{
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int help_full(char *str, stack_t *stack, stack_t *help_stack)
{
	char *push = "push", *pall = "pall";
	if (str == push)
	{
		if (stack == help_stack)
			return (-1);
	}
	else if(str == pall)
	{
		if (stack == NULL)
		{
			return (-1);
		}
	}
	return (0);
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
		{NULL, NULL}
	};

	while (command[index].f != NULL && strcmp(command[index].opcode, line) != 0)
	{
		index++;
	}

	if (index == 4)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, line);
		return (NULL);
	}
	return (command[index].f);

}
