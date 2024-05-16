/*
** EPITECH PROJECT, 2024
** arena_read.c
** File description:
** arena_read.c
*/

#include "my.h"


size_t arena_read(arena_t *arena, size_t pos, uint8_t n)
{
    uint8_t value[n];
    size_t ret = 0;

    for (size_t i = 0; i < n; i++)
        value[i] = (arena->arena_copy[(pos + i) % MEM_SIZE] >>
            (2 * (n - i - 1))) & 0x03;
    my_memcpy((void *)&ret, (void *)value, n);
    return ret;
}
