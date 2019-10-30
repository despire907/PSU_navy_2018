/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include "my.h"
#include "navy.h"
#include "map.h"

char **init_target_map(char **map)
{
    int i = 0;
    int j;

    while (i < 8) {
        j = 0;
        while (j < 8) {
            map[i][j] = map_void;
            ++j;
        }
        ++i;
    }
    return map;
}

void my_put_header(void)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
}

void dysplay_first_map(char **map)
{
    int i = 0;
    int j = 0;
    int nb = 1;

    my_put_header();
    while (map[i] != NULL) {
        j = 0;
        while (map[i][j] != '\0') {
            if (j == 0) {
                my_putchar(nb + 48);
                my_putchar('|');
            }
            my_putchar(map[i][j]);
            my_putchar(' ');
            j++;
        }
        nb++;
        my_putchar('\n');
        i++;
    }
    my_putchar('\n');
}

int display_map(char **map, char **target_map)
{
    my_putstr("my positions:\n");
    dysplay_first_map(map);
    my_putstr("enemy's positions:\n");
    dysplay_first_map(target_map);
    return 1;
}