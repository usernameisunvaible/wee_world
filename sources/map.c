#include "../includes/includes.h"

void refresh_map(elements_t *elements, map_ *map, sfRenderStates *tmp)
{
    // printf("%d %d\n", map->size.x, map->size.y);
    
    // tmp->
    // temp->
    for (int i = 0; i < map->size.x  * map->size.y; ++i) {
        sfRenderWindow_drawVertexArray(elements->window, map->cube_map[i]->top, tmp);
        
    }
}