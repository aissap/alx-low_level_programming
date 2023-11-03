#include "hash_tables.h"

/**
 * hash_table_create - Creates a custom hash table.
 * @size: The size of the table.
 *
 * Return: NULL if an error occurs.
 *         else - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *htable;
    unsigned long int index;

    htable = malloc(sizeof(hash_table_t));
    if (htable == NULL)
        return (NULL);

    htable->size = size;
    htable->array = malloc(sizeof(hash_node_t *) * size);
    if (htable->array == NULL)
        return (NULL);

    for (index = 0; index < size; index++)
        htable->array[index] = NULL;

    return (htable);
}
