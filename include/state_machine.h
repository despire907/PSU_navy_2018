/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MUL_MY_RUNNER_2018_STATE_MACHINE_H
#define MUL_MY_RUNNER_2018_STATE_MACHINE_H

#include <stdlib.h>
#include <stdio.h>

typedef enum e_state_machine{state_init, state_wait, state_play, state_destroy,
    state_error, state_end} t_state;

typedef enum e_state_event{event_startup, event_map_error, event_signal_error,
                           event_destroy_clear, event_connection_error} t_event;


typedef struct s_core{
    int ac;
    char **av;
    char **map;
    char **target_map;
} t_core;

typedef t_state (*state_handler)(t_state state, t_event *event, t_core *core);

t_state step_machine_create(t_state state, t_event *event, t_core *core);
t_state step_machine_wait(t_state state, t_event *event, t_core *core);
t_state step_machine_play(t_state state, t_event *event, t_core *core);
t_state step_machine_destroy(t_state state, t_event *event, t_core *core);
t_state step_mmachine_error(t_state state, t_event *event, t_core *core);

int state_machine(int ac, char **av);
#endif //MUL_MY_RUNNER_2018_STATE_MACHINE_H
