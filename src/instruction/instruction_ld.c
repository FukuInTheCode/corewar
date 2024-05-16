/*
** EPITECH PROJECT, 2024
** instruction_ld.c
** File description:
** instruction_ld.c
*/

#include "my.h"
#include "op.h"
#include <stdint.h>
#include <sys/types.h>

int instruction_ld(process_t *process, arena_t *arena)
{
    size_t first = process_get_arg_type(process, arena, 0);
    size_t second = process_get_arg_type(process, arena, 1);

    if (!(second == T_REG && first != 0)) {
        process_move(process, 1);
        return 0;
    }
    first = process_get_arg_value(process, arena, 0);
    process_change_register(process, process_get_arg_value(process, arena, 1),
        (uint8_t *)&first);
    process->carry = !first;
    process_move(process, 2 + process_get_arg_size(process, arena, 0));
    return 0;
}
