#include "../../../includes/includes.h"

void refresh_body(brick_ *body, map_ *map, character_ *character, elements_t *elements, int angle)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lfb = iso(define_vectortf(character->size.x / 2, character->size.y / 2  , character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2   - (character->size.z * 1.4)), angle);
    sfVector2f v_lft = iso(define_vectortf(character->size.x / 2, character->size.y / 2  , character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2       - (character->size.z * 1.4)), angle);
    sfVector2f v_lbt = iso(define_vectortf(character->size.x / 2, -character->size.y / 2 , character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2       - (character->size.z * 1.4)), angle);
    sfVector2f v_lbb = iso(define_vectortf(character->size.x / 2, -character->size.y / 2 , character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2   - (character->size.z * 1.4)), angle);
    sfVector2f v_rfb = iso(define_vectortf(-character->size.x / 2, character->size.y / 2 , character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2  - (character->size.z * 1.4)), angle);
    sfVector2f v_rft = iso(define_vectortf(-character->size.x / 2, character->size.y / 2 , character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2      - (character->size.z * 1.4)), angle);
    sfVector2f v_rbt = iso(define_vectortf(-character->size.x / 2, -character->size.y / 2, character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2      - (character->size.z * 1.4)), angle);
    sfVector2f v_rbb = iso(define_vectortf(-character->size.x / 2, -character->size.y / 2, character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2  - (character->size.z * 1.4)), angle);

    sfVertexArray_destroy(body->left);
    sfVertexArray_destroy(body->right);
    sfVertexArray_destroy(body->top);
    sfVertexArray_destroy(body->back);
    sfVertexArray_destroy(body->bottom);
    sfVertexArray_destroy(body->front);

    body->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->left, sfQuads);
    sfVertexArray_append(body->left, define_vertex(v_lft, sfWhite, define_vectorf(28, 20)));
    sfVertexArray_append(body->left, define_vertex(v_lfb, sfWhite, define_vectorf(28, 32)));
    sfVertexArray_append(body->left, define_vertex(v_lbb, sfWhite, define_vectorf(32, 32)));
    sfVertexArray_append(body->left, define_vertex(v_lbt, sfWhite, define_vectorf(32, 20)));

    body->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->right, sfQuads);
    sfVertexArray_append(body->right, define_vertex(v_rft, sfWhite, define_vectorf(20, 20)));
    sfVertexArray_append(body->right, define_vertex(v_rfb, sfWhite, define_vectorf(20, 32)));
    sfVertexArray_append(body->right, define_vertex(v_rbb, sfWhite, define_vectorf(16, 32)));
    sfVertexArray_append(body->right, define_vertex(v_rbt, sfWhite, define_vectorf(16, 20)));

    body->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->top, sfQuads);
    sfVertexArray_append(body->top, define_vertex(v_lft, sfWhite, define_vectorf(28, 20)));
    sfVertexArray_append(body->top, define_vertex(v_lbt, sfWhite, define_vectorf(28, 16)));
    sfVertexArray_append(body->top, define_vertex(v_rbt, sfWhite, define_vectorf(20, 16)));
    sfVertexArray_append(body->top, define_vertex(v_rft, sfWhite, define_vectorf(20, 20)));

    body->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->back, sfQuads);
    sfVertexArray_append(body->back, define_vertex(v_lbt, sfWhite, define_vectorf(32, 20)));
    sfVertexArray_append(body->back, define_vertex(v_rbt, sfWhite, define_vectorf(40, 20)));
    sfVertexArray_append(body->back, define_vertex(v_rbb, sfWhite, define_vectorf(40, 32)));
    sfVertexArray_append(body->back, define_vertex(v_lbb, sfWhite, define_vectorf(32, 32)));

    body->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->bottom, sfQuads);
    sfVertexArray_append(body->bottom, define_vertex(v_lfb, sfWhite, define_vectorf(28, 32)));
    sfVertexArray_append(body->bottom, define_vertex(v_lbb, sfWhite, define_vectorf(28, 36)));
    sfVertexArray_append(body->bottom, define_vertex(v_rbb, sfWhite, define_vectorf(20, 36)));
    sfVertexArray_append(body->bottom, define_vertex(v_rfb, sfWhite, define_vectorf(20, 32)));

    body->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->front, sfQuads);
    sfVertexArray_append(body->front, define_vertex(v_lft, sfWhite, define_vectorf(28, 20)));
    sfVertexArray_append(body->front, define_vertex(v_rft, sfWhite, define_vectorf(20, 20)));
    sfVertexArray_append(body->front, define_vertex(v_rfb, sfWhite, define_vectorf(20, 32)));
    sfVertexArray_append(body->front, define_vertex(v_lfb, sfWhite, define_vectorf(28, 32)));
}