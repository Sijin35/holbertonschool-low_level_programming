#include "hash_tables.h"

/**
 * dup - Checks length of string and duplicates it
 *
 * @s: String to be duplicated
 *
 * Return: Duplicated string
 */

char *dup(const char *s)
{
	int len = 0;
	int i = 0;
	char *copy;

	while (s[len])
	{
		len++;
	}

	copy = malloc(len + 1);

	if (!copy)
	{
		return (NULL);
	}

	while (i <= len)
	{
		copy[i] = s[i];
		i++;
	}

	return (copy);
}

/**
 * equal - Checks whether two strings are equal or not
 *
 * @s1: First string
 *
 * @s2: Second string
 *
 * Return: Equal = 1, !Equal = 0
 */

int equal(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (0);
		}

		s1++;
		s2++;
	}

	return (*s1 == '\0' && *s2 == '\0');
}

/**
 * update_node - Updates value of node if new key matches
 *
 * @node: Pointer to head of linked list at hash table index
 *
 * @key: Keyto be searched in likned list
 *
 * @value: New value to be set if key matches
 *
 * Return: Successful update = 1, else 0
 */

int update_node(hash_node_t *node, const char *key, const char *value)
{
	while (node)
	{
		if (equal(node->key, key))
		{
			free(node->value);
			node->value = dup(value);

			if (!node->value)
			{
				return (0);
			}

			return (1);
		}

		node = node->next;
	}

	return (0);
}

/**
 * insert_new - Inserts new node at head of linked list in hash table
 *
 * @ht: Pointer to hash table
 *
 * @index: Index within hash table
 *
 * @key: Key to be stored in new node
 *
 * @value: Value to be stored in new node
 *
 * Return: 1 if new node has been created and inserted, else 0
 */

int insert_new(hash_table_t *ht,
		unsigned long index,
		const char *key,
		const char *value)
{
	hash_node_t *new = malloc(sizeof(hash_node_t));

	if (!new)
	{
		return (0);
	}

	new->key = dup(key);
	new->value = dup(value);

	if (!new->key || !new->value)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (0);
	}

	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}

/**
 * hash_table_set - Adds an element to the hash table
 *
 * @ht: Hash table to add or update the key/value to
 *
 * @key: Key, cannot be empty string
 *
 * @value: Value assosciated with key, must be duplicated, can be empty string
 *
 * Return: Success = 1, Otherwise 0
 * Collision = Add new node to beginning of list
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long index;

	if (!ht || !key || key[0] == '\0' || !value)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);

	if (update_node(ht->array[index], key, value))
	{
		return (1);
	}

	return (insert_new(ht, index, key, value));
}
