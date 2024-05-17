/*
** EPITECH PROJECT, 2024
** corewar_loop.c
** File description:
** corewar_loop.c
*/

#include "my.h"
#include "op.h"

static void write_winner(arena_t *arena)
{
    for (process_t *tmp = arena->champions; tmp; tmp = tmp->next) {
        if (arena->winner == tmp->process_id) {
            write(1, tmp->name, my_strlen(tmp->name));
            write(1, " ", 1);
            my_put_nbr(tmp->process_id);
            write(1, " WON!\n", 6);
            write(1, tmp->comment, my_strlen(tmp->comment));
            write(1, "\n", 1);
            return;
        }
    }
}

int corewar_loop(arena_t *arena, args_t *args)
{
    for (; !arena_is_end(arena);) {
        if (args->dump == arena->total_cycles) {
            break;
        }
        arena_play_cycle(arena);
    }
    arena_dump(arena->arena, MEM_SIZE);
    write(1, "TOOK ", 5);
    my_put_nbr(arena->total_cycles);
    write(1, " CYCLES\n", 8);
    write_winner(arena);
    for (process_t *tmp = arena->champions; arena->champions;
        arena->champions = tmp) {
        tmp = arena->champions->next;
        process_destroy(arena->champions);
    }
    arena_destroy(arena);
    return 0;
}
