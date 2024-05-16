/*
** EPITECH PROJECT, 2024
** instruction_and.c
** File description:
** instruction_and.c
*/

#include "my.h"
#include "op.h"

static int get_values(process_t *process, arena_t *arena,
    size_t *first, size_t *second)
{
    *first = process_get_arg_value(process, arena, 0);
    *second = process_get_arg_value(process, arena, 1);
    if (*first == T_REG)
        *first = process_get_register(process, *first);
    if (*second == T_REG)
        *second = process_get_register(process, *second);
    return 0;
}

int instruction_and(process_t *process, arena_t *arena)
{
    size_t first = process_get_arg_type(process, arena, 0);
    size_t second = process_get_arg_type(process, arena, 1);
    size_t third = process_get_arg_type(process, arena, 2);
    size_t result = 0;

    if (third != T_REG || first == 0 || second == 0) {
        process_move(process, 1);
        return 0;
    }
    get_values(process, arena, &first, &second);
    result = first & second;
    process_change_register(process, third, (uint8_t *)&result);
    process_move(process, 2 + process_get_arg_size(process, arena, 0) +
        process_get_arg_size(process, arena, 1));
    process->carry = !result;
    return 0;
}
