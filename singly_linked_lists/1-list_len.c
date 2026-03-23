#include "lists.h"

/**
 * list_len- Returns the number of elements in a linked list_t list
 *
 * @h: Singly linked list
 *
 * Return: Number of elements in list
 */

size_t list_len(const list_t *h)
{
	int c = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		c++;
		current = current->next;
	}

	return (c);
}
