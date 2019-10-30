/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Created by Croquette,
*/

#include "my.h"

void my_put_nbr(int nb)
{
    if (nb <= 9)
        my_putchar(nb + 48);
    else{
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}