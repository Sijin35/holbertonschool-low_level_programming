#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list
 *
 * @head: First node of list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;
	dlistint_t *newNode;

	while (head != NULL)
	{
		tmp = head;
		newNode = tmp->next;

		free(tmp);
		tmp = newNode;
	}
}
