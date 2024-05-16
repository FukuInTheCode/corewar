/*
** EPITECH PROJECT, 2024
** instruction_zjmp.c
** File description:
** instruction_zjmp.c
*/

#include "my.h"
#include "op.h"

void instruction_zjmp(process_t *process, arena_t *arena)
{
    size_t to_go = 0;

    if (!process->carry)
        process_move(process, 3);
    to_go = arena_read(arena, process->PC + 1, IND_SIZE);
    process->PC = ((process->PC + to_go) % IDX_MOD) % MEM_SIZE;
}
