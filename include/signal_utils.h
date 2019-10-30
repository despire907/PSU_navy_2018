/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#ifndef PSU_NAVY_2018_SIGNAL_H
#define PSU_NAVY_2018_SIGNAL_H


#include <stdlib.h>

typedef enum e_sigkeys{sig_null, sig_first_case = 1, sig_last_case = 64,
                       sig_is_server = 70, sig_i_am_server,
                       sig_received, sig_shot, sig_miss}t_sigkey_value;

int set_signal_listener(void);
int send_signal(char key, int target);
typedef struct s_sigkey{
    char key;
    int emitter;
} t_sigkey;

extern t_sigkey g_sigkey;
#endif //PSU_NAVY_2018_SIGNAL_H
