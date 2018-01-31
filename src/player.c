/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** player.c
*/

#include "matchstick.h"

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
	status = 0;
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

void finished_turn(int line, int matches)
{
	my_putstr("Player removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
}

void player_turn(int *map, int lines, int chars, int max_matches)
{
	int line;
	int matches;
	int status = 0;
	int nb;

	my_putstr("\nYour turn:\n");
	while (status != 2) {
		nb = read_input("Line: ");
		line = nb;
		status = check_line(status, line, lines);
		if (status == 1) {
			nb = read_input("Matches: ");
			matches = nb;
			status = check_matches(status, map, line,
			matches, max_matches);
		}
	}
	map[line] -= matches;
	finished_turn(line, matches);
	display_map(map, lines, chars);
}
