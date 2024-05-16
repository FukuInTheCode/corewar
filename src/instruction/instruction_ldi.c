/*
** EPITECH PROJECT, 2024
** instruction_ldi.c
** File description:
** instruction_ldi.c
*/

#include "my.h"
#include "op.h"

static int do_ldi(process_t *process, arena_t *arena, size_t args[3])
{
    return 0;
}

int instruction_ldi(process_t *process, arena_t *arena)
{
    size_t first = process_get_arg_type(process, arena, 0);
    size_t second = process_get_arg_type(process, arena, 1);
    size_t third = process_get_arg_type(process, arena, 2);

    if (third != T_REG || first == 0 || (second != T_DIR && second != T_REG)) {
        process_move(process, 1);
        return 0;
    }
    first = process_get_arg_value(process, arena, 0);
    if (process_get_arg_type(process, arena, 0) == T_REG)
        first = process_get_register(process, first);
    second = process_get_arg_value(process, arena, 1);
    if (process_get_arg_type(process, arena, 1) == T_REG)
        second = process_get_register(process, second);
    third = process_get_register(process,
        process_get_arg_value(process, arena, 2));
    return do_ldi(process, arena, (size_t[3]){first, second, third});
}
