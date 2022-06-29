#include "includes.h"


#ifndef MAP_H
    #define MAP_H
    
typedef struct {
    sfVector2f pos_on_screen;
    sfVector2i pos_on_tab;
    sfVertexArray *top;
    sfVertexArray *north;
    sfVertexArray *south;
    sfVertexArray *east;
    sfVertexArray *west;
}cube_;

typedef struct {
    cube_ **cube_map;
    int angle;
    sfVector2i size;
}map_;

#endif //MAP_H
