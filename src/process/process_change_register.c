/*
** EPITECH PROJECT, 2024
** process_change_register.c
** File description:
** process_change_register.c
*/

#include "my.h"
#include "op.h"

int process_change_register(process_t *process, size_t register_id,
    uint8_t *reg)
{
    if (!process || register_id >= REG_NUMBER)
        return 84;
    for (size_t i = 0;  i < REG_SIZE; i++)
        process->registers[register_id][i] = reg[i];
    return 0;
}
