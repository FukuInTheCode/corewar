/*
** EPITECH PROJECT, 2024
** my_memcpy.c
** File description:
** my_memcpy.c
*/

#include "my.h"

void *my_memcpy(void *dest, void *src, int64_t n)
{
    char *tmp = dest;
    char *tmp2 = src;

    for (int64_t i = 0; i < n; i++)
        tmp[i] = tmp2[i];
    return dest;
}
