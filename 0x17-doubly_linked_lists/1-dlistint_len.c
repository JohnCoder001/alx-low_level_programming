#include "lists.h"

/**
 * dlistint_len - pointer of a doubly linked list.
 * @h: points to the first node of the list.
 * Return: total number of nodes in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodeCount = 0;

	while (h != NULL)
	{
		h = h->next;
		nodeCount++;
	}
	return (nodeCount);
}
