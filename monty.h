#ifndef MAIN_H
#define MAIN_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*instruct)(stack_t **stack, unsigned int line_number);

#define UNUSED(x) (void)(x);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*monty functions*/
instruct check_i(char *line, unsigned int line_no);
char *buf_tok(char *str);
int end_process(stack_t **stack);
int file_processor(char *file, stack_t **stack);

/*linked_list fuction*/
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int isnumber(char *str);

/*stack function*/
void push_c(stack_t **stack, unsigned int line_no);
void pall_c(stack_t **stack, unsigned int line_no);
void pop_c(stack_t **head, unsigned int line_no);

#endif
