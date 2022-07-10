#include "../../../includes/includes.h"

void refresh_body(brick_ *body, map_ *map, character_ *character, elements_t *elements)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lfb = iso(define_vectortf(character->size.x / 2, character->size.y / 2  - character->size.y / 4, character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2   - (character->size.z * 1.4)));
    sfVector2f v_lft = iso(define_vectortf(character->size.x / 2, character->size.y / 2  - character->size.y / 4, character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2       - (character->size.z * 1.4)));
    sfVector2f v_lbt = iso(define_vectortf(character->size.x / 2, -character->size.y / 2 - character->size.y / 4, character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2       - (character->size.z * 1.4)));
    sfVector2f v_lbb = iso(define_vectortf(character->size.x / 2, -character->size.y / 2 - character->size.y / 4, character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2   - (character->size.z * 1.4)));
    sfVector2f v_rfb = iso(define_vectortf(-character->size.x / 2, character->size.y / 2  + character->size.y / 4, character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2  - (character->size.z * 1.4)));
    sfVector2f v_rft = iso(define_vectortf(-character->size.x / 2, character->size.y / 2  + character->size.y / 4, character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2      - (character->size.z * 1.4)));
    sfVector2f v_rbt = iso(define_vectortf(-character->size.x / 2, -character->size.y / 2 + character->size.y / 4, character->size.z / 2), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2      - (character->size.z * 1.4)));
    sfVector2f v_rbb = iso(define_vectortf(-character->size.x / 2, -character->size.y / 2 + character->size.y / 4, character->size.z / 10 * 9), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2  - (character->size.z * 1.4)));

    sfVertexArray_destroy(body->left);
    sfVertexArray_destroy(body->right);
    sfVertexArray_destroy(body->top);
    sfVertexArray_destroy(body->back);
    sfVertexArray_destroy(body->bottom);
    sfVertexArray_destroy(body->front);

    body->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->left, sfQuads);
    sfVertexArray_append(body->left, define_vertex(v_lft, sfRed, define_vectorf(0, 0)));
    sfVertexArray_append(body->left, define_vertex(v_lfb, sfRed, define_vectorf(0, 0)));
    sfVertexArray_append(body->left, define_vertex(v_lbb, sfRed, define_vectorf(0, 0)));
    sfVertexArray_append(body->left, define_vertex(v_lbt, sfRed, define_vectorf(0, 0)));

    body->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->right, sfQuads);
    sfVertexArray_append(body->right, define_vertex(v_rft, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->right, define_vertex(v_rfb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->right, define_vertex(v_rbb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->right, define_vertex(v_rbt, sfMagenta, define_vectorf(0, 0)));

    body->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->top, sfQuads);
    sfVertexArray_append(body->top, define_vertex(v_lft, sfBlack, define_vectorf(0, 0)));
    sfVertexArray_append(body->top, define_vertex(v_lbt, sfBlack, define_vectorf(0, 0)));
    sfVertexArray_append(body->top, define_vertex(v_rbt, sfBlack, define_vectorf(0, 0)));
    sfVertexArray_append(body->top, define_vertex(v_rft, sfBlack, define_vectorf(0, 0)));

    body->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->back, sfQuads);
    sfVertexArray_append(body->back, define_vertex(v_lbt, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->back, define_vertex(v_rbt, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->back, define_vertex(v_rbb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->back, define_vertex(v_lbb, sfMagenta, define_vectorf(0, 0)));

    body->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->bottom, sfQuads);
    sfVertexArray_append(body->bottom, define_vertex(v_lfb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->bottom, define_vertex(v_lbb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->bottom, define_vertex(v_rbb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->bottom, define_vertex(v_rfb, sfMagenta, define_vectorf(0, 0)));

    body->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(body->front, sfQuads);
    sfVertexArray_append(body->front, define_vertex(v_lft, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->front, define_vertex(v_rft, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->front, define_vertex(v_rfb, sfMagenta, define_vectorf(0, 0)));
    sfVertexArray_append(body->front, define_vertex(v_lfb, sfMagenta, define_vectorf(0, 0)));
}