/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "includes/include_engine.h"

chrono_t *init_chrono(void)
{
    chrono_t *chrono = malloc(sizeof(chrono_t));

    if (chrono == NULL) {return NULL;}
    chrono->ms = 0;
    chrono->s = 0;
    chrono->clock = sfClock_create();
    if (chrono->clock == NULL) {free(chrono); return NULL;}
    return chrono;
}

void refresh_chrono(chrono_t *chrono)
{
    chrono->ms = (sfClock_getElapsedTime(chrono->clock).microseconds) / 1000;
    if (chrono->ms > 1000)
        ++chrono->s;
}

void free_chrono(chrono_t *chrono)
{
    sfClock_destroy(chrono->clock);
    free(chrono);
}
