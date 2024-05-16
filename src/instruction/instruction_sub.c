/*
** EPITECH PROJECT, 2024
** instruction_sub.c
** File description:
** instruction_sub.c
*/

#include "my.h"
#include "op.h"


void instruction_sub(process_t *process, arena_t *arena)
{
    int64_t arg1 = process_get_arg_type(process, arena, 0) & ops[4].type[0];
    int64_t arg2 = process_get_arg_type(process, arena, 1) & ops[4].type[1];
    int64_t arg3 = process_get_arg_type(process, arena, 2) & ops[4].type[2];

    if (!arg1 || !arg2 || !arg3)
        return process_move(process, 1);
    arg1 = process_get_arg_value(process, arena, 0);
    arg2 = process_get_arg_value(process, arena, 1);
    arg3 = process_get_arg_value(process, arena, 2);
    arg1 = process_get_register(process, arg1);
    arg2 = process_get_register(process, arg2);
    arg1 -= arg2;
    process_change_register(process, arg3, (uint8_t *)&arg1);
}
