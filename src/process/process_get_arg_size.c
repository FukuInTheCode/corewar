/*
** EPITECH PROJECT, 2024
** process_get_arg_size.c
** File description:
** process_get_arg_size.c
*/

#include "my.h"
#include "op.h"

size_t process_get_arg_size(process_t *process, arena_t *arena,
    size_t arg_type)
{
    if (arg_type == T_DIR)
        return DIR_SIZE;
    if (arg_type == T_IND)
        return IND_SIZE;
    if (arg_type == T_REG)
        return 1;
    return 0;
}
