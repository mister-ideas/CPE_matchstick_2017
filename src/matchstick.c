/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.c
*/

#include "matchstick.h"

void free_map(char **map, int lines)
{
	for (int i = 0; i < lines; i++)
		free(map[i]);
	free(map);
}

void create_map(int lines, int chars)
{
	int center = chars / 2;
	char **map = malloc(sizeof(char*) * lines);

	for (int i = 0; i < lines; i++)
		map[i] = malloc(sizeof(char) * chars);
	free_map(map, lines);
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
	lines = my_getnbr(av[1]) + 2;
	if (lines < 1 || lines > 99)
		return (84);
	matches = my_getnbr(av[2]);
	chars = lines * 2 + 2;
	if (matches < 1 || matches > chars - 2)
		return (84);
	create_map(lines, chars);
	return (0);
}
