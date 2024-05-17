/*
** EPITECH PROJECT, 2024
** corewar_loop.c
** File description:
** corewar_loop.c
*/

#include "my.h"

int corewar_loop(arena_t *arena)
{
    for (; !arena_is_end(arena);)
        arena_play_cycle(arena);
    return 0;
}
