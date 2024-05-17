/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** RETURN
*/

#include "my.h"

int my_put_nbr(int nb)
{
    unsigned int count = nb;

    if (nb < 0) {
        my_putchar('-');
        count = -nb;
    }
    if (count > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(count + '0');
    return 0;
}
