#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in linked list dlistint_t
 *
 * @h: Pointer to first node of dlistint_t
 *
 * Return: Number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	int c = 0;
	const dlistint_t *current = h;

	while (current != NULL)
	{
		c++;
		current = current->next;
	}

	return (c);
}
