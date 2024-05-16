/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** RETURN
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = 0;
    int i;

    while (dest[dest_len] != '\0')
        dest_len++;
    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
