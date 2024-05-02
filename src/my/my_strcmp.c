/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** function for compare two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (int)((unsigned char)*s1 - (unsigned char)*s2);
}
