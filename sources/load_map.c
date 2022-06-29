#include "../includes/includes.h"



static cube_ *load_cube(sfVector2i id, char *str_map, sfVector2i size, elements_t *elements)
{
    cube_ *cube = malloc(sizeof(cube_));
    float mid =   ((dsin(25) * (size.y / 2) + dsin(25) * (size.x / 2)) * (elements->win_size.x/RECT_SIZE)) - (elements->win_size.y / 2)  ;
    cube->pos_on_tab = id;
    cube->pos_on_screen = define_vectorf( (dcos(25) * id.x - dcos(25) * id.y) * (elements->win_size.x/RECT_SIZE) + elements->win_size.x/2, (dsin(25) * id.y + dsin(25) * id.x - str_map[id.y * size.x + id.x]) * (elements->win_size.x/RECT_SIZE) - mid );
    cube->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(cube->top, sfQuads);
    sfVertexArray_append(cube->top, define_vertex(cube->pos_on_screen, sfGreen));
    sfVertexArray_append(cube->top, define_vertex(define_vectorf((dcos(25) * id.x - dcos(25) * (id.y + 1)) * (elements->win_size.x/RECT_SIZE) + elements->win_size.x/2, (dsin(25) * (id.y + 1) + dsin(25) * id.x - str_map[id.y * size.x + id.x]) * (elements->win_size.x/RECT_SIZE) - mid ), sfGreen));
    sfVertexArray_append(cube->top, define_vertex(define_vectorf((dcos(25) * (id.x + 1) - dcos(25) * (id.y + 1)) * (elements->win_size.x/RECT_SIZE)+ elements->win_size.x/2, (dsin(25) * (id.y + 1) + dsin(25) * (id.x + 1) - str_map[id.y * size.x + id.x])  * (elements->win_size.x/RECT_SIZE) - mid ), sfGreen));
    sfVertexArray_append(cube->top, define_vertex(define_vectorf((dcos(25) * (id.x + 1) - dcos(25) * id.y ) * (elements->win_size.x/RECT_SIZE) + elements->win_size.x/2, (dsin(25) * id.y  + dsin(25) * (id.x + 1) - str_map[id.y * size.x + id.x]) * (elements->win_size.x/RECT_SIZE) - mid  ), sfGreen));

    return cube;
}

map_ *load_map(char *str_map, sfVector2i size, elements_t *elements)
{

    map_ *map = malloc(sizeof(map_));
    map->angle = 0;
    map->size = size;
    map->cube_map = malloc(sizeof(cube_ *) * size.x * size.y);
    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            map->cube_map[j * size.x + i] = load_cube(define_vectori(i, j), str_map, size, elements);
        }
    }
    return map;
}
