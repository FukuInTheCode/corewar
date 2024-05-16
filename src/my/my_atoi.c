/*
** EPITECH PROJECT, 2024
** my_atoi.c
** File description:
** my_atoi.c
*/

#include "my.h"

int my_atoi(char const *s)
{
    int64_t result = 0;

    for (int64_t i = *s == '-' || *s == '+'; s[i]; i++)
        result = 10 * result + s[i] - '0';
    return result * (1 - 2 * (*s == '-'));
}
