/*
** EPITECH PROJECT, 2024
** my_is_num.c
** File description:
** my_is_num.c
*/

#include "my.h"

bool my_is_num(char const *s)
{
    for (int64_t i = 0; s[i]; i++)
        if (!('0' <= s[i] && s[i] <= '9'))
            return false;
    return true;
}
