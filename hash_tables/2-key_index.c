#include "hash_table.c"

/**
 * key_index - Gives you the index of a key
 *
 * @key: Key of the index
 *
 * @size: Size of array of hash table
 *
 * Return: Index at which the key/value pair should be stored in array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key) % size;

	return (index);
}
