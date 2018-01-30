/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.c
*/

#include "matchstick.h"

void display_map(int lines, int chars)
{
	int map[lines];
	int j = 0;

	lines += 2;
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1)
			map[i] = 0;
		else
			map[i] = 2 * i - 1;
	}
	for (int i = 0; i < lines; i++) {
		if (map[i] == 0) {
			for (int i = 0; i < chars; i++)
				my_putchar('*');
			my_putchar('\n');
		} else {
			my_putchar('*');
			for (int i = 0; i < (chars - 2) / 2 - j; i++)
				my_putchar(' ');
			for (int k = 0; k < map[i]; k++)
				my_putchar('|');
			my_putchar('\n');
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
		write(2, "Usage: ./matchstick <lines> <matches_per_turn>\n", 47);
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
