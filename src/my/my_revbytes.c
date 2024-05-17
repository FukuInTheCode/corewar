/*
** EPITECH PROJECT, 2024
** my_revbyte.c
** File description:
** my_revbyte.c
*/

#include "my.h"

uint8_t my_revbyte_8(uint8_t num)
{
    uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        result |= ((num >> i) & 1) << (7 - i);
    }
    return result;
}

uint16_t my_revbyte_16(uint16_t num)
{
    return (num << 8) | (num >> 8);
}

uint32_t my_revbyte_32(uint32_t num)
{
    return ((num & 0xFF) << 24) | (((num >> 8) & 0xFF) << 16)
        | (((num >> 16) & 0xFF) << 8) | ((num >> 24) & 0xFF);
}
