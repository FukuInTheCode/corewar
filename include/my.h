/*
** EPITECH PROJECT, 2024
** my .h
** File description:
** header for amazed
*/

#pragma once
    #define MY_H
    #include <unistd.h>
    #include "op.h"
    #include <stdint.h>
    #include <stdbool.h>
    #include <stddef.h>

typedef struct arena_s {
    // process_t *champions;
    uint8_t arena[MEM_SIZE];
    uint8_t arena_copy[MEM_SIZE];
    size_t cycles_to_die;
    size_t nbr_live;
    size_t total_cycles;
} arena_t;

void *my_memset(char *, char, size_t);
