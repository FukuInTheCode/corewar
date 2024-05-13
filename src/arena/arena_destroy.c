/*
** EPITECH PROJECT, 2024
** arena_destroy.c
** File description:
** arena_destroy.c
*/

#include "my.h"
#include <stdlib.h>

void arena_destroy(arena_t *arena)
{
    free(arena);
}
