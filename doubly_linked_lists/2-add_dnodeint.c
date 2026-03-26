#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of dlistint_t
 *
 * @head: Beginning node of list
 *
 * @n: integer
 *
 * Return: Address if new element, or NULL if failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->prev = NULL;

	new->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}

	*head = new;

	return (new);
}
