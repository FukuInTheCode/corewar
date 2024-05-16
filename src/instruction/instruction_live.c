/*
** EPITECH PROJECT, 2024
** instruction_live.c
** File description:
** instruction_live.c
*/

#include "my.h"

int instruction_live(process_t *process, arena_t *arena)
{
    uint16_t live_id = 0;

    arena->nbr_live++;
    live_id = (uint16_t)arena->arena[process->PC + 1];
    for (process_t *tmp = arena->champions; tmp; tmp= tmp->next) {
        if (tmp->process_id != live_id)
            continue;
        tmp->cycles_to_die = arena->cycles_to_die;
    }
    process_move(process, 4);
    return 0;
}
