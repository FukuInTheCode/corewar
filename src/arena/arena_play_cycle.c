/*
** EPITECH PROJECT, 2024
** arena_play_cycle.c
** File description:
** arena_play_cycle.c
*/

#include "my.h"

int arena_play_cycle(arena_t *arena)
{
    for (process_t *tmp = arena->champions; tmp; tmp = tmp->next)
        if (!tmp->cycles_to_wait)
            process_read_instruction(tmp, arena);
    arena_update(arena);
    return 0;
}
