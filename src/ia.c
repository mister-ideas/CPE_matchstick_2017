/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** ia.c
*/

#include "matchstick.h"

void finished_ia_turn(int line, int matches)
{
	my_putstr("AI removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
}

void ia_turn(int *map, int lines, int chars, int max_matches)
{
	int line = (random() % lines) + 1;
	int matches = (random() % max_matches) + 1;
	int error = 1;

	my_putstr("\nAI's turn...\n");
	while (error == 1) {
		if (line > lines - 2)
			line = lines - 1;
		if (matches > map[line]) {
			line = (random() % lines) + 1;
			matches = (random() % max_matches) + 1;
		} else
			error = 0;
	}
	map[line] -= matches;
	finished_ia_turn(line, matches);
	display_map(map, lines, chars);
}
