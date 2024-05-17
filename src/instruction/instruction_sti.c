/*
** EPITECH PROJECT, 2024
** instruction_sti.c
** File description:
** instruction_sti.c
*/

#include "my.h"
#include "op.h"
#include <stdint.h>

static void do_sti(process_t *process, arena_t *arena,
    int64_t arg1, int64_t arg3)
{
    int64_t arg2_type =
        process_get_arg_type(process, arena, 1) & ops[10].type[1];
    int64_t arg2 = arg2_type;

    if (arg2_type == T_REG)
        arg2 = (int8_t)process_get_register(process,
            process_get_arg_value(process, arena, 1));
    if (arg2_type == T_DIR)
        arg2 = (int)process_get_arg_value(process, arena, 1) >> 24;
    if (arg2_type == T_IND)
        arg2 = (int16_t)arena_read(arena, IND_SIZE, process->PC +
            process_get_arg_value(process, arena, 2) % IDX_MOD);
    arg3 += arg2;
    arena_write(arena, process->PC +
        (short)arg3 % IDX_MOD, REG_SIZE, (void *)&arg1);
    process_move(process, process_get_arg_size(process, arena, arg2_type) - 2 +
        process_get_arg_size(process, arena,
        process_get_arg_type(process, arena, 0)) + process_get_arg_size(process
        , arena, process_get_arg_type(process, arena, 1)));
}

void instruction_sti(process_t *process, arena_t *arena)
{
    int64_t arg1 = process_get_arg_type(process, arena, 0) & ops[10].type[0];
    int64_t arg2 = process_get_arg_type(process, arena, 1) & ops[10].type[1];
    int64_t arg3 = process_get_arg_type(process, arena, 2) & ops[10].type[2];

    if (!arg1 || !arg2 || !arg3)
        return process_move(process, 1);
    if (arg3 == T_REG)
        arg3 = process_get_register(process,
            process_get_arg_value(process, arena, 2));
    else
        arg3 = process_get_arg_value(process, arena, 2) >> 16;
    do_sti(process, arena, process_get_register(process,
        process_get_arg_value(process, arena, 0)), arg3);
}
