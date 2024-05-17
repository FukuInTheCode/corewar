/*
** EPITECH PROJECT, 2024
** create_process.c
** File description:
** create_process.c
*/

#include "my.h"

static int read_file(FILE *file, process_t *new)
{
    header_t data;

    if (fread(&data, sizeof(header_t), 1, file) == (size_t)-1) {
        free(new);
        return 84;
    }
    my_strcat(new->name, data.prog_name);
    my_strcat(new->comment, data.comment);
    new->binary_size = data.prog_size;
    new->binary_size = my_revbyte_32(new->binary_size);
    fread(new->binary, MEM_SIZE, 1, file);
    return 0;
}

static int open_file(char *filename, process_t **head)
{
    FILE *file = NULL;
    process_t *new = NULL;

    new = process_create();
    if (new == NULL)
        return 84;
    process_add(head, new);
    file = fopen(filename, "rb");
    if (file == NULL) {
        free(new);
        return 84;
    }
    read_file(file, new);
    fclose(file);
    return 0;
}

static void free_all(process_t *head)
{
    process_t *tmp = NULL;

    for (; head; head = tmp) {
        tmp = head->next;
        process_destroy(head);
    }
}

int create_process(args_t *args)
{
    process_t *head = NULL;

    if (args == NULL)
        return 84;
    for (int i = 0; i < args->proccess_n; i++) {
        if (open_file(args->processes[i].filename, &head) == 84) {
            free_all(head);
            return 84;
        }
    }
    return create_arena(head, args);
}
