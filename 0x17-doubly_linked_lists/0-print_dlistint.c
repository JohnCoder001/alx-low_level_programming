#include "lists.h"

/**
 * print_dlistint - pointer of a doubly linked list.
 * @h: points to the first node of the list.
 * Return: total number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t nodeCount = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		nodeCount++;
	}
	return (nodeCount);
}
