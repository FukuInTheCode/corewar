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
    reverse_bytes((void *)&data->prog_size, 4);
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

bool is_extension(const char *extension, const char *filename)
{
    size_t ext_len = my_strlen(extension);
    size_t file_len = my_strlen(filename);

    if (file_len < ext_len)
        return false;
    return my_strcmp(filename + file_len - ext_len, extension) == 0;
}

int check_binary(char *filename)
{
    FILE *file = fopen(filename, "rb");
    header_t data;

    if (file == NULL)
        return 84;
    if (fread(&data, sizeof(header_t), 1, file) == (size_t)-1) {
        fclose(file);
        return 84;
    }
    if (!is_extension(".cor", filename))
        return 84;
    if (!check_prog_name(&data) || !check_comment(&data)
        || !check_prog_size(&data)) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}
