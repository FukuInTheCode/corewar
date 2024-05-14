/*
** EPITECH PROJECT, 2024
** my_atoi.c
** File description:
** my_atoi.c
*/

#include "my.h"

int my_atoi(char const *s)
{
    size_t result = 0;

    for (size_t i = *s == '-' || *s == '+'; s[i]; i++)
        result = 10 * result + s[i] - '0';
    return result * (1 - 2 * (*s == '-'));
}
