/*
** EPITECH PROJECT, 2024
** process_read_instruction.c
** File description:
** process_read_instruction.c
*/

#include "my.h"
#include "op.h"

static int set_wait(process_t *process, int code)
{
    for (size_t i = 0; op_tab[i].mnemonique; i++) {
        if (op_tab[i].code != code)
            continue;
        process->cycles_to_wait = op_tab[i].nbr_cycles;
        return 0;
    }
    return 0;
}

int process_read_instruction(process_t *process, arena_t *arena)
{
    for (size_t i = 0; instructions[i].f; i++) {
        if (arena->arena[process->PC] == instructions[i].code) {
            instructions[i].f(process, arena);
            set_wait(process, instructions[i].code);
            return 0;
        }
    }
    process_move(process, 1);
    return 0;
}
