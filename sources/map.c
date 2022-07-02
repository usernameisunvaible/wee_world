#include "../includes/includes.h"

void refresh_map(elements_t *elements, map_ *map, texture_ **list)
{
    // printf("%d %d\n", map->size.x, map->size.y);
    
    // tmp->
    // temp->
    for (int i = 0; i < map->size.x  * map->size.y; ++i) {
        if (map->cube_map[i]->type == 1)
            sfRenderWindow_drawVertexArray(elements->window, map->cube_map[i]->top, list[0]->state);
            for (int j = 0; j < map->cube_map[i]->height; ++j) {
                sfRenderWindow_drawVertexArray(elements->window, map->cube_map[i]->south[j], list[0]->state);
                sfRenderWindow_drawVertexArray(elements->window, map->cube_map[i]->east[j], list[0]->state);
            }
    }
}

void generate_chunk_arrays(map_ *map, chunk_ *chunk, elements_t *elements)
{
    int x = 0;

    map->infos->offset.x += 1;
    for (unsigned int i = chunk->coords % NB_CHUNK_MAX; i < chunk->coords % NB_CHUNK_MAX + 32; ++i) {
        for (unsigned int j = chunk->coords / NB_CHUNK_MAX; j < chunk->coords / NB_CHUNK_MAX + 32; ++j) {
            chunk->cube_map[x] = load_cube(define_vectori(i, j), chunk->mapping, elements, 1, map->infos);
            ++x;
        }
    }

}

void refresh_chunk(sfVector2f player_pos, chunk_ *chunk, elements_t *elements, texture_ **list)
{
    for (int i = 0; i < 1024; ++i) {
        if (chunk->cube_map[i]->type == 1) {
            sfRenderWindow_drawVertexArray(elements->window, chunk->cube_map[i]->top, list[0]->state);
            for (int j = 0; j < chunk->cube_map[i]->height; ++j) {
                sfRenderWindow_drawVertexArray(elements->window, chunk->cube_map[i]->south[j], list[0]->state);
                sfRenderWindow_drawVertexArray(elements->window, chunk->cube_map[i]->east[j], list[0]->state);
            }
        }
        free_cube(chunk->cube_map[i]);

    }
}