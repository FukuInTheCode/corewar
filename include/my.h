/*
** EPITECH PROJECT, 2024
** my .h
** File description:
** header for amazed
*/

#pragma once
    #define MY_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdint.h>
    #include "op.h"

typedef struct process_s {
    int process_id;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH+ 1];
    uint8_t binary[MEM_SIZE + 1];
    bool is_dead;
    int cycles_to_wait;
    size_t PC;
    struct process_s *next;
    bool carry;
    uint8_t registers[REG_NUMBER][REG_SIZE];
    size_t cycles_to_die;
} process_t;
