/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include "map.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **str = malloc(sizeof(char *) * (nb_cols + 1));
    int i = 0;

    str[nb_cols] = NULL;
    while (i != nb_cols){
        str[i] = malloc(sizeof(char) * (nb_rows + 1));
        str[i][nb_rows] = '\0';
        i++;
    }
    return (str);
}

char **load_my_map(void)
{
    char **map = mem_alloc_2d_array(8, 8);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i <= 7){
        j = 0;
        while (j <= 7){
            map[i][j] = '.';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    return map;
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char **arr = mem_alloc_2d_array(nb_rows, nb_cols);
    struct stat sb;
    stat(filepath, &sb);
    int size = sb.st_size;
    char buffer[size * 2];
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, size);
    int i = 0;
    int j = 0;
    int y = 0;
    while (i != nb_cols){
        j = 0;
        while (j != nb_rows){
            arr[i][j] = buffer[y];
            j++;
            y++;
        }arr[i][j] = '\0';
        i++;
    }arr[i] = NULL;
    return (arr);
}

char **load_boat_in_map(char **coord, char **map)
{
    int i = 0;
    int j = 0;

    while (i < 4){
        if (put_in_map(i, coord, map) == 84)
            return NULL;
        i++;
    }
    return map;
}

int my_strlen_for_map(char const *str)
{
    int bobo = 0;

    while (str[bobo] != '\0' && str[bobo] != '\n'){
        bobo = bobo + 1;
    }
    return (bobo);
}