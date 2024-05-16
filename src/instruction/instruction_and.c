/*
** EPITECH PROJECT, 2024
** instruction_and.c
** File description:
** instruction_and.c
*/

#include "my.h"
#include "op.h"

void instruction_and(process_t *process, arena_t *arena)
{
    int64_t arg1 = process_get_arg_type(process, arena, 0) & op_tab[5].type[0];
    int64_t arg2 = process_get_arg_type(process, arena, 1) & op_tab[5].type[1];
    int64_t arg3 = process_get_arg_type(process, arena, 2) & op_tab[5].type[2];

    if (!arg1 || !arg2 || !arg3)
        return process_move(process, 1);
    arg1 = process_get_arg_value(process, arena, 0);
    arg2 = process_get_arg_value(process, arena, 1);
    arg3 = process_get_arg_value(process, arena, 2);
    if (process_get_arg_type(process, arena, 0) == T_REG)
        arg1 = process_get_register(process, arg1);
    else if (process_get_arg_type(process, arena, 0) == T_IND)
        arg1 = arena_read(arena, process->PC + arg1, IND_SIZE);
    if (process_get_arg_type(process, arena, 1) == T_REG)
        arg2 = process_get_register(process, arg2);
    else if (process_get_arg_type(process, arena, 1) == T_IND)
        arg2 = arena_read(arena, process->PC + arg2, IND_SIZE);
    arg1 &= arg2;
    process_change_register(process, arg3, (uint8_t *)&arg1);
}
