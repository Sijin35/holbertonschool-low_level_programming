#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Fress a list_t list
 *
 * @head: Start of list
 */

void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;

		free(tmp->str);
		free(tmp);
	}
}
