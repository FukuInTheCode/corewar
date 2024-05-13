/*
** EPITECH PROJECT, 2024
** arena_create.c
** File description:
** arena_create.c
*/

#include "my.h"
#include "op.h"
#include <stdlib.h>

arena_t *arena_create(void)
{
    arena_t *arena = malloc(sizeof(arena_t));


    if (!arena)
        return NULL;
    my_memset((void *)arena, 0, sizeof(arena_t));
    arena->cycles_to_die = CYCLE_TO_DIE;
    return arena;
}
