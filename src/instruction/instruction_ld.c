/*
** EPITECH PROJECT, 2024
** instruction_ld.c
** File description:
** instruction_ld.c
*/

#include "my.h"
#include "op.h"
#include <stdint.h>
#include <sys/types.h>

void instruction_ld(process_t *process, arena_t *arena)
{
    size_t arg1 = process_get_arg_type(process, arena, 0) & op_tab[1].type[0];
    size_t arg2 = process_get_arg_type(process, arena, 1) & op_tab[1].type[1];

    if (!arg1 || !arg2)
        return process_move(process, 1);
    if (arg1 == T_IND)
        arg1 = arena_read(arena, process->PC +
            process_get_arg_value(process, arena, 0), IND_SIZE);
    else
        arg1 = process_get_arg_value(process, arena, 0);
    arg2 = process_get_arg_value(process, arena, 1);
    process_change_register(process, arg2, (uint8_t *)&arg1);
}
