/*
** EPITECH PROJECT, 2024
** instruction_sub.c
** File description:
** instruction_sub.c
*/

#include "my.h"
#include "op.h"

int instruction_sub(process_t *process, arena_t *arena)
{
    size_t first = process_get_arg_type(process, arena, 0);
    size_t second = process_get_arg_type(process, arena, 1);
    size_t third = process_get_arg_type(process, arena, 2);
    size_t sum = 0;

    if (first != T_REG || second != T_REG || third != T_REG) {
        process_move(process, 1);
        return 0;
    }
    first = process_get_arg_value(process, arena, 0);
    second = process_get_arg_value(process, arena, 1);
    third = process_get_arg_value(process, arena, 2);
    sum = process_get_register(process, first) -
        process_get_register(process, second);
    process_change_register(process, third, (uint8_t *)&sum);
    process_move(process, 4);
    process->carry = !sum;
    return 0;
}
