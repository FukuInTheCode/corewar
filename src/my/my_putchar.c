/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** RETURN
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
