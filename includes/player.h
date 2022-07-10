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
    sfVertexArray *top;
    sfVertexArray *bottom;
    sfVertexArray *front;
    sfVertexArray *left;
    sfVertexArray *right;
    sfVertexArray *back;
}brick_;

typedef struct {
    sfVector2f p1;
    sfVector2f p2;
    sfVector2f p3;
    sfVector2f p4;
    int angle;
    int dir;
    int timer;
    int timer_tot;
}annim_;

typedef struct {
    brick_ *head;
    brick_ *body;
    brick_ *l_arm;
    brick_ *r_arm;
    brick_ *l_leg;
    brick_ *r_leg;
    sfVector3f size;
    annim_ *annim_l_leg;
    annim_ *annim_r_leg;
    annim_ *annim_l_arm;
    annim_ *annim_r_arm;
}character_;

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
    character_ *charactere;
}player_;

#endif //PLAYER_H