#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index in d list.
 * @h: pointer of a doubly linked list.
 * @idx: index where the new node should be added.
 * @n: value for the new node.
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;

	dlistint_t *current = *h;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (h == NULL || new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (idx == 0)
	{
		new = add_dnodeint(h, n);
		return (new);
	}
	while (current)
	{
		if (current->next == NULL && i == idx - 1)
		{
			new = add_dnodeint_end(h, n);
			return (new);
		}
		else if ((idx - 1) == i)
		{
			new->next = current->next;
			new->prev = current;
			current->next->prev = new;
			current->next = new;
			return (new);
		}
		i++;
		current = current->next;
	}
	free(new);
	return (NULL);
}
