#include "../includes/includes.h"


void main_keys(elements_t *elements)
{

}

void key_events(elements_t *elements)
{
    while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
        if (elements->event.type == sfEvtClosed)
            sfRenderWindow_close(elements->window);
        if (elements->event.type == sfEvtKeyPressed) {
            main_keys(elements);
        }
    }

}