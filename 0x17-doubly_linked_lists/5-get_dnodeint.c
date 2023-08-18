#include "lists.h"

/**
 * get_dnodeint_at_index - pointer of a doubly linked list.
 * @head: pointer to the list.
 * @index: node to retrieve.
 * Return: node does not exist, return NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL && count < index)
	{
		head = head->next;
		count++;
	}
	if (head == NULL)
	{
		return (NULL);
	}
	return (head);
}
