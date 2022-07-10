#include "../../includes/includes.h"

chunk_ *select_chunk(sfVector3f next, map_ *s_map)
{
    unsigned int chunk = player_chunk(next, s_map);

    for (int i = 0; i < 9; ++i) {
        if (chunk == s_map->chunk_list[i]->coords)
            return s_map->chunk_list[i];
    }
    return s_map->chunk_list[4];
}

void player_collisions(player_ *player, elements_t *elements, map_ *s_map)
{
    sfVector3f next = player->pos_on_map;
    int ground = s_map->chunk_list[4]->mapping[(int)(get_pos_on_map(player->pos_on_map, s_map).y) % 32 * 32 + (int)(get_pos_on_map(player->pos_on_map, s_map).x) % 32];
    chunk_ *chunk;

    player->apply_move = player->move;
    if (player->move & TOP) {
        next.y -= elements->win_size.x / 1920;
        next.x -= elements->win_size.x / 1920;
    }
    if (player->move & BOTTOM) {
        next.y += elements->win_size.x / 1920;
        next.x += elements->win_size.x / 1920;
    }
    if (player->move & LEFT) {
        next.y += elements->win_size.x / 1920;
        next.x -= elements->win_size.x / 1920;
    }
    if (player->move & RIGHT) {
        next.y -= elements->win_size.x / 1920;
        next.x += elements->win_size.x / 1920;
    }
    chunk = select_chunk(next, s_map);
    if (chunk->mapping[(int)(get_pos_on_map(next, s_map).y) % 32 * 32 + (int)(get_pos_on_map(next, s_map).x) % 32] > player->pos_on_map.z) {
        player->apply_move = 0;
    }
}