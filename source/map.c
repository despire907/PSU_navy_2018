/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include "map.h"

char **change_coord(char **coord_boat)
{
    int i = 0;
    int j = 0;

    while (coord_boat[i] != NULL){
        j = 0;
        while (coord_boat[i][j] != '\0') {
            if (coord_boat[i][j] < 91 && coord_boat[i][j] > 64)
                coord_boat[i][j] = coord_boat[i][j] - 16;
            j++;
        }
        i++;
    }
    return coord_boat;
}

int replace_point(int i, int j, char **map, char **co)
{
    int pos = 2;
    int neg = 0;
    while (j > 0) {
        if (co[i][2] - co[i][5] == 0) {
            if (co[i][3] - co[i][6] > 0) {
                map[(co[i][3] - 48) - pos][(co[i][2] - 48) - 1] = co[i][0];
            } else if (co[i][3] - co[i][6] < 0) {
                map[(co[i][3] - 48) + neg][(co[i][2] - 48) - 1] = co[i][0];
            }
        } else if (co[i][3] - co[i][6] == 0) {
            if (co[i][2] - co[i][5] > 0) {
                map[(co[i][3] - 48) - 1][(co[i][2] - 48) - pos] = co[i][0];
            } else if (co[i][2] - co[i][5] < 0) {
                map[(co[i][3] - 48) - 1][(co[i][2] - 48) + neg] = co[i][0];
            }
        } else
            return 84;
        neg++;
        pos++;
        j--;
    } return 0;
}

int put_in_map(int i, char **coord, char **map)
{
    if (i == 0) {
        map[(coord[i][3] - 1) - 48][(coord[i][2] - 1) - 48] = coord[0][0];
        map[(coord[i][6] - 1) - 48][(coord[i][5] - 1) - 48] = coord[0][0];
        if (replace_point(i, i, map, coord) == 84)
            return 84;
    }if (i == 1) {
        map[(coord[i][3] - 1) - 48][(coord[i][2] - 1) - 48] = coord[1][0];
        map[(coord[i][6] - 1) - 48][(coord[i][5] - 1) - 48] = coord[1][0];
        if (replace_point(i, i, map, coord) == 84)
            return 84;
    }if (i == 2) {
        map[(coord[i][3] - 1) - 48][(coord[i][2] - 1) - 48] = coord[2][0];
        map[(coord[i][6] - 1) - 48][(coord[i][5] - 1) - 48] = coord[2][0];
        if (replace_point(i, i, map, coord) == 84)
            return 84;
    }if (i == 3) {
        map[(coord[i][3] - 1) - 48][(coord[i][2] - 1) - 48] = coord[3][0];
        map[(coord[i][6] - 1) - 48][(coord[i][5] - 1) - 48] = coord[3][0];
        if (replace_point(i, i, map, coord) == 84)
            return 84;
    }
    return 0;
}

int check_coord(char **coord_boat)
{
    int i = 0;

    while (coord_boat[i] != NULL){
        if (my_strlen_for_map(coord_boat[i]) != 7 || coord_boat[i][1] != ':' ||
        coord_boat[i][4] != ':')
            return 84;
        else if (coord_boat[0][0] != '2' || coord_boat[1][0] != '3' ||
        coord_boat[2][0] != '4' || coord_boat[3][0] != '5')
            return 84;
        if ((coord_boat[i][2] < 'A' || coord_boat[i][2] > 'H') ||
        (coord_boat[i][3] < '1' || coord_boat[i][3] > '8'))
            return 84;
        else if ((coord_boat[i][5] < 'A' || coord_boat[i][5] > 'H') ||
        (coord_boat[i][6] < '1' || coord_boat[i][6] > '8'))
            return 84;
        i++;
    }
    return 0;
}

char **load_map_from_file(char *name)
{
    int i = 0;
    char **coord;
    char **map_boat;
    char **map = load_my_map();
    char **coord_boat = load_2d_arr_from_file(name, 8, 4);
    int j = check_coord(coord_boat);
    if (j == 0) {
        coord = change_coord(coord_boat);
        map_boat = load_boat_in_map(coord, map);
        if (map_boat == NULL) {
            while (map[i] != NULL) {
                free(map[i]);
                i++;
            } return NULL;
        }
    }else {
        while (map[i] != NULL) {
            free(map[i]);
            i++;
        } return NULL;
    } return map;
}