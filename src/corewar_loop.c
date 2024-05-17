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
            return 0;
        }
        arena_play_cycle(arena);
    }
    arena_dump(arena->arena, MEM_SIZE);
    write(1, "TOOK ", 5);
    my_put_nbr(arena->total_cycles);
    write(1, " CYCLES\n", 8);
    for (process_t *tmp = arena->champions; arena->champions;
        arena->champions = tmp) {
        tmp = arena->champions->next;
        process_destroy(arena->champions);
    }
    arena_destroy(arena);
    return 0;
}
