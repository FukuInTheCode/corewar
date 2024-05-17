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
    #include <stdint.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "op.h"
    #include <stdio.h>

typedef struct process_s {
    int process_id;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH+ 1];
    uint8_t binary[MEM_SIZE + 1];
    bool is_dead;
    int cycles_to_wait;
    size_t PC;
    bool carry;
    size_t binary_size;
    uint8_t registers[REG_NUMBER][REG_SIZE];
    int64_t cycles_to_die;
    struct process_s *next;
} process_t;

typedef struct arena_s {
    process_t *champions;
    uint8_t arena[MEM_SIZE];
    uint8_t arena_copy[MEM_SIZE];
    int64_t cycles_to_die;
    int64_t nbr_live;
    int64_t total_cycles;
} arena_t;

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
int process_change_register(process_t *process, int64_t, uint8_t *);
int64_t process_get_register(process_t *process, int64_t register_id);
void process_add(process_t **head, process_t *to_add);
process_t *process_copy(process_t *head);
int process_read_instruction(process_t *process, arena_t *arena);
int process_get_arg_type(process_t *process, arena_t *arena, int64_t arg_id);
int64_t process_get_arg_size(process_t *process, arena_t *arena,
    int64_t arg_type);
int64_t process_get_arg_value(process_t *process, arena_t *arena,
    int64_t arg_id);
int create_process(args_t *);


void arena_write(arena_t *arena, int64_t pos, uint8_t n, int64_t value);
int64_t arena_read(arena_t *arena, int64_t pos, uint8_t n);
arena_t *arena_create(void);
void arena_destroy(arena_t *arena);
int arena_update(arena_t *arena);
bool arena_is_end(arena_t *arena);
int arena_play_cycle(arena_t *arena);
int create_arena(process_t *champions, args_t *args);

int corewar_loop(arena_t *);

void *my_memset(char *, char, int64_t);
void *my_memcpy(void *dest, void *src, int64_t n);
int my_strcmp(char const *s1, char const *s2);
bool my_is_num(char const *);
int my_atoi(char const *);
int my_strlen(char const *);
char *my_strcat(char *, char const *);
uint8_t my_revbyte_8(uint8_t num);
uint16_t my_revbyte_16(uint16_t num);
uint32_t my_revbyte_32(uint32_t num);

typedef void(*instruction_f_t)(process_t *, arena_t *);

typedef struct instruction_s {
    uint8_t code;
    instruction_f_t f;
} instruction_t;

void instruction_live(process_t *process, arena_t *arena);
void instruction_ld(process_t *process, arena_t *arena);
void instruction_st(process_t *process, arena_t *arena);
void instruction_add(process_t *process, arena_t *arena);
void instruction_sub(process_t *process, arena_t *arena);
void instruction_and(process_t *process, arena_t *arena);
void instruction_or(process_t *process, arena_t *arena);
void instruction_xor(process_t *process, arena_t *arena);
void instruction_zjmp(process_t *process, arena_t *arena);
void instruction_ldi(process_t *process, arena_t *arena);
void instruction_sti(process_t *process, arena_t *arena);
void instruction_fork(process_t *process, arena_t *arena);
void instruction_lld(process_t *process, arena_t *arena);
void instruction_lldi(process_t *process, arena_t *arena);
void instruction_lfork(process_t *process, arena_t *arena);
void instruction_aff(process_t *process, arena_t *arena);

static instruction_t const instructions[] = {
    {0x01, instruction_live},
    {0x02, instruction_ld},
    {0x03, instruction_st},
    {0x04, instruction_add},
    {0x05, instruction_sub},
    {0x06, instruction_and},
    {0x07, instruction_or},
    {0x08, instruction_xor},
    {0x09, instruction_zjmp},
    {0x0a, instruction_ldi},
    {0x0b, instruction_sti},
    {0x0c, instruction_fork},
    {0x0d, instruction_lld},
    {0x0e, instruction_lldi},
    {0x0f, instruction_lfork},
    {0x10, instruction_aff},
    {0x00, NULL}
};

int display_help(int, char **, char const *);
