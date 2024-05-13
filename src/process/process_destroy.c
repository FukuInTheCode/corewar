/*
** EPITECH PROJECT, 2024
** process_destroy.c
** File description:
** process_destroy.c
*/

#include "my.h"

void process_destroy(process_t *to_destroy)
{
    free(to_destroy);
}
