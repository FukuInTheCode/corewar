/*
** EPITECH PROJECT, 2024
** process_copy.c
** File description:
** process_copy.c
*/

#include "my.h"
#include "op.h"

process_t *process_copy(process_t *head)
{
    process_t *copy = process_create();

    my_memcpy(copy, head, sizeof(process_t));
    copy->next = NULL;
    return copy;
}
