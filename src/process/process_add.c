/*
** EPITECH PROJECT, 2024
** process_add.c
** File description:
** process_add.c
*/

#include "my.h"

void process_add(process_t **head, process_t *to_add)
{
    process_t *current = *head;

    if (*head == NULL)
        *head = to_add;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = to_add;
    }
    to_add->next = NULL;
}
