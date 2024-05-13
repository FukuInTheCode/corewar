/*
** EPITECH PROJECT, 2024
** process_update.c
** File description:
** process_update.c
*/

#include "my.h"

int process_update(process_t *process)
{
    if (process->cycles_to_wait > 0)
        process->cycles_to_wait -= 1;
    if (process->is_dead == false)
        process->cycles_to_die -= 1;
    return 0;
}
