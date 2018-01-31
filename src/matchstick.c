/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.c
*/

#include "matchstick.h"

void player_turn(void)
{
	char temp[12];
	int line;
	int matches;
	int status = 0;
	int i = 0;

	my_putstr("\nYour turn:\n");
	while (status == 0) {
		my_putstr("Line: ");
		 i = read(0, temp, 12);
		 temp[i] = '\0';
		 line = my_getnbr(temp);
	}
}

int main(int ac, char **av)
{
	int lines;
	int matches;
	int chars;

	if (ac != 3) {
		write(2, "Usage: ./matchstick <lines> <matches>\n", 38);
		return (84);
	}
	lines = my_getnbr(av[1]);
	if (lines < 1 || lines > 99)
		return (84);
	matches = my_getnbr(av[2]);
	chars = lines * 2 + 1;
	if (matches < 1 || matches > chars - 2)
		return (84);
	display_map(lines, chars);
	player_turn();
	return (0);
}
