#include "../includes/includes.h"

player_ *init_player(void)
{
    player_ *player = malloc(sizeof(player_));
    player->pos_on_map = define_vectortf(5, 36, 0);
    player->pos_on_screen = define_vectorf(0, 0);
    player->move = 0;
    player->timer = (sfVector2u) {0, 0};
    player->diag = sfFalse;
    return player;
}