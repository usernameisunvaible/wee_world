#include "../includes/includes.h"

static sfColor select_colortop(int type)
{
    if (type == 1) { return sfGreen;}
}

static sfColor select_colorsouth(int type)
{
    if (type == 1) { return sfColor_fromRGB(79, 38, 9);}
}

static sfColor select_coloreast(int type)
{
    if (type == 1) { return sfColor_fromRGB(139, 69, 19);}
}

static cube_ *load_cube(sfVector2i id, char *str_map, sfVector2i size, elements_t *elements, int type)
{
    cube_ *cube = malloc(sizeof(cube_));
    float mid =   ((dsin(25) * (size.y / 2) + dsin(25) * (size.x / 2)) * (elements->win_size.x/RECT_SIZE)) - (elements->win_size.y / 2)  ;
    sfColor color_top = select_colortop(type);
    sfColor color_south = select_colorsouth(type);
    sfColor color_east = select_coloreast(type);

    cube->pos_on_tab = id;
    cube->pos_on_screen = define_vectorf(NORD_OUEST);
    cube->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(cube->top, sfQuads);
    sfVertexArray_append(cube->top, define_vertex(cube->pos_on_screen, color_top , define_vectorf(0, 0)));
    sfVertexArray_append(cube->top, define_vertex(define_vectorf(NORD_EST), color_top, define_vectorf(512, 0)));
    sfVertexArray_append(cube->top, define_vertex(define_vectorf(SUD_EST), color_top, define_vectorf(512, 512)));
    sfVertexArray_append(cube->top, define_vertex(define_vectorf(SUD_OUEST), color_top,  define_vectorf(0, 512)));
    cube->height = str_map[id.y * size.x + id.x];
    cube->south = malloc(sizeof(sfVertexArray *) * cube->height);
    cube->east = malloc(sizeof(sfVertexArray *) * cube->height);
    for (int i = 0; i < cube->height; ++i) {
        cube->south[i] = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(cube->south[i], sfQuads);
        sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_EST + (elements->win_size.x/RECT_SIZE) * i), color_south, define_vectorf(0, 0)));
        sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_OUEST + (elements->win_size.x/RECT_SIZE) * i ), color_south,  define_vectorf(0, 512)));
        sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_OUEST  + (elements->win_size.x/RECT_SIZE) * (i + 1)), color_south,  define_vectorf(512, 512)));
        sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_EST + (elements->win_size.x/RECT_SIZE)* (i + 1)), color_south, define_vectorf(512, 0)));

        cube->east[i] = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(cube->east[i], sfQuads);
        sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(SUD_EST + (elements->win_size.x/RECT_SIZE) * i), color_east, define_vectorf(0, 0)));
        sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(NORD_EST + (elements->win_size.x/RECT_SIZE) * i), color_east,  define_vectorf(0, 512)));
        sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(NORD_EST  + (elements->win_size.x/RECT_SIZE) * (i + 1)), color_east,  define_vectorf(512, 512)));
        sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(SUD_EST + (elements->win_size.x/RECT_SIZE) * (i + 1)), color_east, define_vectorf(512, 0)));
    }
    
    cube->type = type;
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
            map->cube_map[j * size.x + i] = load_cube(define_vectori(i, j), str_map, size, elements, 1);
        }
    }
    return map;
}
