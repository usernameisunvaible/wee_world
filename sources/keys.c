#include "../includes/includes.h"


void main_keys(elements_t *elements, player_ *player)
{
    if (KEY_CODE == sfKeyZ) {
       player->pos_on_map.y -= 7;
       player->pos_on_map.x -= 7;
    }
    if (KEY_CODE == sfKeyS) {
       player->pos_on_map.y += 7;
       player->pos_on_map.x += 7;
    }
    if (KEY_CODE == sfKeyQ) {
       player->pos_on_map.y += 7;
       player->pos_on_map.x -= 7;
    }
    if (KEY_CODE == sfKeyD) {
       player->pos_on_map.y -= 7;
       player->pos_on_map.x += 7;
    }
    // (KEY_CODE == sfKeyS) ? (player->pos_on_map.y -= 5) : (0);

    // (KEY_CODE == sfKeyQ) ? (player->pos_on_map.x += 5) : (0);
    // (KEY_CODE == sfKeyD) ? (player->pos_on_map.x -= 5) : (0);


}

void key_events(elements_t *elements, player_ *player)
{
    while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
        if (elements->event.type == sfEvtClosed)
            sfRenderWindow_close(elements->window);
        if (elements->event.type == sfEvtKeyPressed) {
            main_keys(elements, player);
        }
    }

}