/*
** EPITECH PROJECT, 2024
** instruction_live.c
** File description:
** instruction_live.c
*/

#include "my.h"
#include "op.h"

void instruction_live(process_t *process, arena_t *arena)
{
    long long live_id = 0;

    arena->nbr_live++;
    live_id = arena_read(arena, process->PC + 1, DIR_SIZE);
    for (process_t *tmp = arena->champions; tmp; tmp = tmp->next) {
        if (tmp->process_id != live_id)
            continue;
        tmp->cycles_to_die = arena->cycles_to_die;
        arena->winner = live_id;
    }
    write(1, process->name, my_strlen(process->name));
    write(1, "(", 1);
    my_put_nbr(live_id);
    write(1, ") say LIVE!\n", 12);
    process_move(process, 5);
}
