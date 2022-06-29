#include "../includes/includes.h"

void refresh_map(elements_t *elements, map_ *map)
{
    // printf("%d %d\n", map->size.x, map->size.y);
    sfRenderStates *temp = malloc(sizeof(sfRenderStates));
    temp->texture = sfTexture_createFromFile("assets/grass.png", NULL);
    temp->blendMode = sfBlendNone;
    // temp->
    for (int i = 0; i < map->size.x  * map->size.y; ++i) {
        sfRenderWindow_drawVertexArray(elements->window, map->cube_map[i]->top, NULL);
        
    }
    free(temp);
}