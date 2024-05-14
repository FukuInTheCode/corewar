/*
** EPITECH PROJECT, 2024
** check_binary.c
** File description:
** check_binary.c
*/

#include "my.h"
#include "op.h"

static bool check_prog_size(header_t *data)
{
    if (data->prog_size < MEM_SIZE)
        return true;
    return false;
}

static bool check_comment(header_t *data)
{
    if (data->comment[COMMENT_LENGTH] == 0)
        return true;
    return false;
}

static bool check_prog_name(header_t *data)
{
    if (data->prog_name[PROG_NAME_LENGTH] == 0)
        return true;
    return false;
}

int check_binary(char *filename)
{
    FILE *file = fopen(filename, "rb");
    header_t data;

    if (file == NULL)
        return 84;
    if (fread(&data, sizeof(header_t), 1, file) != -1) {
        fclose(file);
        return 84;
    }
    if (!check_prog_name(&data) || !check_comment(&data)
        || !check_prog_size(&data)) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}
