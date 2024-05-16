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
    bool carry;
    uint8_t registers[REG_NUMBER][REG_SIZE];
    size_t cycles_to_die;
    struct process_s *next;
} process_t;

typedef struct process_info_s {
    char *filename;
    uint8_t id;
    int64_t address;
} process_info_t;

typedef struct args_s {
    uint8_t proccess_n;
    process_info_t processes[4];
    int64_t dump;
} args_t;

int handle_args(int argc, char **argv);
int check_binary(char *file);

process_t *process_create(void);
void process_destroy(process_t *);
void process_kill(process_t *to_kill);
int process_update(process_t *process);
void process_move(process_t *process, int nbr_bytes);
int process_change_register(process_t *process, size_t register_id, uint8_t *);
size_t process_get_register(process_t *process, size_t register_id);
void process_add(process_t **head, process_t *to_add);
process_t *process_copy(process_t *head);
int create_process(args_t *);

void *my_memset(char *, char, size_t);
void *my_memcpy(void *dest, void *src, size_t n);
int my_strcmp(char const *s1, char const *s2);
bool my_is_num(char const *);
int my_atoi(char const *);
char *my_strcat(char *, char const *);
