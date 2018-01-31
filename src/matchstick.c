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

int check_line(int status, int line, int lines)
{
	if (line != -1) {
		if (line > 0 && line <= lines)
			status = 1;
		else
			my_putstr(OUT_OF_RANGE);
	} else
		my_putstr(INVALID_INPUT);
	return (status);
}

int check_matches(int status, int *map, int line, int matches, int max_matches)
{
	if (matches != -1) {
		if (matches > max_matches) {
			my_putstr("Error: you cannot remove more than ");
			my_put_nbr(max_matches);
			my_putstr(" matches per turn\n");
		} else if (matches > map[line])
			my_putstr(TOO_HIGH);
		else if (matches == 0)
			my_putstr(AT_LEAST_ONE);
		else
			status = 2;
	} else
		my_putstr(INVALID_INPUT);
	return (status);
}
		   
void player_turn(int *map, int lines, int chars, int max_matches)
{
	int line;
	int matches;
	int status = 0;
	int nb;

	my_putstr("\nYour turn:\n");
	while (status == 0) {
		nb = read_input("Line: ");
		line = nb;
		status = check_line(status, line, lines);
	}
	while (status == 1) {
		nb = read_input("Matches: ");
		matches = nb;
		status = check_matches(status, map, line, matches, max_matches);
	}
	map[line] -= matches;
	my_putstr("Player removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	display_map(map, lines, chars);
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
