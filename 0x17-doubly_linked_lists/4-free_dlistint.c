#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list.
 * @head:  pointer of a doubly linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *nextNode;

	while (head != NULL)
	{
		nextNode = head->next;
		free(head);
		head = nextNode;
	}
}
