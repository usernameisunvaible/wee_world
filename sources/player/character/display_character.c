#include "../../../includes/includes.h"


//     display_brick(elements, character->r_arm, character);
//     display_brick(elements, character->r_leg, character);
//     display_brick(elements, character->l_leg, character);
//     display_brick(elements, character->body, character);
//     display_brick(elements, character->l_arm, character);
//     display_brick(elements, character->head, character);
// }

// void display_brick(elements_t *elements, brick_ *brick, character_ *character)
// {
//     sfRenderWindow_drawVertexArray(elements->window, brick->right, character->skin);
//     sfRenderWindow_drawVertexArray(elements->window, brick->bottom, character->skin);
//     sfRenderWindow_drawVertexArray(elements->window, brick->back, character->skin);
//     sfRenderWindow_drawVertexArray(elements->window, brick->front, character->skin);
//     sfRenderWindow_drawVertexArray(elements->window, brick->left, character->skin);
//     sfRenderWindow_drawVertexArray(elements->window, brick->top, character->skin);
// }

static void display_lb(elements_t *elements, character_ *character)
{
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->top, character->skin);
}


static void display_lt(elements_t *elements, character_ *character)
{
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->top, character->skin);
}

static void display_rt(elements_t *elements, character_ *character)
{
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->top, character->skin);
}

static void display_rb(elements_t *elements, character_ *character)
{
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_LEG->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, L_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, BODY->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, R_ARM->top, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, HEAD->top, character->skin);
}

void display_character(elements_t *elements, character_ *character)
{
    if(character->angle == 0) {
        display_lb(elements, character);
    }

    if(character->angle == 90) {
        display_lt(elements, character);
    }
    if(character->angle == 180) {
        display_rt(elements, character);
    }
    if(character->angle == 270) {
        display_rb(elements, character);
    }
}