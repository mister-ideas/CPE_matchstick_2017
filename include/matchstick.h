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

/* matchstick.c */

/* display.c */

void display_stars_line(int chars);
void display_matches_line(int *map, int chars, int i, int j);
void display_map(int lines, int chars, int line, int matches);

#endif
