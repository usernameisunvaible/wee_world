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

void load_maths_infos(int  angle, elements_t *elements, sfVector2i size, math_inf_ *infos)
{
    infos->bloc_size = (elements->win_size.x/RECT_SIZE);
    infos->cos_angle = dcos(angle);
    infos->sin_angle = dsin(angle);
    infos->mid_x = elements->win_size.x/2;
    infos->mid_y = ((infos->sin_angle * (size.y / 2) + infos->sin_angle * (size.x / 2)) * (infos->bloc_size)) - (elements->win_size.y / 2);
    infos->offset = define_vectorf(15, 15);
}

cube_ *load_cube(sfVector2i id, char *str_map, elements_t *elements, int type, math_inf_ *infos, sfVector2i real_id)
{
    cube_ *cube = malloc(sizeof(cube_));
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
    cube->height = str_map[real_id.y * 32  + real_id.x];
    cube->south = malloc(sizeof(sfVertexArray *) * cube->height);
    cube->east = malloc(sizeof(sfVertexArray *) * cube->height);

    for (int i = 0; i < cube->height; ++i) {
        cube->south[i] = NULL;

        if (real_id.y < 31 && str_map[(real_id.y + 1) * 32  + real_id.x] < str_map[real_id.y * 32  + real_id.x]) {
            cube->south[i] = sfVertexArray_create();
            sfVertexArray_setPrimitiveType(cube->south[i], sfQuads);
            sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_EST + infos->bloc_size * i), color_south, define_vectorf(0, 0)));
            sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_OUEST + infos->bloc_size * i ), color_south,  define_vectorf(0, 512)));
            sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_OUEST  + infos->bloc_size * (i + 1)), color_south,  define_vectorf(512, 512)));
            sfVertexArray_append(cube->south[i], define_vertex(define_vectorf(SUD_EST + infos->bloc_size* (i + 1)), color_south, define_vectorf(512, 0)));
        }
        cube->east[i] = NULL;
        if (real_id.x < 31 && str_map[real_id.y * 32  + real_id.x + 1] < str_map[real_id.y * 32  + real_id.x]) {
            cube->east[i] = sfVertexArray_create();
            sfVertexArray_setPrimitiveType(cube->east[i], sfQuads);
            sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(SUD_EST + infos->bloc_size * i), color_east, define_vectorf(0, 0)));
            sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(NORD_EST + infos->bloc_size * i), color_east,  define_vectorf(0, 512)));
            sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(NORD_EST  + infos->bloc_size * (i + 1)), color_east,  define_vectorf(512, 512)));
            sfVertexArray_append(cube->east[i], define_vertex(define_vectorf(SUD_EST + infos->bloc_size * (i + 1)), color_east, define_vectorf(512, 0)));
        }
    }
    
    cube->type = type;
    return cube;
}

void free_cube(cube_ *cube)
{
    for (int i = 0; i < cube->height; ++i) {
        sfVertexArray_destroy(cube->south[i]);
        sfVertexArray_destroy(cube->east[i]);
    }
    free(cube->south);
    free(cube->east);
    sfVertexArray_destroy(cube->top);
    free(cube);
}

map_ *load_map(char *str_map, sfVector2i size, elements_t *elements)
{
    map_ *map = malloc(sizeof(map_));
    map->infos = malloc(sizeof(math_inf_));
    load_maths_infos(25, elements, size, map->infos);
    return map;
}
