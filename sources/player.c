#include "../includes/includes.h"

sfVector2f get_pos_on_map(player_ *player, map_ *s_map)
{
    return define_vectorf(player->pos_on_map.x / s_map->infos->bloc_size, player->pos_on_map.y / s_map->infos->bloc_size);
}


void appli_move(player_ *player, map_ *s_map, elements_t *elements, chunk_ *chunk)
{
    player->pos_on_screen = define_vectorf(((s_map->infos->cos_angle * get_pos_on_map(player, s_map).x - s_map->infos->cos_angle * get_pos_on_map(player, s_map).y ) * s_map->infos->bloc_size + s_map->infos->offset.x), ((s_map->infos->sin_angle * player->pos_on_map.y + s_map->infos->sin_angle * player->pos_on_map.x - (chunk->mapping[(int)(get_pos_on_map(player, s_map).y) % 32 * 32 + (int)(get_pos_on_map(player, s_map).x) % 32]) * s_map->infos->bloc_size + s_map->infos->offset.y)));
    s_map->infos->offset.x -= player->pos_on_screen.x - elements->win_size.x / 2;
    s_map->infos->offset.y -= player->pos_on_screen.y - elements->win_size.y / 2;

}


void move_player(player_ *player, elements_t *elements)
{
    int time;
    player->timer.x += elements->chrono->ms - player->timer.y;
    player->diag = sfFalse;
    if (PL TOP && PL LEFT)
        player->diag = sfTrue;
    if (PL TOP && PL RIGHT)
        player->diag = sfTrue;
    if (PL BOTTOM && PL RIGHT)
        player->diag = sfTrue;
    if (PL BOTTOM && PL LEFT)
        player->diag = sfTrue;

    time = (player->diag) ? (6) : (4);
    while (player->timer.x >= time) {
        if (player->move & TOP) {
            player->pos_on_map.y -= elements->win_size.x / 1920;
            player->pos_on_map.x -= elements->win_size.x / 1920;
        }
        if (player->move & BOTTOM) {
            player->pos_on_map.y += elements->win_size.x / 1920;
            player->pos_on_map.x += elements->win_size.x / 1920;
        }
        if (player->move & LEFT) {
            player->pos_on_map.y += elements->win_size.x / 1920;
            player->pos_on_map.x -= elements->win_size.x / 1920;
        }
        if (player->move & RIGHT) {
            player->pos_on_map.y -= elements->win_size.x / 1920;
            player->pos_on_map.x += elements->win_size.x / 1920;
        }
        player->timer.x -= time;
    }
    player->timer.y = elements->chrono->ms;
}

unsigned int player_chunk(player_ *player, map_ *s_map)
{
    // printf("%f %f\n", get_pos_on_map(player, s_map).x, get_pos_on_map(player, s_map).y);

    return ((int)(get_pos_on_map(player, s_map).y / 32) * NB_CHUNK_MAX) + (int)(get_pos_on_map(player, s_map).x / 32);
}