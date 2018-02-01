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
#include <time.h>
#include "my.h"

#define USAGE "Usage: ./matchstick <lines> <matches>\n"
#define INVALID_INPUT "Error: invalid input (positive number expected)\n"
#define OUT_OF_RANGE "Error: this line is out of range\n"
#define AT_LEAST_ONE "Error: you have to remove at least one match\n"
#define TOO_HIGH "Error: not enough matches on this line\n"
#define IA_LOST "I lost... snif... but I'll get you next time!!\n"
#define PLAYER_LOST "You lost, too bad...\n"

/* matchstick.c */

int read_input(char *input);
int check_end(int player, int *map, int lines);
int game_loop(int *map, int lines, int chars, int max_matches);

/* init.c */

void map_init(int *map, int lines);
int game_init(char **av);

/* display.c */

void display_stars_line(int chars);
void display_matches_line(int *map, int chars, int i, int j);
void display_map(int *map, int lines, int chars);

/* player.c */

int check_line(int line, int lines);
int check_matches(int *map, int line, int matches, int max_matches);
void finished_player_turn(int line, int matches);
int player_turn(int *map, int lines, int chars, int max_matches);

/* ia.c */

void finished_ia_turn(int line, int matches);
void ia_turn(int *map, int lines, int chars, int max_matches);

#endif
