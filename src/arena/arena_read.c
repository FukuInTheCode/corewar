/*
** EPITECH PROJECT, 2024
** arena_read.c
** File description:
** arena_read.c
*/

#include "my.h"


int64_t arena_read(arena_t *arena, int64_t pos, uint8_t n)
{
    uint8_t value[n];
    int64_t ret = 0;

    for (int64_t i = 0; i < n; i++)
        value[i] = arena->arena[(pos + i) % MEM_SIZE];
    my_memcpy((void *)&ret, (void *)value, n);
    reverse_bytes((void *)&ret, n);
    return ret;
}
