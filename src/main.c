/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv)
{
    int return_value = display_help(argc, argv, "src/assets/help.txt");

    if (return_value == 1)
        return 0;
    if (return_value == 84)
        return 84;
    return handle_args(argc, argv);
}
