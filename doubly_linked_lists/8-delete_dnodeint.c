#include "lists.h"
/**
 *delete_dnodeint_at_index - Delete node at index of dlistint_t linked list
 *
 *@head: Pointer to first node of list
 *
 *@index: Index of node that should be deleted
 *
 *Return: 1 on success, -1 if fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *tmp = *head;

	if (!*head)
		return (-1);

	for (i = 0; tmp != NULL && i < index; ++i)
	{
		tmp = tmp->next;
	}

	if (!tmp)
		return (-1);

	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;


	if (*head == tmp)
	{
		*head = tmp->next;
		if (*head != NULL)
		(*head)->prev = NULL;
	}
	free(tmp);
	return (1);
}
