/*
** EPITECH PROJECT, 2024
** my_memset.c
** File description:
** my_memset.c
*/

#include "my.h"

void *my_memset(char *p, char c, int64_t count)
{
    for (int64_t i = 0; i < count; i++)
        p[i] = c;
    return (void *)p;
}
