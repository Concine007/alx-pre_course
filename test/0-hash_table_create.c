#include "hash_tables.h"

/**
 * hash_table_create - Cr ea te s a ha sh ta bl e.
 * @size: Th e si ze o f  the  a r r a y.
 * Return: I f an   e r r o r  o c c u  r s   -  N U L L.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *ht;
unsigned long int x;

ht = malloc(sizeof(hash_table_t));
if (ht == NULL)
return (NULL);
ht->size = size;
ht->array = malloc(sizeof(hash_node_t *) * size);
if (ht->array == NULL)
return (NULL);
for (x = 0; x < size; x++)
ht->array[x] = NULL;
return (ht);
}