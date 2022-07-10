#include "../../../includes/includes.h"

void refresh_right_leg(brick_ *right_leg, map_ *map, character_ *character, elements_t *elements)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lft = iso(define_vectortf(0, character->annim_r_leg->p1.x , character->annim_r_leg->p1.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_lfb = iso(define_vectortf(0, character->annim_r_leg->p2.x , character->annim_r_leg->p2.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_lbb = iso(define_vectortf(0, character->annim_r_leg->p3.x , character->annim_r_leg->p3.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_lbt = iso(define_vectortf(0, character->annim_r_leg->p4.x , character->annim_r_leg->p4.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_rft = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p1.x + character->size.y / 4, character->annim_r_leg->p1.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_rfb = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p2.x + character->size.y / 4, character->annim_r_leg->p2.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_rbb = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p3.x + character->size.y / 4, character->annim_r_leg->p3.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));
    sfVector2f v_rbt = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p4.x + character->size.y / 4, character->annim_r_leg->p4.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2));

    sfVertexArray_destroy(right_leg->left);
    sfVertexArray_destroy(right_leg->right);
    sfVertexArray_destroy(right_leg->top);
    sfVertexArray_destroy(right_leg->back);
    sfVertexArray_destroy(right_leg->bottom);
    sfVertexArray_destroy(right_leg->front);

    right_leg->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->left, sfQuads);
    sfVertexArray_append(right_leg->left, define_vertex(v_lft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->left, define_vertex(v_lfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->left, define_vertex(v_lbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->left, define_vertex(v_lbt, sfBlue, define_vectorf(0, 0)));

    right_leg->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->right, sfQuads);
    sfVertexArray_append(right_leg->right, define_vertex(v_rft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->right, define_vertex(v_rfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->right, define_vertex(v_rbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->right, define_vertex(v_rbt, sfBlue, define_vectorf(0, 0)));

    right_leg->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->top, sfQuads);
    sfVertexArray_append(right_leg->top, define_vertex(v_lft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->top, define_vertex(v_lbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->top, define_vertex(v_rbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->top, define_vertex(v_rft, sfBlue, define_vectorf(0, 0)));

    right_leg->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->back, sfQuads);
    sfVertexArray_append(right_leg->back, define_vertex(v_lbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->back, define_vertex(v_rbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->back, define_vertex(v_rbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->back, define_vertex(v_lbb, sfBlue, define_vectorf(0, 0)));

    right_leg->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->bottom, sfQuads);
    sfVertexArray_append(right_leg->bottom, define_vertex(v_lfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->bottom, define_vertex(v_lbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->bottom, define_vertex(v_rbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->bottom, define_vertex(v_rfb, sfBlue, define_vectorf(0, 0)));

    right_leg->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->front, sfQuads);
    sfVertexArray_append(right_leg->front, define_vertex(v_lft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->front, define_vertex(v_rft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->front, define_vertex(v_rfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(right_leg->front, define_vertex(v_lfb, sfBlue, define_vectorf(0, 0)));
}

