#include "monty.h"
/**
 * add_dnodeint - adding to start
 * @head: pla 1
 * @n: pla 2
 * Return: new always
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->prev = NULL;
	new->n = n;
	new->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
	return (new);
}

/**
 * add_dnodeint_end - Adds a new node to the end of a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @n: The data to be stored in the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		return (NULL); /* Return NULL on memory allocation failure */
	}

	new->n = n;
	new->next = NULL; /* The new node is the last, so its next should be NULL */

	if (*head == NULL)
	{
		/* If the list is empty, the new node becomes the head */
		new->prev = NULL;
		*head = new;
	}
	else
	{
		stack_t *tail = *head;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		/* Link the new node to the current tail */
		new->prev = tail;
		tail->next = new;
	}

	return (new); /* Return the new node that was added to the end */
}

/**
 * free_dlistint - main
 * @head: head
 * Return: void
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
