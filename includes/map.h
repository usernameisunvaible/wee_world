#include "includes.h"


#ifndef MAP_H
    #define MAP_H
    
typedef struct {
    sfVector2f pos_on_screen;
    sfVector2i pos_on_tab;
    sfVertexArray *top;
    sfVertexArray **south;
    sfVertexArray **east;
    int height;
    int type;
}cube_;

typedef struct {
    float cos_angle;
    float sin_angle;
    float mid_x;
    float bloc_size;
    sfVector2f offset;

}math_inf_;

typedef struct {
    cube_ **cube_map;
    int angle;
    sfVector2i size;
    math_inf_ *infos;
}map_;

typedef struct {
    sfRenderStates *state;
    int type;
    sfColor bgcolor;
}texture_;



#endif //MAP_H
