#include "../includes/includes.h"


void main_keys(elements_t *elements, player_ *player)
{
    if (KEY_CODE == sfKeyZ) {player->move = player->move | TOP;}
    if (KEY_CODE == sfKeyS) {player->move = player->move | BOTTOM;}
    if (KEY_CODE == sfKeyQ) {player->move = player->move | LEFT;}
    if (KEY_CODE == sfKeyD) {player->move = player->move | RIGHT;}
    if (KEY_CODE == sfKeySpace) {player->jump->active = sfTrue;}
}

void main_released(elements_t *elements, player_ *player)
{
    if (KEY_CODE == sfKeyZ) {player->move = (255 ^ TOP) & player->move;}
    if (KEY_CODE == sfKeyS) {player->move = (255 ^ BOTTOM) & player->move;}
    if (KEY_CODE == sfKeyQ) {player->move = (255 ^ LEFT) & player->move;}
    if (KEY_CODE == sfKeyD) {player->move = (255 ^ RIGHT) & player->move;}
}

void key_events(elements_t *elements, player_ *player)
{
    while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
        if (elements->event.type == sfEvtClosed)
            sfRenderWindow_close(elements->window);
        if (elements->event.type == sfEvtKeyPressed) {
            main_keys(elements, player);
        }
        if (elements->event.type == sfEvtKeyReleased) {
            main_released(elements, player);
        }
    }

}