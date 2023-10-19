#include "monty.h"

/**
 * deleteFirstElement - Deletes the first element of a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 */

void deleteFirstElement(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
	{
	return;
	}

	temp = *head;

	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}

	*head = temp->next;
	free(temp);
}
