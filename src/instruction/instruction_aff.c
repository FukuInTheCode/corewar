/*
** EPITECH PROJECT, 2024
** instruction_aff.c
** File description:
** instruction_aff.c
*/

#include "my.h"

void instruction_aff(process_t *process, arena_t *arena)
{
    int64_t arg1 = process_get_arg_type(process, arena, 0) & ops[15].type[0];

    if (!arg1)
        return;
    arg1 = process_get_register(process,
        process_get_arg_value(process, arena, 0)) % 256;
    write(1, (void *)&arg1, 1);
}
