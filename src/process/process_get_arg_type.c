/*
** EPITECH PROJECT, 2024
** process_get_arg_type.c
** File description:
** process_get_arg_type.c
*/

#include "my.h"
#include "op.h"

int process_get_arg_type(process_t *process, arena_t *arena, int64_t arg_id)
{
    uint8_t tmp = 0;

    if (arg_id >= MAX_ARGS_NUMBER)
        return 0;
    tmp = (arena->arena[process->PC + 1] >>
        (2 * (MAX_ARGS_NUMBER - arg_id - 1)))
        & 0x03;
    if (tmp == 1)
        return T_REG;
    if (tmp == 3)
        return T_IND;
    if (tmp == 2)
        return T_DIR;
    return 0;
}
