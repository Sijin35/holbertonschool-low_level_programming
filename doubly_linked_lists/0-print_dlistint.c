#include "lists.h"

/**
 * print_dlistint - Prints all elements of dlistint_t list
 *
 * @h: Pointer to first node of dlistint_t
 *
 * Return: Number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int c = 0;
	const dlistint_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);

		c++;
		current = current->next;
	}

	return (c);
}
