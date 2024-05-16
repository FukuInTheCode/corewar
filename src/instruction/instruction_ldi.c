/*
** EPITECH PROJECT, 2024
** instruction_ldi.c
** File description:
** instruction_ldi.c
*/

#include "my.h"
#include "op.h"

static void do_ldi(process_t *process, arena_t *arena,
    int64_t arg2, int64_t arg3)
{
    int64_t arg1_type =
        process_get_arg_type(process, arena, 0) & op_tab[9].type[0];
    int64_t arg1 = arg1_type;

    if (arg1_type == T_REG)
        arg1 = process_get_register(process,
            process_get_arg_value(process, arena, 0));
    if (arg1_type == T_DIR)
        arg1 = process_get_arg_value(process, arena, 0);
    if (arg1_type == T_IND)
        arg1 = arena_read(arena, IND_SIZE, (process->PC +
            process_get_arg_value(process, arena, 0)) % IDX_MOD);
    arg1 += arg2;
    arg1 = arena_read(arena, (process->PC + arg1) % IDX_MOD, REG_SIZE);
    process_change_register(process, arg3, (uint8_t *)&arg1);
    process->carry = !arg1;
}

void instruction_ldi(process_t *process, arena_t *arena)
{
    int64_t arg1 = process_get_arg_type(process, arena, 0) & op_tab[9].type[0];
    int64_t arg2 = process_get_arg_type(process, arena, 1) & op_tab[9].type[1];
    int64_t arg3 = process_get_arg_type(process, arena, 2) & op_tab[9].type[2];

    if (!arg1 || !arg2 || !arg3)
        return;
    if (arg2 == T_REG)
        arg2 = process_get_register(process,
            process_get_arg_value(process, arena, 1));
    if (arg2 == T_DIR)
        arg2 = process_get_arg_value(process, arena, 1);
    do_ldi(process, arena, arg2, process_get_arg_value(process, arena, 2));
}
