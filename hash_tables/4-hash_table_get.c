#include "hash_tables.h"

/**
 * hash_table_get - Retrieves value assosciated with key
 *
 * @ht: Hash table to be looked into
 *
 * @key: Key whose value is being searched for
 *
 * Return: Value assosiated with element, NULL if key not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long index;
	hash_node_t *node;

	if (!ht || !key || key[0] == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (equal(node->key, key))
		{
			return (node->value);
		}

		node = node->next;
	}

	return (NULL);
}
