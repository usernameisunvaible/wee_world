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