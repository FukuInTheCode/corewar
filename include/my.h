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

process_t *process_create(void);
void process_destroy(process_t *);
void process_kill(process_t *to_kill);
int process_update(process_t *process);
void process_move(process_t *process, int nbr_bytes);
int process_change_register(process_t *process, size_t register_id,
    size_t value);
size_t process_get_register(process_t *process, size_t register_id);
void process_add(process_t *head, process_t *to_add);
process_t *process_copy(process_t *head);
