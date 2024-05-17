/*
** EPITECH PROJECT, 2024
** instruction_st.c
** File description:
** instruction_st.c
*/

#include "my.h"
#include "op.h"

void instruction_st(process_t *process, arena_t *arena)
{
    int64_t arg1 = process_get_arg_type(process, arena, 0) & ops[2].type[0];
    int64_t arg2 = process_get_arg_type(process, arena, 1) & ops[2].type[1];

    if (!arg1 || !arg2)
        return process_move(process, 1);
    arg1 = process_get_register(process,
        process_get_arg_value(process, arena, 0));
    if (arg2 == T_REG) {
        arg2 = process_get_arg_value(process, arena, 1);
        process_change_register(process, arg2, (uint8_t *)&arg1);
        return;
    }
    arg2 = process_get_arg_value(process, arena, 1);
    arena_write(arena, process->PC + arg2, REG_SIZE, (void *)&arg1);
    process_move(process, 2 + process_get_arg_size(process, arena,
        process_get_arg_type(process, arena, 0)) +
        process_get_arg_size(process, arena,
        process_get_arg_type(process, arena, 1)));
}
