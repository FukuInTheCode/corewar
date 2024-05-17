/*
** EPITECH PROJECT, 2024
** corewar_loop.c
** File description:
** corewar_loop.c
*/

#include "my.h"
#include "op.h"

int corewar_loop(arena_t *arena, args_t *args)
{
    for (; !arena_is_end(arena);) {
        if (args->dump == arena->total_cycles) {
            arena_dump(arena->arena, MEM_SIZE);
            break;
        }
        arena_play_cycle(arena);
    }
    return 0;
}
