#include "../../includes/includes.h"


void generate_chunk_arrays(sfVector3f player_pos, map_ *map, chunk_ *chunk, elements_t *elements)
{
    int x = 0;
    int y = 0;

    for (unsigned int i = (chunk->coords % NB_CHUNK_MAX) * 32; i < (chunk->coords % NB_CHUNK_MAX) * 32 + 32; ++i) {
        for (unsigned int j = (chunk->coords / NB_CHUNK_MAX) * 32; j < (chunk->coords / NB_CHUNK_MAX) * 32 + 32; ++j) {
            chunk->cube_map[y * 32 + x] = load_cube(define_vectori(i, j), chunk->mapping, elements, 1, map->infos, define_vectori(x, y), ((int)(player_pos.x / map->infos->bloc_size) == i && (int)(player_pos.y / map->infos->bloc_size) == j) ? (sfTrue) : (sfFalse));
            ++y;
        }
        ++x;
        y = 0;
    }
}

void refresh_chunk(chunk_ *chunk, elements_t *elements, texture_ **list, map_ *map)
{
    sfVector2f temp;
    for (int i = 0; i < 1024; ++i) {
        if (chunk->cube_map[i]->type == 1) {
            temp = sfVertexArray_getVertex(chunk->cube_map[i]->top, 0)->position;
            if (temp.x > - map->infos->bloc_size && temp.x < elements->win_size.x +  map->infos->bloc_size && temp.y > - map->infos->bloc_size && temp.y < elements->win_size.y +  map->infos->bloc_size)
                sfRenderWindow_drawVertexArray(elements->window, chunk->cube_map[i]->top, list[0]->state);
            for (int j = 0; j < chunk->cube_map[i]->height; ++j) {
                if (chunk->cube_map[i]->south[j] != NULL) {
                    temp = sfVertexArray_getVertex(chunk->cube_map[i]->south[j], 0)->position;
                    if (temp.x > - map->infos->bloc_size && temp.x < elements->win_size.x +  map->infos->bloc_size && temp.y > - map->infos->bloc_size && temp.y < elements->win_size.y +  map->infos->bloc_size)
                        sfRenderWindow_drawVertexArray(elements->window, chunk->cube_map[i]->south[j], list[0]->state);
                }
                if (chunk->cube_map[i]->east[j] != NULL) {
                    temp = sfVertexArray_getVertex(chunk->cube_map[i]->east[j], 0)->position;
                        if (temp.x > - map->infos->bloc_size && temp.x < elements->win_size.x +  map->infos->bloc_size && temp.y > - map->infos->bloc_size && temp.y < elements->win_size.y +  map->infos->bloc_size)
                            sfRenderWindow_drawVertexArray(elements->window, chunk->cube_map[i]->east[j], list[0]->state);
                }
            }
        }
    }
    
}