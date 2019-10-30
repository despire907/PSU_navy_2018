/*
** EPITECH PROJECT, 2018
** fs_open_file.c
** File description:
** open_file
*/

#include <unistd.h>
#include "my.h"

void process_info(void)
{
    int pid = getpid();

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
}