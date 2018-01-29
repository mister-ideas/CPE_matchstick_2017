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
	int chars;
	int matches;

	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches_per_turn>\n", 47);
		return (84);
	}
	lines = my_getnbr(av[1]);
	if (lines < 1)
		return (84);
	chars = lines * 2 + 2;
	matches = my_getnbr(av[2]);
	if (matches > chars - 2)
		return (84);
	return (0);
}
