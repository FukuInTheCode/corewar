/*
** EPITECH PROJECT, 2024
** handle_args.c
** File description:
** handle_args.c
*/

#include "my.h"

static int handle_no_flags(char *filename, args_t *args)
{
    if (args->proccess_n == 4 || !filename)
        return 84;
    args->processes[args->proccess_n].filename = filename;
    args->proccess_n++;
    if (check_binary(filename) == 84)
        return 84;
    return 0;
}

static int handle_process_args(int argc, char **argv, uint8_t *i, args_t *args)
{
    if (my_strcmp("-n", argv[*i]) && my_strcmp("-a", argv[*i]))
        return handle_no_flags(argv[*i], args);
    if (!my_strcmp("-n", argv[*i])) {
        if (*i + 1 >= argc || !my_is_num(argv[*i + 1]) ||
            args->proccess_n == 4)
            return 84;
        args->processes[args->proccess_n].id = my_atoi(argv[*i + 1]);
        *i += 2;
    }
    if (!my_strcmp("-a", argv[*i])) {
        if (*i + 1 >= argc || !my_is_num(argv[*i + 1]) ||
            args->proccess_n == 4)
            return 84;
        args->processes[args->proccess_n].address = my_atoi(argv[*i + 1]);
        *i += 2;
    }
    return handle_no_flags(argv[*i], args);
}

static int handle_arg(int argc, char **argv, uint8_t *i, args_t *args)
{
    if (!my_strcmp("-dump", argv[*i])) {
        if (args->dump != -1 || (*i) + 1 >= argc || !my_is_num(argv[*i + 1]))
            return 84;
        args->dump = my_atoi(argv[*i]);
        *i += 1;
        return 0;
    }
    return handle_process_args(argc, argv, i, args);
}

int handle_args(int argc, char **argv)
{
    args_t args = {.dump = -1, .proccess_n = 0};

    if (argc == 1 || argc > 23)
        return 84;
    for (uint8_t i = 0; i < 4; i++) {
        args.processes[i].id = 0;
        args.processes[i].filename = NULL;
        args.processes[i].address = 0;
    }
    for (uint8_t i = 1; i < argc; i++) {
        if (handle_arg(argc, argv, &i, &args))
            return 84;
    }
    if (create_process(&args) == 84)
        return 84;
    return 0;
}
