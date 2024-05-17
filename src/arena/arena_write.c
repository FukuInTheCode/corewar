/*
** EPITECH PROJECT, 2024
** arena_write.c
** File description:
** arena_write.c
*/

#include "my.h"
#include "op.h"

void arena_write(arena_t *arena, int64_t pos, uint8_t n, int8_t *value)
{
    for (int64_t i = 0; i < n; i++) {
        arena->arena_copy[(pos + i) % MEM_SIZE] = value[n - i - 1];
    }
}
