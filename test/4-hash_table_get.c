#include "hash_tables.h"

/**
 * hash_table_get - Ret rie ve th e val ue ass oc iat ed wi th ke y ina ha sh.
 * @ht: A poi nt  e r  t o   th e   h a s h    ta  b le .
 * @key: Th e  k ey   t o  g e t    th e    v a l u e   of .
 * Return: If   t h e  k e y   c a  n n o t  be  m a t  c he  d  - NU L L.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);
index = key_index((const unsigned char *)key, ht->size);
if (index >= ht->size)
return (NULL);
node = ht->array[index];
while (node && strcmp(node->key, key) != 0)
node = node->next;
return ((node == NULL) ? NULL : node->value);
}