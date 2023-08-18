#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at nth index.
 * @head: pointer of a doubly linked list.
 * @index: node to delete.
 * Return: number of nodes.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *new;

	if (*head == NULL)
		return (-1);

	new = *head;
	if (index == 0)
	{
		*head = new->next;
		if (new->next != NULL)
		{
			new->next->prev = NULL;
		}
		free(new);
		return (1);
	}
	for (i = 0; new != NULL && i < index - 1 ; i++)
	{
		new = new->next;
	}
	if (new == NULL || new->next == NULL)
	{
		return (-1);
	}

	if (new->next->next != NULL)
	{
		new->next = new->next->next;
		free(new->next->prev);
		new->next->prev = new;
		return (1);
	}
	else
	{
		free(new->next);
		new->next = NULL;
		return (1);
	}
	return (-1);
}
