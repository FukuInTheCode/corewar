/*
** EPITECH PROJECT, 2024
** arena_update.c
** File description:
** arena_update.c
*/

#include "my.h"
#include "op.h"

int arena_update(arena_t *arena)
{
    arena->total_cycles++;
    if (arena->nbr_live >= NBR_LIVE) {
        arena->cycles_to_die -= CYCLE_DELTA * (arena->nbr_live / NBR_LIVE);
        arena->nbr_live = arena->nbr_live % NBR_LIVE;
    }
    for (process_t *tmp = arena->champions; tmp; tmp = tmp->next) {
        process_update(tmp);
        if (tmp->cycles_to_die == 0)
            process_kill(tmp);
    }
    my_memcpy((void *)arena->arena, (void *)arena->arena_copy, MEM_SIZE);
    return 0;
}
