/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include <unistd.h>
#include "signal_utils.h"
#include "my.h"

int connect_to_server(int server_pid)
{
    int nb = 0;

    g_sigkey.key = sig_null;
    send_signal(sig_is_server, server_pid);
    while (g_sigkey.key == sig_null && nb < 50) {
        usleep(10000);
        ++nb;
    }
    if (g_sigkey.key == sig_i_am_server)
        my_putstr("Successfully connected\n\n");
    else
        server_pid = 0;
    g_sigkey.key = sig_null;
    return server_pid;
}