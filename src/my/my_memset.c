/*
** EPITECH PROJECT, 2024
** my_memset.c
** File description:
** my_memset.c
*/

#include "my.h"

void *my_memset(char *p, char c, size_t count)
{
    for (size_t i = 0; i < count; i++)
        p[i] = c;
    return (void *)p;
}
