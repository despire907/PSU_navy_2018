/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/
#include "state_machine.h"
#include "my.h"
#include "client.h"
#include "server.h"
#include "signal_utils.h"
#include "map.h"

#include <unistd.h>
#include <signal_utils.h>
#include "navy.h"

int wait_for_signal(void);
void process_info(void);
int set_and_get_pid(int pid);

t_sigkey g_sigkey = {sig_null, 0};

static state_handler machine_steps[] = {&step_machine_create,
                                        &step_machine_wait,
                                        &step_machine_play,
                                        &step_machine_destroy,
                                        &step_mmachine_error,
                                        NULL};

t_state step_machine_create(t_state state, t_event *event, t_core *core)
{
    int ship_path = 1;

    process_info();
    set_signal_listener();
    core->target_map = load_my_map();
    if (core->ac == 3) {
        ship_path = 2;
        g_sigkey.emitter = my_getnbr(core->av[1]);
        state = state_wait;
    } else
        state = state_play;
    if(!(core->map = load_map_from_file(core->av[ship_path]))) {
        *event = event_map_error;
        return state_error;
    }
    g_sigkey.emitter = (core->ac == 3) ? connect_to_server(g_sigkey.emitter) :
                        wait_for_client();
    if (!g_sigkey.emitter && (*event = event_connection_error))
        return state_error;
    init_target_map((core->target_map));
    return state;
}

t_state step_machine_wait(t_state state, t_event *event, t_core *core)
{
    g_sigkey.key = sig_null;
    my_putstr("waiting for enemy's attack...\n");
    while(g_sigkey.key == sig_null)
        usleep(10000);
    if (g_sigkey.key < sig_first_case || g_sigkey.key > sig_last_case) {
        *event = event_signal_error;
        return state_error;
    }
    if (shot_is_landed(g_sigkey.key - 1, core->map))
        send_signal(sig_shot, g_sigkey.emitter);
    else
        send_signal(sig_miss, g_sigkey.emitter);
    return state_play;
}

t_state step_machine_play(t_state state, t_event *event, t_core *core) {
    int target;

    display_map(core->map, core->target_map);
    target = get_next_shot(core->target_map);
    if (!navy_shot(target, core->target_map)) {
        *event = event_signal_error;
        return state_error;
}
    return state_wait;
}

t_state step_machine_destroy(t_state state, t_event *event, t_core *core)
{
    *event = event_destroy_clear;
    return state_end;
}

t_state step_mmachine_error(t_state state, t_event *event, t_core *core)
{
    my_putstr("error\n");
    return state_end;
}