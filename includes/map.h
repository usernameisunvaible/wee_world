#include "includes.h"


#ifndef MAP_H
    #define MAP_H
    


typedef struct {
    float cos_angle;
    float sin_angle;
    float mid_x;
    float bloc_size;
    sfVector2f offset;

}math_inf_;

typedef struct {
    math_inf_ *infos;
    chunk_ **chunk_list;
}map_;

typedef struct {
    sfRenderStates *state;
    int type;
    sfColor bgcolor;
}texture_;



#endif //MAP_H
