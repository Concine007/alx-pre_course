#include "hash_tables.h"

/**
 * key_index - Ge t t he ind ex at whi ch a k ey/val ue pa ir shoul red.
 * @key: Th e ke y to  ge t th e in d ex o f.
 * @size: Th e s iz e  of  the   a rr a y of t he ha sh t ab le.
 * Return: Th e i nde x of  th e  ke y.
 * Description: Us e s t he dj b 2 alg o r i  t hm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
return (hash_djb2(key) % size);
}
