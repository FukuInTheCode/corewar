/*
** EPITECH PROJECT, 2024
** instruction_fork.c
** File description:
** instruction_fork.c
*/

#include "my.h"
#include "op.h"

void instruction_fork(process_t *process, arena_t *arena)
{
    int64_t to_go = arena_read(arena, process->PC + 1, IND_SIZE);
    process_t *forked = process_copy(process);

    if (!forked)
        return process_move(process, 1);
    process_add(&arena->champions, forked);
    forked->cycles_to_wait = ops[11].nbr_cycles + 1;
    process_move(forked, process->PC + to_go % IDX_MOD);
    process_move(process, 3);
}
