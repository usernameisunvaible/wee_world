#include "includes.h"

#ifndef CHUNK_H
    #define CHUNK_H

typedef struct {
    char *mapping;
    int coords;
    cube_ **cube_map;
}chunk_;

#endif //CHUNK_H