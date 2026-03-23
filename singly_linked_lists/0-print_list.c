#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_list - Prints all elements of list_t list
 *
 * @h: Singly linked list
 *
 * Return: Number of nodes
 */

size_t print_list(const list_t *h)
{
	int c = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		if (current->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", current->len, current->str);
		}

		c++;
		current = current->next;
	}

	return (c);
}
