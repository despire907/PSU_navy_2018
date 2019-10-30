/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"
#include "signal_utils.h"

int check_player_entry(char *entry, char **map) {
    int target;

    if (my_strlen(entry) != 3) {
        return -1;
    }
    if (*entry < 'A' || *entry > 'H' || entry[1] < '1' || entry[1] > '8') {
        my_putstr("Invalid characters\n");
        return -1;
    }
    target = (entry[1] - '1') * 8 + entry[0] - 'A';
    if (map[entry[1] - '1'][entry[0] - 'A'] == '.')
        return target;
    return -1;
}

int get_next_shot(char **map)
{
    char buffer[5];
    int status = -1;
    ssize_t size = 1;

    while (status == -1) {
        my_putstr("attack:\t");
        size = read(0, &buffer, 4);
        if (size < 0)
            return -1;
        buffer[size] = '\0';
        status = check_player_entry(buffer, map);
        if (status == -1)
            my_putstr("wrong position\n");
    }
}

int navy_shot(int target, char **map) {
    g_sigkey.key = sig_null;
    send_signal((char) (target + 1), g_sigkey.emitter);
    while (g_sigkey.key == sig_null) {
        usleep(1000);
    }
    my_putchar((char) (target % 8 + 'A'));
    my_putchar((char) (target / 8 + '1'));
    if (g_sigkey.key == sig_shot) {
        my_putstr(": hit\n\n");
        map[target / 8][target % 8] = map_gotcha;
    } else if (g_sigkey.key == sig_miss) {
        my_putstr(": missed\n\n");
        map[target / 8][target % 8] = map_missed;
    } else
        return 0;
    return 1;
}

int shot_is_landed(int target, char **map)
{
    int x = target % 8;
    int y = target / 8;

    my_putchar((char) (x + 'A'));
    my_putchar((char) (y + '1'));
    if (map[y][x] != '.' && map[y][x] != 'o' && map[y][x] != 'x') {
        map[y][x] = map_gotcha;
        my_putstr(": hit\n\n");
        return 1;
    } else {
        map[y][x] = map_missed;
        my_putstr(": missed\n\n");
    }
    return 0;
}