/*
** EPITECH PROJECT, 2024
** process_get_arg_type.c
** File description:
** process_get_arg_type.c
*/

#include "my.h"
#include "op.h"

int process_get_arg_type(process_t *process, arena_t *arena, size_t arg_id)
{
    if (arg_id >= MAX_ARGS_NUMBER)
        return 0;
    return (arena->arena[process->PC + 1] >>
        (2 * (MAX_ARGS_NUMBER - arg_id - 1)))
        & 0x03;
}
