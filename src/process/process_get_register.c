/*
** EPITECH PROJECT, 2024
** process_get_register.c
** File description:
** process_get_register.c
*/

#include "my.h"

int64_t process_get_register(process_t *process, int64_t register_id)
{
    return (size_t)*process->registers[register_id - 1];
}
