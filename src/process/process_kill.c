/*
** EPITECH PROJECT, 2024
** process_kill.c
** File description:
** process_kill.c
*/

#include "my.h"

void process_kill(process_t *to_kill)
{
    to_kill->is_dead = true;
}