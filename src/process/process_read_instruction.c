/*
** EPITECH PROJECT, 2024
** process_read_instruction.c
** File description:
** process_read_instruction.c
*/

#include "my.h"

int process_read_instruction(process_t *process, arena_t *arena)
{
    for (size_t i = 0; instructions[i].f; i++) {
        if (arena->arena[process->PC] == instructions[i].code) {
            instructions[i].f(process, arena);
            return 0;
        }
    }
    process_move(process, 1);
    return 0;
}
