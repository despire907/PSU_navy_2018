/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include "navy.h"
#include "state_machine.h"

void dysplay_h(void)
{
    my_putstr("USAGE\n"
                "\t./navy [first_player_pid] navy_positions\n"
                "DESCRIPTION\n"
                "\tfirst_player_pid:  only for the 2nd player.  pid of the "
                "first player.\n"
                "\tnavy_positions:  file representing the positions of the "
                "ships.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        dysplay_h();
    return state_machine(ac, av);
}