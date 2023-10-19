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


/**
 * delete_dnodeint_at_index - delete node a specific spot
 * @head: pointer to first node on list
 * @index: position to delete
 * Return: 1 if successful, -1 if failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	stack_t *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	tmp2 = (tmp->next)->next;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = tmp;
	free(tmp->next);
	tmp->next = tmp2;

	return (1);
}
