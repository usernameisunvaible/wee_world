#include "../../../includes/includes.h"

void refresh_left_arm(brick_ *left_arm, map_ *map, character_ *character, elements_t *elements, int angle)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lft = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p1.x , character->annim_l_arm->p1.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lfb = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p2.x , character->annim_l_arm->p2.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lbb = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p3.x , character->annim_l_arm->p3.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lbt = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p4.x , character->annim_l_arm->p4.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rft = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p1.x , character->annim_l_arm->p1.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rfb = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p2.x , character->annim_l_arm->p2.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rbb = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p3.x , character->annim_l_arm->p3.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rbt = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p4.x , character->annim_l_arm->p4.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);

    sfVertexArray_destroy(left_arm->left);
    sfVertexArray_destroy(left_arm->right);
    sfVertexArray_destroy(left_arm->top);
    sfVertexArray_destroy(left_arm->back);
    sfVertexArray_destroy(left_arm->bottom);
    sfVertexArray_destroy(left_arm->front);

    left_arm->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->left, sfQuads);
    sfVertexArray_append(left_arm->left, define_vertex(v_lft, sfWhite, define_vectorf(40, 52)));
    sfVertexArray_append(left_arm->left, define_vertex(v_lfb, sfWhite, define_vectorf(40, 64)));
    sfVertexArray_append(left_arm->left, define_vertex(v_lbb, sfWhite, define_vectorf(44, 64)));
    sfVertexArray_append(left_arm->left, define_vertex(v_lbt, sfWhite, define_vectorf(44, 52)));

    left_arm->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->right, sfQuads);
    sfVertexArray_append(left_arm->right, define_vertex(v_rft, sfWhite, define_vectorf(36, 52)));
    sfVertexArray_append(left_arm->right, define_vertex(v_rfb, sfWhite, define_vectorf(36, 64)));
    sfVertexArray_append(left_arm->right, define_vertex(v_rbb, sfWhite, define_vectorf(32, 64)));
    sfVertexArray_append(left_arm->right, define_vertex(v_rbt, sfWhite, define_vectorf(32, 52)));

    left_arm->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->top, sfQuads);
    sfVertexArray_append(left_arm->top, define_vertex(v_lft, sfWhite, define_vectorf(40, 52)));
    sfVertexArray_append(left_arm->top, define_vertex(v_lbt, sfWhite, define_vectorf(40, 48)));
    sfVertexArray_append(left_arm->top, define_vertex(v_rbt, sfWhite, define_vectorf(36, 48)));
    sfVertexArray_append(left_arm->top, define_vertex(v_rft, sfWhite, define_vectorf(36, 52)));

    left_arm->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->back, sfQuads);
    sfVertexArray_append(left_arm->back, define_vertex(v_lbt, sfWhite, define_vectorf(44, 52)));
    sfVertexArray_append(left_arm->back, define_vertex(v_rbt, sfWhite, define_vectorf(48, 52)));
    sfVertexArray_append(left_arm->back, define_vertex(v_rbb, sfWhite, define_vectorf(48, 64)));
    sfVertexArray_append(left_arm->back, define_vertex(v_lbb, sfWhite, define_vectorf(44, 64)));

    left_arm->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->bottom, sfQuads);
    sfVertexArray_append(left_arm->bottom, define_vertex(v_lfb, sfWhite, define_vectorf(44, 52)));
    sfVertexArray_append(left_arm->bottom, define_vertex(v_lbb, sfWhite, define_vectorf(44, 48)));
    sfVertexArray_append(left_arm->bottom, define_vertex(v_rbb, sfWhite, define_vectorf(40, 48)));
    sfVertexArray_append(left_arm->bottom, define_vertex(v_rfb, sfWhite, define_vectorf(40, 52)));

    left_arm->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->front, sfQuads);
    sfVertexArray_append(left_arm->front, define_vertex(v_lft, sfWhite, define_vectorf(40, 52)));
    sfVertexArray_append(left_arm->front, define_vertex(v_rft, sfWhite, define_vectorf(36, 52)));
    sfVertexArray_append(left_arm->front, define_vertex(v_rfb, sfWhite, define_vectorf(36, 64)));
    sfVertexArray_append(left_arm->front, define_vertex(v_lfb, sfWhite, define_vectorf(40, 64)));
}
