#include "../../../includes/includes.h"

void refresh_left_arm(brick_ *left_arm, map_ *map, character_ *character, elements_t *elements)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lft = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p1.x - character->size.y / 2, character->annim_l_arm->p1.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)));
    sfVector2f v_lfb = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p2.x - character->size.y / 2, character->annim_l_arm->p2.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)));
    sfVector2f v_lbb = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p3.x - character->size.y / 2, character->annim_l_arm->p3.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)));
    sfVector2f v_lbt = iso(define_vectortf(character->size.x / 4 * 4 , character->annim_l_arm->p4.x - character->size.y / 2, character->annim_l_arm->p4.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)));
    sfVector2f v_rft = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p1.x - character->size.y / 4 , character->annim_l_arm->p1.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)));
    sfVector2f v_rfb = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p2.x - character->size.y / 4 , character->annim_l_arm->p2.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)));
    sfVector2f v_rbb = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p3.x - character->size.y / 4 , character->annim_l_arm->p3.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)));
    sfVector2f v_rbt = iso(define_vectortf(character->size.x / 2, character->annim_l_arm->p4.x - character->size.y / 4 , character->annim_l_arm->p4.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)));

    sfVertexArray_destroy(left_arm->left);
    sfVertexArray_destroy(left_arm->right);
    sfVertexArray_destroy(left_arm->top);
    sfVertexArray_destroy(left_arm->back);
    sfVertexArray_destroy(left_arm->bottom);
    sfVertexArray_destroy(left_arm->front);

    left_arm->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->left, sfQuads);
    sfVertexArray_append(left_arm->left, define_vertex(v_lft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->left, define_vertex(v_lfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->left, define_vertex(v_lbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->left, define_vertex(v_lbt, sfBlue, define_vectorf(0, 0)));

    left_arm->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->right, sfQuads);
    sfVertexArray_append(left_arm->right, define_vertex(v_rft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->right, define_vertex(v_rfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->right, define_vertex(v_rbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->right, define_vertex(v_rbt, sfBlue, define_vectorf(0, 0)));

    left_arm->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->top, sfQuads);
    sfVertexArray_append(left_arm->top, define_vertex(v_lft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->top, define_vertex(v_lbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->top, define_vertex(v_rbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->top, define_vertex(v_rft, sfBlue, define_vectorf(0, 0)));

    left_arm->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->back, sfQuads);
    sfVertexArray_append(left_arm->back, define_vertex(v_lbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->back, define_vertex(v_rbt, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->back, define_vertex(v_rbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->back, define_vertex(v_lbb, sfBlue, define_vectorf(0, 0)));

    left_arm->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->bottom, sfQuads);
    sfVertexArray_append(left_arm->bottom, define_vertex(v_lfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->bottom, define_vertex(v_lbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->bottom, define_vertex(v_rbb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->bottom, define_vertex(v_rfb, sfBlue, define_vectorf(0, 0)));

    left_arm->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(left_arm->front, sfQuads);
    sfVertexArray_append(left_arm->front, define_vertex(v_lft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->front, define_vertex(v_rft, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->front, define_vertex(v_rfb, sfBlue, define_vectorf(0, 0)));
    sfVertexArray_append(left_arm->front, define_vertex(v_lfb, sfBlue, define_vectorf(0, 0)));
}
