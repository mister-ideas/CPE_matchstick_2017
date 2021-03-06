/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** display.c
*/

#include "matchstick.h"

void display_stars_line(int chars)
{
	for (int i = 0; i < chars; i++)
		my_putchar('*');
	my_putchar('\n');
}

void display_matches_line(int *map, int chars, int i, int j)
{
	int k = 0;

	my_putchar('*');
	for (int i = 0; i < (chars - 2) / 2 - j; i++) {
		my_putchar(' ');
		k++;
	}
	for (int j = 0; j < map[i]; j++)
		my_putchar('|');
	for (int j = 0; j < chars - k - map[i] - 2; j++)
		my_putchar(' ');
	my_putchar('*');
	my_putchar('\n');
}

void display_map(int *map, int lines, int chars)
{
	int j = 0;

	for (int i = 0; i < lines; i++) {
		if (map[i] == -1)
			display_stars_line(chars);
		else {
			display_matches_line(map, chars, i, j);
			j++;
		}
	}
}
