#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of dlistint_t list
 *
 * @head: First node of the list
 *
 * @n: Integer
 *
 * Return: Address of new element, or NULL if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *pHead = *head;

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}

	pHead->next = new;
	new->prev = pHead;

	return (new);
}
