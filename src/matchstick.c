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

void player_turn(int *map, int lines, int chars, int max_matches)
{
	int line;
	int matches;
	int nb = 0;
	int status = 0;

	my_putstr("\nYour turn:\n");
	while (status == 0) {
		nb = read_input("Line: ");
		if (nb != -1) {
			line = nb;
			if (line > 0 && line <= lines)
				status = 1;
			else
				my_putstr("Error: this line is out of range\n");
		} else
			my_putstr("Error: invalid input (positive number expected)\n");
	}
	while (status == 1) {
		nb = read_input("Matches: ");
		if (nb != -1) {
			matches = nb;
			if (matches > max_matches) {
				my_putstr("Error: you cannot remove more than ");
				my_put_nbr(max_matches);
				my_putstr(" matches per turn\n");
			} else if (matches > map[line])
				my_putstr("Error: not enough matches on this line\n");
			else if (matches == 0)
				my_putstr("Error: you have to remove at least one match\n");
			else
				status = 2;
		} else
			my_putstr("Error: invalid input (positive number expected)\n");
	}
	map[line] -= matches;
	my_putstr("Player removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	display_map(map, lines, chars);
}

int main(int ac, char **av)
{
	int lines;
	int max_matches;
	int chars;

	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches>\n", 38);
		return (84);
	}
	lines = my_getnbr(av[1]);
	if (lines < 1 || lines > 99)
		return (84);
	int map[lines];
	max_matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (max_matches < 1 || max_matches > chars - 2)
		return (84);
	lines += 2;
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1)
			map[i] = -1;
		else
			map[i] = 2 * i - 1;
	}
	display_map(map, lines, chars);
	while (1)
		player_turn(map, lines, chars, max_matches);
	return (0);
}
