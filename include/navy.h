/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#ifndef PSU_NAVY_2018_NAVY_H
#define PSU_NAVY_2018_NAVY_H

#include <stdio.h>

typedef enum map_chars{map_void = '.', map_ship2 = '2', map_ship3 = '3',
                       map_ship4 = '4', map_ship5 = '5', map_missed = 'o',
                       map_gotcha = 'x'} t_map_char;

void my_putchar(char c);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int get_next_shot(char **map);
int display_map(char **map, char **target_map);
char **init_target_map(char **map);
int navy_shot(int target, char **map);
int shot_is_landed(int target, char **map);
#endif //PSU_NAVY_2018_NAVY_H
