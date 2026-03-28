#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 *
 * @h: Start of node
 *
 * @idx: Index where new node should be added, starts at 0
 *
 * @n: Value
 *
 * Return: Address of new node or NULL if failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *current = *h;
	unsigned int c = 1;

	if (new == NULL)
	{return (NULL); }
	new->n = n;
	if (idx == 0)
	{
		new->next = current;
		new->prev = NULL;
		if (current != NULL)
		{
			(*h)->prev = new;
		}
		*h = new;

		return (new);
	}
	while (current != NULL)
	{
		if (c == idx)
		{
			new->next = current;
			new->prev = current->prev;
			current->prev->next = new;
			current->prev = new;

			return (new);
		}

		current = current->next;
		c++;
	}
	return (NULL);
}
