/*
** EPITECH PROJECT, 2024
** process_get_arg_value.c
** File description:
** process_get_arg_value.c
*/

#include "my.h"
#include "op.h"

size_t process_get_arg_value(process_t *process, arena_t *arena, size_t arg_id)
{
    size_t offset = 2;
    size_t arg_type = 0;

    if (arg_id >= MAX_ARGS_NUMBER)
        return 0;
    for (size_t i = 0; i < arg_id; i++)
        offset += process_get_arg_size(process, arena,
            process_get_arg_type(process, arena, i));
    arg_type = process_get_arg_type(process, arena, arg_id);
    if (arg_type == T_DIR)
        return arena_read(arena, process->PC + offset, DIR_SIZE);
    if (arg_type == T_IND)
        return arena_read(arena, process->PC + offset, IND_SIZE);
    if (arg_type == T_REG)
        return arena_read(arena, process->PC + offset, 1);
    return 0;
}
