/*
** EPITECH PROJECT, 2024
** process_create.c
** File description:
** process_create.c
*/

#include "my.h"

process_t *process_create()
{
    process_t *new_process = malloc(sizeof(process_t));

    if (!new_process)
        return NULL;
    my_memset((void *)new_process, 0, sizeof(process_t));
    return new_process;
}
