/*
** EPITECH PROJECT, 2024
** my_revbyte.c
** File description:
** my_revbyte.c
*/

#include "my.h"

void reverse_bytes(uint8_t *arr, size_t size)
{
    uint8_t tmp = 0;

    for (size_t i = 0; i < size / 2; i++) {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}
