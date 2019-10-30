/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include <unistd.h>
#include "signal_utils.h"
#include "my.h"

int wait_for_client(void)
{
    my_putstr("waiting for enemy connection...\n\n");
    while(g_sigkey.key == sig_null) {
        usleep(10000);
    }
    if (g_sigkey.key == sig_is_server) {
        send_signal(sig_i_am_server, g_sigkey.emitter);
        my_putstr("enemy connected...\n\n");
        return g_sigkey.emitter;
    }
    return 0;
}

int state_machine(int ac, char **av)
{
    t_state state = state_init;
    t_event event = event_startup;
    state_handler handler = machine_steps[state];
    t_core core = {ac, av};

    while (state != state_end) {
        state = handler(state, &event, &core);
        handler = machine_steps[state];
    }
    if (event == event_destroy_clear)
        return 0;
    return 84;
}