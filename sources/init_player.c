#include "../includes/includes.h"

static jump_ *init_jump(void)
{
    jump_ *jump = malloc(sizeof(jump_));
    jump->counter = -5;
    jump->offset = 0;
    jump->timer = define_vectori(0, 0);
    jump->active = sfFalse;
    return jump;
}

player_ *init_player(map_ *s_map, sfVector2i player_spawn, elements_t *elements )
{
    player_ *player = malloc(sizeof(player_));
    player->pos_on_map = define_vectortf(player_spawn.x * s_map->infos->bloc_size,  player_spawn.y * s_map->infos->bloc_size, 0);
    player->pos_on_screen = define_vectorf(0, 0);
    player->move = 0;
    player->timer = (sfVector2u) {0, 0};
    player->diag = sfFalse;
    load_near_chunks(player_chunk(player, s_map), s_map->chunk_list, s_map->infos->seed);
    for (int i = 0; i < 9; ++i) {
        generate_chunk_arrays(player->pos_on_map, s_map, s_map->chunk_list[i], elements);
    }
    player->jump = init_jump();
    return player;
}