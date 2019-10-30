/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "signal_utils.h"

int send_signal(char key, int target)
{
    int i = 0;

    while (i < 8) {
        if (key & 1)
            kill(target, SIGUSR2);
        else
            kill(target, SIGUSR1);
        key = key >> 1;
        usleep(1000);
        ++i;
    }
}