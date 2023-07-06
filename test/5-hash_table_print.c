#include "hash_tables.h"

/**
 * hash_table_print - Pr in t s a  ha s h  t a b l e.
 * @ht: A p o i  n t e r t o   t h e   ha s h ta b l e to  pr i nt.
 * Description: Ke y/va lu e  pa i rs   ar e  p ri n t ed  in   th e or d e r
 */
void hash_table_print(const hash_table_t *ht)
{
hash_node_t *node;
unsigned long int x;
unsigned char comma_flag = 0;

if (ht == NULL)
return;
printf("{");
for (x = 0; x < ht->size; x++)
{
if (ht->array[x] != NULL)
{
if (comma_flag == 1)
printf(", ");
node = ht->array[x];
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->next;
if (node != NULL)
printf(", ");
}
comma_flag = 1;
}
}
printf("}\n");
}