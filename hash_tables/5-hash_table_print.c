#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 *
 * @ht: Hash table to be printed
 * Key/value printed in oreder of appearence in array of hash table
 *
 * ht == NULL, print nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first = 1;

	if (!ht)
	{
		return;
	}

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		while (node)
		{
			if (!first)
			{
				printf(", ");
			}
			else
			{
				first = 0;
			}

			printf("'%s' : '%s'", node->key, node->value);

			node = node->next;
		}
	}

	printf("}\n");
}
