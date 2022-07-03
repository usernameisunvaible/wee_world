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


chunk_ *wich_chunk(unsigned int player_chunk, map_ *map)
{
    int a = 0;

    for (int i = 0; i < 9; ++i) {
        a = 0;
        for (int j = 0; j < 9; ++j) {
            if (map->chunk_list[i]->coords == player_chunk - map->infos->arround_chunks[j])
                a = 1;
                
        }
        if (a == 0)
            break;
    }

    if (a == 0) {
        for (int i = 0; i < 9; ++i) {
            free_chunk(map->chunk_list[i]);
            map->chunk_list[i] = NULL;
        }
        load_near_chunks(player_chunk, map->chunk_list, map->infos->seed);
    } else {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 1024; ++j) {
                free_cube(map->chunk_list[i]->cube_map[j]);
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (map->chunk_list[i]->coords == player_chunk)
            return map->chunk_list[i];
    }
}

unsigned int player_chunk(player_ *player, map_ *s_map)
{
    return ((int)(get_pos_on_map(player, s_map).y / 32) * NB_CHUNK_MAX) + (int)(get_pos_on_map(player, s_map).x / 32);
}