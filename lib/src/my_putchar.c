/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
