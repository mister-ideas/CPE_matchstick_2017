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

void player_turn(int lines, int max_matches)
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
			if (matches >= max_matches && matches <= max_matches)
				status = 2;
			else {
				my_putstr("Error: you cannot remove more than ");
				my_put_nbr(max_matches);
				my_putstr(" matches per turn\n");
			}	
		} else
			my_putstr("Error: invalid input (positive number expected)\n");
	}
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
	max_matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (max_matches < 1 || max_matches > chars - 2)
		return (84);
	display_map(lines, chars);
	player_turn(lines, max_matches);
	return (0);
}
