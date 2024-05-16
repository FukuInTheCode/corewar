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
    for (int64_t i = 0; ops[i].mnemonique; i++) {
        if (ops[i].code != code)
            continue;
        process->cycles_to_wait = ops[i].nbr_cycles;
        return 0;
    }
    return 0;
}

int process_read_instruction(process_t *process, arena_t *arena)
{
    for (int64_t i = 0; instructions[i].f; i++) {
        if (arena->arena[process->PC] == instructions[i].code) {
            instructions[i].f(process, arena);
            set_wait(process, instructions[i].code);
            return 0;
        }
    }
    process_move(process, 1);
    return 0;
}
