/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#ifndef MAP_H
#define MAP_H

#include "navy.h"
#include "state_machine.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **change_coord(char **coord_boat);
int replace_point(int i, int j, char **map, char **coord);
int put_in_map(int i, char **coord, char **map);
char **load_map(char *name);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **load_my_map(void);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
char **load_boat_in_map(char **coord, char **map);
int my_strlen_for_map(char const *str);
char **load_map_from_file(char *name);

#endif //MAP_H
