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

	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches_per_turn>\n", 47);
		return (84);
	}
	lines = my_getnbr(av[1]);
	matches = my_getnbr(av[2]);
	return (0);
}
