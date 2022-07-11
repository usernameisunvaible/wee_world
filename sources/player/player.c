#include "../../includes/includes.h"

sfVector2f get_pos_on_map(sfVector3f pos_on_map, map_ *s_map)
{
    return define_vectorf(pos_on_map.x / s_map->infos->bloc_size, pos_on_map.y / s_map->infos->bloc_size);
}


void appli_move(player_ *player, map_ *s_map, elements_t *elements)
{
    player->pos_on_screen = define_vectorf(((s_map->infos->cos_angle * get_pos_on_map(player->pos_on_map, s_map).x - s_map->infos->cos_angle * get_pos_on_map(player->pos_on_map, s_map).y ) * s_map->infos->bloc_size + s_map->infos->offset.x), ((s_map->infos->sin_angle * player->pos_on_map.y + s_map->infos->sin_angle * player->pos_on_map.x - (player->pos_on_map.z) * s_map->infos->bloc_size + s_map->infos->offset.y)));
    s_map->infos->offset.x -= player->pos_on_screen.x - elements->win_size.x / 2;
    s_map->infos->offset.y -= player->pos_on_screen.y - elements->win_size.y / 2;
}


void move_player(player_ *player, elements_t *elements, map_ *s_map)
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
        player_collisions(player, elements, s_map);
        if (player->apply_move & TOP) {
            player->pos_on_map.y -= s_map->infos->bloc_size / 45;
            player->pos_on_map.x -= s_map->infos->bloc_size / 45;
        }
        if (player->apply_move & BOTTOM) {
            player->pos_on_map.y += s_map->infos->bloc_size / 45;
            player->pos_on_map.x += s_map->infos->bloc_size / 45;
        }
        if (player->apply_move & LEFT) {
            player->pos_on_map.y += s_map->infos->bloc_size / 45;
            player->pos_on_map.x -= s_map->infos->bloc_size / 45;
        }
        if (player->apply_move & RIGHT) {
            player->pos_on_map.y -= s_map->infos->bloc_size / 45;
            player->pos_on_map.x += s_map->infos->bloc_size / 45;
        }
        if (player->apply_move & TOP && player->apply_move & LEFT) {
            player->character->angle = 90;
            player->character->do_annim = sfTrue;
        }
        if (player->apply_move & TOP && player->apply_move & RIGHT) {
            player->character->angle = 180;
            player->character->do_annim = sfTrue;
        }
        if (player->apply_move & BOTTOM && player->apply_move & LEFT) {
            player->character->angle = 0;
            player->character->do_annim = sfTrue;
        }
        if (player->apply_move & BOTTOM && player->apply_move & RIGHT) {
            player->character->angle = 270;
            player->character->do_annim = sfTrue;
        }
        if (!player->apply_move | 0) {
            player->character->do_annim = sfFalse;
            player->character->annim_l_arm->angle = 180;
            player->character->annim_r_arm->angle = 180;
            player->character->annim_l_leg->angle = 180;
            player->character->annim_r_leg->angle = 180;
            player->character->annim_l_arm->dir = 0;
            player->character->annim_r_leg->dir = 0;
            player->character->annim_r_arm->dir = 1;
            player->character->annim_l_leg->dir = 1;
        }
        player->timer.x -= time;
    }
    player->timer.y = elements->chrono->ms;
}

void gravity(player_ *player, elements_t *elements, map_ *s_map, chunk_ *chunk)
{
    int ground = chunk->mapping[(int)(get_pos_on_map(player->pos_on_map, s_map).y) % 32 * 32 + (int)(get_pos_on_map(player->pos_on_map, s_map).x) % 32];
    if (player->jump->active == sfFalse && player->pos_on_map.z > ground){
        player->pos_on_map.z -= 0.25;
    }
    if (player->jump->active == sfFalse && player->pos_on_map.z < ground && player->pos_on_map.z > ground - 0.2){
        player->pos_on_map.z = ground;
    }
    if (player->pos_on_map.z == ground)
        player->on_the_ground = sfTrue;
    else
        player->on_the_ground = sfFalse;
}

void jump(player_ *player, elements_t *elements, map_ *s_map, chunk_ *chunk)
{

    player->jump->timer.x += elements->chrono->ms - player->jump->timer.y;
    while (player->jump->timer.x >= 25)
    {
        if (player->jump->active && player->jump->counter < 0) {
            player->pos_on_map.z -= (float) player->jump->counter / 10.0;
            player->jump->counter += 1;
        } else if (player->jump->counter >= 0){
            player->jump->active = sfFalse;
            player->jump->counter = -5;
        }
        gravity(player, elements, s_map, chunk);
        player->jump->timer.x -= 25;
    }
    player->jump->timer.y = elements->chrono->ms;
}



unsigned int player_chunk(sfVector3f pos_on_map, map_ *s_map)
{
    return ((int)(get_pos_on_map(pos_on_map, s_map).y / 32) * NB_CHUNK_MAX) + (int)(get_pos_on_map(pos_on_map, s_map).x / 32);
}