#include "lists.h"

/**
 * get_dnodeint_at_index - Retutns the nth node of dlistint_t linked list
 *
 * @head: Start of node
 *
 * @index: Index of node, starting from 0
 *
 * Return: Nth node or NULL if node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int c = 0;

	if (head == NULL)
	{
		return (NULL);
	}

	while (current != NULL)
	{
		if (c == index)
		{
			return (current);
		}

		c++;
		current = current->next;
	}

	return (NULL);
}
