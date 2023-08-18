#include "lists.h"

/**
 * add_dnodeint - pointer of a doubly linked list.
 * @head: points to the first node of the list.
 * @n: value for the new node to be added.
 * Return: address of the new element or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode = malloc(sizeof(dlistint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = newNode;
	}
	*head = newNode;
	return (newNode);
}
