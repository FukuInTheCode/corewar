/*
** EPITECH PROJECT, 2024
** instruction_st.c
** File description:
** instruction_st.c
*/

#include "my.h"
#include "op.h"

int instruction_st(process_t *process, arena_t *arena)
{
    size_t first = process_get_arg_type(process, arena, 0);
    size_t second = process_get_arg_type(process, arena, 1);

    if (!(second == T_REG && first != 0 && first != T_IND)) {
        process_move(process, 1);
        return 0;
    }
    first = process_get_arg_value(process, arena, 0);
    if (first == T_REG) {
        process_change_register(process, process_get_arg_value(process, arena, 1),
        (uint8_t *)&first);
        return 0;
    }
    for (size_t i = 0; i < REG_SIZE; i++)
        arena->arena_copy[(process->PC + first) % IDX_MOD + i] =
            (first >> (2 * (REG_SIZE - i - 1))) & 0x03;
    return 0;
}
