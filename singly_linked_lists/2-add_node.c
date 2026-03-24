#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list
 *
 * @head: Pointer to pointer to list_t node
 *
 * @str: Value to be stored in new node
 *
 * Return: Address of the new element, or NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->len = strlen(str);
	new->str = strdup(str);

	new->next = *head;
	*head = new;

	return (new);
}
