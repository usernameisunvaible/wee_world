#include "../../../includes/includes.h"

void refresh_right_leg(brick_ *right_leg, map_ *map, character_ *character, elements_t *elements,int angle)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lft = iso(define_vectortf(0, character->annim_r_leg->p1.x , character->annim_r_leg->p1.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_lfb = iso(define_vectortf(0, character->annim_r_leg->p2.x , character->annim_r_leg->p2.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_lbb = iso(define_vectortf(0, character->annim_r_leg->p3.x , character->annim_r_leg->p3.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_lbt = iso(define_vectortf(0, character->annim_r_leg->p4.x , character->annim_r_leg->p4.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rft = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p1.x, character->annim_r_leg->p1.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rfb = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p2.x, character->annim_r_leg->p2.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rbb = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p3.x, character->annim_r_leg->p3.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rbt = iso(define_vectortf(-character->size.x / 2, character->annim_r_leg->p4.x, character->annim_r_leg->p4.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);

    sfVertexArray_destroy(right_leg->left);
    sfVertexArray_destroy(right_leg->right);
    sfVertexArray_destroy(right_leg->top);
    sfVertexArray_destroy(right_leg->back);
    sfVertexArray_destroy(right_leg->bottom);
    sfVertexArray_destroy(right_leg->front);

    right_leg->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->left, sfQuads);
    sfVertexArray_append(right_leg->left, define_vertex(v_lft, sfWhite, define_vectorf(8, 20)));
    sfVertexArray_append(right_leg->left, define_vertex(v_lfb, sfWhite, define_vectorf(8, 32)));
    sfVertexArray_append(right_leg->left, define_vertex(v_lbb, sfWhite, define_vectorf(12, 32)));
    sfVertexArray_append(right_leg->left, define_vertex(v_lbt, sfWhite, define_vectorf(12, 20)));

    right_leg->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->right, sfQuads);
    sfVertexArray_append(right_leg->right, define_vertex(v_rft, sfWhite, define_vectorf(4, 20)));
    sfVertexArray_append(right_leg->right, define_vertex(v_rfb, sfWhite, define_vectorf(4, 32)));
    sfVertexArray_append(right_leg->right, define_vertex(v_rbb, sfWhite, define_vectorf(0, 32)));
    sfVertexArray_append(right_leg->right, define_vertex(v_rbt, sfWhite, define_vectorf(0, 20)));

    right_leg->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->top, sfQuads);
    sfVertexArray_append(right_leg->top, define_vertex(v_lft, sfWhite, define_vectorf(8, 20)));
    sfVertexArray_append(right_leg->top, define_vertex(v_lbt, sfWhite, define_vectorf(8, 16)));
    sfVertexArray_append(right_leg->top, define_vertex(v_rbt, sfWhite, define_vectorf(4, 16)));
    sfVertexArray_append(right_leg->top, define_vertex(v_rft, sfWhite, define_vectorf(4, 20)));

    right_leg->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->back, sfQuads);
    sfVertexArray_append(right_leg->back, define_vertex(v_lbt, sfWhite, define_vectorf(12, 20)));
    sfVertexArray_append(right_leg->back, define_vertex(v_rbt, sfWhite, define_vectorf(16, 20)));
    sfVertexArray_append(right_leg->back, define_vertex(v_rbb, sfWhite, define_vectorf(16, 32)));
    sfVertexArray_append(right_leg->back, define_vertex(v_lbb, sfWhite, define_vectorf(12, 32)));

    right_leg->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->bottom, sfQuads);
    sfVertexArray_append(right_leg->bottom, define_vertex(v_lfb, sfWhite, define_vectorf(12, 20)));
    sfVertexArray_append(right_leg->bottom, define_vertex(v_lbb, sfWhite, define_vectorf(12, 16)));
    sfVertexArray_append(right_leg->bottom, define_vertex(v_rbb, sfWhite, define_vectorf(8, 16)));
    sfVertexArray_append(right_leg->bottom, define_vertex(v_rfb, sfWhite, define_vectorf(8, 20)));

    right_leg->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_leg->front, sfQuads);
    sfVertexArray_append(right_leg->front, define_vertex(v_lft, sfWhite, define_vectorf(8, 20)));
    sfVertexArray_append(right_leg->front, define_vertex(v_rft, sfWhite, define_vectorf(4, 20)));
    sfVertexArray_append(right_leg->front, define_vertex(v_rfb, sfWhite, define_vectorf(4, 32)));
    sfVertexArray_append(right_leg->front, define_vertex(v_lfb, sfWhite, define_vectorf(8, 32)));
}

