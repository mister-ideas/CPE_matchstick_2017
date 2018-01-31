/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.c
*/

#include "matchstick.h"

void stars_line(int chars)
{
	for (int i = 0; i < chars; i++)
		my_putchar('*');
	my_putchar('\n');
}

void matches_line(int *map, int chars, int i, int j)
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

void display_map(int lines, int chars)
{
	int map[lines];
	int j = 0;

	lines += 2;
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1)
			map[i] = -1;
		else
			map[i] = 2 * i - 1;
	}
	for (int i = 0; i < lines; i++) {
		if (map[i] == -1)
			stars_line(chars);
		else {
			matches_line(map, chars, i, j);
			j++;
		}
	}
}

int main(int ac, char **av)
{
	int lines;
	int matches;
	int chars;

	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches>\n", 38);
		return (84);
	}
	lines = my_getnbr(av[1]);
	if (lines < 1 || lines > 99)
		return (84);
	matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (matches < 1 || matches > chars - 2)
		return (84);
	display_map(lines, chars);
	return (0);
}
