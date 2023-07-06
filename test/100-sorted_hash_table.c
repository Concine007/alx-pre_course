#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Cr eat es  a sor t e d ha sh tab l e.
 * @size: The  siz e   of   n e w  so r t e d ha s h  ta b l e.
 * Return: If a n er r or occ u r s - N U L L.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int x;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
		ht->array[x] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Ad d s  a n   e l em e n t   t o   a s o r t e d ta ble.
 * @ht: A po in  te r t o th e sor t e d h as h ta bl e .
 * @key: Th e ke y t o a dd  - c a n n o t be   a n   e m pt y  st ri n g.
 * Return: Up o n  fa i l u re - 0. Oth er w i s e - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *new, *tmp;
char *value_copy;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);
value_copy = strdup(value);
if (value_copy == NULL)
return (0);
index = key_index((const unsigned char *)key, ht->size);
tmp = ht->shead;
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = value_copy;
return (1);
}
tmp = tmp->snext;
}
new = malloc(sizeof(shash_node_t));
if (new == NULL)
{
free(value_copy);
return (0);
}
new->key = strdup(key);
if (new->key == NULL)
{
free(value_copy);
free(new);
return (0);
}
new->value = value_copy;
new->next = ht->array[index];
ht->array[index] = new;
if (ht->shead == NULL)
{
new->sprev = NULL;
new->snext = NULL;
ht->shead = new;
ht->stail = new;
}
else if (strcmp(ht->shead->key, key) > 0)
{
new->sprev = NULL;
new->snext = ht->shead;
ht->shead->sprev = new;
ht->shead = new;
}
else
{
tmp = ht->shead;
while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
tmp = tmp->snext;
new->sprev = tmp;
new->snext = tmp->snext;
if (tmp->snext == NULL)
ht->stail = new;
else
tmp->snext->sprev = new;
tmp->snext = new;
}
return (1);
}

/**
 * shash_table_get - Ret r i ev  e  th e  v a l u e   a s s o ci ated  w i t h
 * @ht: A po i nt e  r  to   t h e   s o r te d   h as h    ta b l  e.
 * @key: Th e   k ey    t o  g e  t   th e  v a l  u e  o f.
 * Return: If th e  ke y   c a n  no t  b e ma t c h ed - N U L L.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);
index = key_index((const unsigned char *)key, ht->size);
if (index >= ht->size)
return (NULL);
node = ht->shead;
while (node != NULL && strcmp(node->key, key) != 0)
node = node->snext;
return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Pr in t s  a  sor t e d  ha sh ta ble  in  ord er.
 * @ht: A p oi n t e r t o th e  so r t e d ha sh   ta bl e .
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;

if (ht == NULL)
return;
node = ht->shead;
printf("{");
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->snext;
if (node != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_print_rev - Pr i n  t s a  s o r t e d  ha shle rev  er se er.
 * @ht: A po int e r  to th e s or ted  ha sh  ta b le t o pr i n t.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;

if (ht == NULL)
return;
node = ht->stail;
printf("{");
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->sprev;
if (node != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_delete - De le te s a so rt ed ha sh ta bl e.
 * @ht: A poi n te r to  th e so rt ed ha sh tab l e.
 */
void shash_table_delete(shash_table_t *ht)
{
shash_table_t *head = ht;
shash_node_t *node, *tmp;

if (ht == NULL)
return;
node = ht->shead;
while (node)
{
tmp = node->snext;
free(node->key);
free(node->value);
free(node);
node = tmp;
}
free(head->array);
free(head);
}