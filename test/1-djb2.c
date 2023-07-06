#include "hash_tables.h"

/**
 * hash_djb2 - Ha sh fu nc t i o n im pl e  m en t i n g.
 * @str: Th e  s t ri n g   t o  h  a s h.
 * Return: Th e  c a l c u l a t e d   h a s h .
 */
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int ha;
int q;

ha = 5381;
while ((q = *str++))
ha = ((ha << 5) + ha) + q;
return (ha);
}