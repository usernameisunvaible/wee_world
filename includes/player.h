#include "includes.h"

#ifndef PLAYER_H
    #define PLAYER_H

#define TOP             1 << 0
#define TOP_LEFT        1 << 1
#define LEFT            1 << 2
#define BOTTOM_LEFT     1 << 3
#define BOTTOM          1 << 4
#define BOTTOM_RIGHT    1 << 5
#define RIGHT           1 << 6
#define TOP_RIGHT       1 << 7

#define PL player->move &

typedef struct {
    sfVector2i timer;
    float offset;
    int counter;
    sfBool active;
}jump_;

typedef struct {
    sfVector3f pos_on_map;
    sfVector2f pos_on_screen;
    unsigned char move;
    unsigned char apply_move;
    sfVector2u timer;
    sfBool diag;
    jump_ *jump;
    sfBool on_the_ground;
}player_;

#endif //PLAYER_H