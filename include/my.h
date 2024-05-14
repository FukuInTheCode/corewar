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

int my_strcmp(char const *s1, char const *s2);
bool my_is_num(char const *);
int my_atoi(char const *);
