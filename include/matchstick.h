/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

#define INVALID_INPUT "Error: invalid input (positive number expected)\n"
#define OUT_OF_RANGE "Error: this line is out of range\n"
#define AT_LEAST_ONE "Error: you have to remove at least one match\n"
#define TOO_HIGH "Error: not enough matches on this line\n"

/* matchstick.c */

int read_input(char *input);
int game_loop(char **av);

/* display.c */

void display_stars_line(int chars);
void display_matches_line(int *map, int chars, int i, int j);
void display_map(int *map, int lines, int chars);

/* player.c */

int check_line(int status, int line, int lines);
int check_matches(int status, int *map, int line, int matches, int max_matches);
void finished_player_turn(int line, int matches);
void player_turn(int *map, int lines, int chars, int max_matches);

#endif
