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

int check_end(int player, int *map, int lines)
{
	int total = 0;

	for (int i = 1; i < lines - 1; i++)
		total += map[i];
	if (total == 0) {
		switch (player) {
		case 2:
			my_putstr(IA_LOST);
			return (1);
		case 1:
			my_putstr(PLAYER_LOST);
			return (2);
		}
	}
	return (0);
}

int game_loop(int *map, int lines, int chars, int max_matches)
{
	display_map(map, lines, chars);
	while (1) {
		player_turn(map, lines, chars, max_matches);
		if (check_end(1, map, lines) == 2) {
			free(map);
			return (2);
		}
		ia_turn(map, lines, chars, max_matches);
		if (check_end(2, map, lines) == 1) {
			free(map);
			return (1);
		}
	}
	return (0);
}

int game_init(char **av)
{
	int *map;
	int lines;
	int max_matches;
	int chars;

	lines = my_getnbr(av[1]);
	if (lines < 1 || lines > 99)
		return (-1);
	map = malloc(sizeof(int) * (lines + 2));
	max_matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (max_matches < 1)
		return (-1);
	lines += 2;
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1)
			map[i] = -1;
		else
			map[i] = 2 * i - 1;
	}
	if (game_loop(map, lines, chars, max_matches) == 1)
		return (1);
	else
		return (2);
	return (0);
}

int main(int ac, char **av)
{
	int return_val;

	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches>\n", 38);
		return (84);
	}
	srand(time(NULL));
	return_val = game_init(av);
	switch (return_val) {
	case -1:
		return (84);
	case 1:
		return (1);
	case 2:
		return (2);
	}
	return (0);
}
