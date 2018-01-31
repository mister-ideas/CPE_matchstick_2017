/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.c
*/

#include "matchstick.h"

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
