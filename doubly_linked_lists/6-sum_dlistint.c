#include "lists.h"

/**
 * sum_dlistint - Retruns sum of all data (n) of dlistint_t linked list
 *
 * @head: Start of node
 *
 * Return: Sum of all data (n) or 0 if list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	if (head == NULL)
	{
		return (0);
	}

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
