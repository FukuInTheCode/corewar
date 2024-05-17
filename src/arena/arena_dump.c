/*
** EPITECH PROJECT, 2024
** arena_dump.c
** File description:
** arena_dump.c
*/

#include "my.h"

static void dump_it(uint8_t value)
{
    char hexString[2] = {0};
    const char hexDigits[] = "0123456789ABCDEF";

    hexString[0] = hexDigits[(value >> 4) & 0x0F];
    hexString[1] = hexDigits[value & 0x0F];
    write(STDOUT_FILENO, hexString, 2);
}

void arena_dump(uint8_t binary[], size_t size)
{
    for (size_t i = 0; i < size; i += 32) {
        for (size_t j = i; j < i + 32 && j < size; j++) {
            dump_it(binary[j]);
        }
        write(1, "\n", 1);
    }
}
