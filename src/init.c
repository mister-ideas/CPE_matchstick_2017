/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** init.c
*/

#include "matchstick.h"

void map_init(int *map, int lines)
{
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1)
			map[i] = -1;
		else
			map[i] = 2 * i - 1;
	}
}

int game_init(char **av)
{
	int *map;
	int lines;
	int max_matches;
	int chars;
	int return_val;

	lines = my_getnbr(av[1]);
	if (lines < 1 || lines > 99)
		return (-1);
	map = malloc(sizeof(int) * (lines + 2));
	max_matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (max_matches < 1)
		return (-1);
	lines += 2;
	map_init(map, lines);
	return_val = game_loop(map, lines, chars, max_matches);
	switch (return_val) {
	case 1:
		return (1);
	case 2:
		return (2);
	case 0:
		return (0);
	}
	return (3);
}
