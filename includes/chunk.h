#include "includes.h"

#ifndef CHUNK_H
    #define CHUNK_H

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
    char *mapping;
    int coords;
    cube_ **cube_map;
}chunk_;

#endif //CHUNK_H