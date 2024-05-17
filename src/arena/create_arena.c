/*
** EPITECH PROJECT, 2024
** create_arena.c
** File description:
** create_arena.c
*/

#include "my.h"
#include "op.h"

int create_arena(process_t *champions, args_t *args)
{
    arena_t *arena = NULL;

    if (!champions || !args || args->proccess_n <= 1)
        return 84;
    arena = arena_create();
    if (!arena)
        return 84;
    arena->champions = champions;
    for (size_t i = 0; i < args->proccess_n; i++) {
        printf("%zu, %d\n", i * (MEM_SIZE / args->proccess_n), MEM_SIZE);
        printf("%zu\n", champions->binary_size);
        my_memcpy(arena->arena + i * (MEM_SIZE / args->proccess_n),
            champions->binary, champions->binary_size);
        champions->PC = i * (MEM_SIZE / args->proccess_n);
        champions = champions->next;
    }
    my_memcpy(arena->arena_copy, arena->arena , MEM_SIZE);
    return corewar_loop(arena);
}
