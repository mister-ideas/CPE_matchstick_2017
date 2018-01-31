/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.c
*/

#include "matchstick.h"

int read_input(char *input)
{
	char temp[4096];
	int i = 0;

	my_putstr(input);
	i = read(0, temp, 4096);
	temp[i] = '\0';
	if (my_str_isnum(temp) == 0)
		return (-1);
	return (my_getnbr(temp));
}

int game_loop(char **av)
{
	int *map;
	int lines;
	int max_matches;
	int chars;

	lines = my_getnbr(av[1]);
	if (lines < 1 || lines > 99)
		return (1);
	map = malloc(sizeof(int) * lines);
	max_matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (max_matches < 1 || max_matches > chars - 2)
		return (1);
	lines += 2;
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1)
			map[i] = -1;
		else
			map[i] = 2 * i - 1;
	}
	display_map(map, lines, chars);
	player_turn(map, lines, chars, max_matches);
	free(map);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches>\n", 38);
		return (84);
	}
	if (game_loop(av) == 1)
		return (84);
	return (0);
}
