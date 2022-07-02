#include "../includes/includes.h"

sfVector2f get_pos_on_map(player_ *player, map_ *s_map)
{
    return define_vectorf(player->pos_on_map.x / s_map->infos->bloc_size, player->pos_on_map.y / s_map->infos->bloc_size);
}

void move_player(player_ *player, chunk_ *chunk, map_ *s_map)
{
    // sfVector2i pos_on_chunk = get_pos_on_map(player, s_map);

    // printf("%d %d\n", pos_on_chunk.x, pos_on_chunk.y);
}