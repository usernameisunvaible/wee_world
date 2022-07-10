#include "../../../includes/includes.h"

void refresh_left_leg(brick_ *left_leg, map_ *map, character_ *character, elements_t *elements, int angle)
{
    // left / right  | front / back  | bottom / top
    sfVector2f v_lft = iso(define_vectortf(character->size.x / 2, character->annim_l_leg->p1.x , character->annim_l_leg->p1.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_lfb = iso(define_vectortf(character->size.x / 2, character->annim_l_leg->p2.x , character->annim_l_leg->p2.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_lbb = iso(define_vectortf(character->size.x / 2, character->annim_l_leg->p3.x , character->annim_l_leg->p3.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_lbt = iso(define_vectortf(character->size.x / 2, character->annim_l_leg->p4.x , character->annim_l_leg->p4.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rft = iso(define_vectortf(0, character->annim_l_leg->p1.x , character->annim_l_leg->p1.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rfb = iso(define_vectortf(0, character->annim_l_leg->p2.x , character->annim_l_leg->p2.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rbb = iso(define_vectortf(0, character->annim_l_leg->p3.x , character->annim_l_leg->p3.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);
    sfVector2f v_rbt = iso(define_vectortf(0, character->annim_l_leg->p4.x , character->annim_l_leg->p4.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - character->size.z / 2), angle);

    sfVertexArray_destroy(left_leg->left);
    sfVertexArray_destroy(left_leg->right);
    sfVertexArray_destroy(left_leg->top);
    sfVertexArray_destroy(left_leg->back);
    sfVertexArray_destroy(left_leg->bottom);
    sfVertexArray_destroy(left_leg->front);

    left_leg->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_leg->left, sfQuads);
    sfVertexArray_append(left_leg->left, define_vertex(v_lft, sfWhite, define_vectorf(24, 52)));
    sfVertexArray_append(left_leg->left, define_vertex(v_lfb, sfWhite, define_vectorf(24, 64)));
    sfVertexArray_append(left_leg->left, define_vertex(v_lbb, sfWhite, define_vectorf(28, 64)));
    sfVertexArray_append(left_leg->left, define_vertex(v_lbt, sfWhite, define_vectorf(28, 52)));

    left_leg->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_leg->right, sfQuads);
    sfVertexArray_append(left_leg->right, define_vertex(v_rft, sfWhite, define_vectorf(20, 52)));
    sfVertexArray_append(left_leg->right, define_vertex(v_rfb, sfWhite, define_vectorf(20, 64)));
    sfVertexArray_append(left_leg->right, define_vertex(v_rbb, sfWhite, define_vectorf(16, 64)));
    sfVertexArray_append(left_leg->right, define_vertex(v_rbt, sfWhite, define_vectorf(16, 52)));

    left_leg->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_leg->top, sfQuads);
    sfVertexArray_append(left_leg->top, define_vertex(v_lft, sfWhite, define_vectorf(24, 52)));
    sfVertexArray_append(left_leg->top, define_vertex(v_lbt, sfWhite, define_vectorf(24, 48)));
    sfVertexArray_append(left_leg->top, define_vertex(v_rbt, sfWhite, define_vectorf(20, 48)));
    sfVertexArray_append(left_leg->top, define_vertex(v_rft, sfWhite, define_vectorf(20, 52)));

    left_leg->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_leg->back, sfQuads);
    sfVertexArray_append(left_leg->back, define_vertex(v_lbt, sfWhite, define_vectorf(28, 52)));
    sfVertexArray_append(left_leg->back, define_vertex(v_rbt, sfWhite, define_vectorf(32, 52)));
    sfVertexArray_append(left_leg->back, define_vertex(v_rbb, sfWhite, define_vectorf(32, 64)));
    sfVertexArray_append(left_leg->back, define_vertex(v_lbb, sfWhite, define_vectorf(28, 64)));

    left_leg->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_leg->bottom, sfQuads);
    sfVertexArray_append(left_leg->bottom, define_vertex(v_lfb, sfWhite, define_vectorf(28, 52)));
    sfVertexArray_append(left_leg->bottom, define_vertex(v_lbb, sfWhite, define_vectorf(28, 48)));
    sfVertexArray_append(left_leg->bottom, define_vertex(v_rbb, sfWhite, define_vectorf(24, 48)));
    sfVertexArray_append(left_leg->bottom, define_vertex(v_rfb, sfWhite, define_vectorf(24, 52)));

    left_leg->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_leg->front, sfQuads);
    sfVertexArray_append(left_leg->front, define_vertex(v_lft, sfWhite, define_vectorf(24, 52)));
    sfVertexArray_append(left_leg->front, define_vertex(v_rft, sfWhite, define_vectorf(20, 52)));
    sfVertexArray_append(left_leg->front, define_vertex(v_rfb, sfWhite, define_vectorf(20, 64)));
    sfVertexArray_append(left_leg->front, define_vertex(v_lfb, sfWhite, define_vectorf(24, 64)));
}
