/*
** EPITECH PROJECT, 2024
** process_move.c
** File description:
** process_move.c
*/

#include "my.h"

void process_move(process_t *process, int nbr_bytes)
{
    if (nbr_bytes == 0)
        return;
    process->PC += nbr_bytes;
    process->PC = process->PC % MEM_SIZE;
}
