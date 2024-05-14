/*
** EPITECH PROJECT, 2024
** arena_is_end.c
** File description:
** arena_is_end.c
*/

#include "my.h"

bool arena_is_end(arena_t *arena)
{
    for (process_t *tmp = arena->champions; tmp; tmp = tmp->next)
        if (!tmp->is_dead)
            return false;
    return true;
}
