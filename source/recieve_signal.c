/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include "signal_utils.h"

int signal_receiver(int signal, pid_t pid)
{
    static char flag = 0;
    static char mask = 1;
    static int stack = 1;

    flag = ((signal == SIGUSR1) ? flag : (flag | mask));
    ++stack;
    mask *= 2;
    if (stack == 9) {
        g_sigkey.key = flag;
        if (flag == sig_is_server)
            g_sigkey.emitter = pid;
        mask = 1;
        flag = 0;
        stack = 1;
    }
    return 1;
}

void signal_usr_handler(int signal, siginfo_t *info, void *data)
{
    if (!g_sigkey.emitter || info->si_pid == g_sigkey.emitter)
        signal_receiver(signal, info->si_pid);
}

int set_signal_listener(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_usr_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    return 1;
}