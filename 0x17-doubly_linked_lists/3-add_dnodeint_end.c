#include "lists.h"

/**
 * add_dnodeint_end -  pointer of a doubly linked list.
 * @head: head pointer of a doubly linked list.
 * @n: value for the new node to be added
 * Return: address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode = malloc(sizeof(dlistint_t));
	dlistint_t *current = *head;

	if (!head)
		return (NULL);

	if (!newNode)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = newNode;
	newNode->prev = current;

	return (newNode);
}
