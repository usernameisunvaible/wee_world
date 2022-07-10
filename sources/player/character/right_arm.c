#include "../../../includes/includes.h"

void refresh_right_arm(brick_ *right_arm, map_ *map, character_ *character, elements_t *elements, int angle)
{
    // left / right  | front / back  | bottom / top

    
    sfVector2f v_rft = iso(define_vectortf(-character->size.x / 4 * 4 , character->annim_r_arm->p1.x, character->annim_r_arm->p1.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rfb = iso(define_vectortf(-character->size.x / 4 * 4 , character->annim_r_arm->p2.x, character->annim_r_arm->p2.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rbb = iso(define_vectortf(-character->size.x / 4 * 4 , character->annim_r_arm->p3.x, character->annim_r_arm->p3.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_rbt = iso(define_vectortf(-character->size.x / 4 * 4 , character->annim_r_arm->p4.x, character->annim_r_arm->p4.y), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2 - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lft = iso(define_vectortf(-character->size.x / 2, character->annim_r_arm->p1.x , character->annim_r_arm->p1.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lfb = iso(define_vectortf(-character->size.x / 2, character->annim_r_arm->p2.x , character->annim_r_arm->p2.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lbb = iso(define_vectortf(-character->size.x / 2, character->annim_r_arm->p3.x , character->annim_r_arm->p3.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)), angle);
    sfVector2f v_lbt = iso(define_vectortf(-character->size.x / 2, character->annim_r_arm->p4.x , character->annim_r_arm->p4.y ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2                    - (character->size.z / 10 * 9)), angle);

    sfVertexArray_destroy(right_arm->left);
    sfVertexArray_destroy(right_arm->right);
    sfVertexArray_destroy(right_arm->top);
    sfVertexArray_destroy(right_arm->back);
    sfVertexArray_destroy(right_arm->bottom);
    sfVertexArray_destroy(right_arm->front);

    right_arm->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_arm->left, sfQuads);
    sfVertexArray_append(right_arm->left, define_vertex(v_lft, sfWhite, define_vectorf(48, 20)));
    sfVertexArray_append(right_arm->left, define_vertex(v_lfb, sfWhite, define_vectorf(48, 32)));
    sfVertexArray_append(right_arm->left, define_vertex(v_lbb, sfWhite, define_vectorf(52, 32)));
    sfVertexArray_append(right_arm->left, define_vertex(v_lbt, sfWhite, define_vectorf(52, 20)));

    right_arm->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_arm->right, sfQuads);
    sfVertexArray_append(right_arm->right, define_vertex(v_rft, sfWhite, define_vectorf(44, 20)));
    sfVertexArray_append(right_arm->right, define_vertex(v_rfb, sfWhite, define_vectorf(44, 32)));
    sfVertexArray_append(right_arm->right, define_vertex(v_rbb, sfWhite, define_vectorf(40, 32)));
    sfVertexArray_append(right_arm->right, define_vertex(v_rbt, sfWhite, define_vectorf(40, 20)));

    right_arm->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_arm->top, sfQuads);
    sfVertexArray_append(right_arm->top, define_vertex(v_lft, sfWhite, define_vectorf(48, 20)));
    sfVertexArray_append(right_arm->top, define_vertex(v_lbt, sfWhite, define_vectorf(48, 16)));
    sfVertexArray_append(right_arm->top, define_vertex(v_rbt, sfWhite, define_vectorf(44, 16)));
    sfVertexArray_append(right_arm->top, define_vertex(v_rft, sfWhite, define_vectorf(44, 20)));

    right_arm->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_arm->back, sfQuads);
    sfVertexArray_append(right_arm->back, define_vertex(v_lbt, sfWhite, define_vectorf(52, 20)));
    sfVertexArray_append(right_arm->back, define_vertex(v_rbt, sfWhite, define_vectorf(56, 20)));
    sfVertexArray_append(right_arm->back, define_vertex(v_rbb, sfWhite, define_vectorf(56, 32)));
    sfVertexArray_append(right_arm->back, define_vertex(v_lbb, sfWhite, define_vectorf(52, 32)));

    right_arm->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_arm->bottom, sfQuads);
    sfVertexArray_append(right_arm->bottom, define_vertex(v_lfb, sfWhite, define_vectorf(52, 20)));
    sfVertexArray_append(right_arm->bottom, define_vertex(v_lbb, sfWhite, define_vectorf(52, 16)));
    sfVertexArray_append(right_arm->bottom, define_vertex(v_rbb, sfWhite, define_vectorf(48, 16)));
    sfVertexArray_append(right_arm->bottom, define_vertex(v_rfb, sfWhite, define_vectorf(48, 20)));

    right_arm->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(right_arm->front, sfQuads);
    sfVertexArray_append(right_arm->front, define_vertex(v_lft, sfWhite, define_vectorf(48, 20)));
    sfVertexArray_append(right_arm->front, define_vertex(v_rft, sfWhite, define_vectorf(44, 20)));
    sfVertexArray_append(right_arm->front, define_vertex(v_rfb, sfWhite, define_vectorf(44, 32)));
    sfVertexArray_append(right_arm->front, define_vertex(v_lfb, sfWhite, define_vectorf(48, 32)));
}
