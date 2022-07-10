#include "../../../includes/includes.h"

void refresh_head(brick_ *head, map_ *map, character_ *character, elements_t *elements, int angle)
{

    // left / right  | front / back  | bottom / top
    sfVector2f v_lft = iso(define_vectortf(( character->size.x / 7 * 3), ( character->size.y / 3 * 2) , character->size.z / 10 * 9   ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2   - (character->size.z * 2)), angle);
    sfVector2f v_lfb = iso(define_vectortf(( character->size.x / 7 * 3), ( character->size.y / 3 * 2) , character->size.z / 10 * 11.3  ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2       - (character->size.z * 2)), angle);
    sfVector2f v_lbb = iso(define_vectortf(( character->size.x / 7 * 3), (-character->size.y / 3 * 2) , character->size.z / 10 * 11.3), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2       - (character->size.z * 2)), angle);
    sfVector2f v_lbt = iso(define_vectortf(( character->size.x / 7 * 3), (-character->size.y / 3 * 2) , character->size.z / 10 * 9 ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2   - (character->size.z * 2)), angle);
    sfVector2f v_rft = iso(define_vectortf((-character->size.x / 7 * 3), ( character->size.y / 3 * 2) , character->size.z / 10 * 9   ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2  - (character->size.z * 2)), angle);
    sfVector2f v_rfb = iso(define_vectortf((-character->size.x / 7 * 3), ( character->size.y / 3 * 2) , character->size.z / 10 * 11.3  ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2      - (character->size.z * 2)), angle);
    sfVector2f v_rbb = iso(define_vectortf((-character->size.x / 7 * 3), (-character->size.y / 3 * 2) , character->size.z / 10 * 11.3), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2      - (character->size.z * 2)), angle);
    sfVector2f v_rbt = iso(define_vectortf((-character->size.x / 7 * 3), (-character->size.y / 3 * 2) , character->size.z / 10 * 9 ), map, define_vectorf(elements->win_size.x / 2, elements->win_size.y / 2  - (character->size.z * 2)), angle);

    sfVertexArray_destroy(head->left);
    sfVertexArray_destroy(head->right);
    sfVertexArray_destroy(head->top);
    sfVertexArray_destroy(head->back);
    sfVertexArray_destroy(head->bottom);
    sfVertexArray_destroy(head->front);

    head->left = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(head->left, sfQuads);
    sfVertexArray_append(head->left, define_vertex(v_lft, sfWhite, define_vectorf(16, 8)));
    sfVertexArray_append(head->left, define_vertex(v_lfb, sfWhite, define_vectorf(16, 16)));
    sfVertexArray_append(head->left, define_vertex(v_lbb, sfWhite, define_vectorf(24, 16)));
    sfVertexArray_append(head->left, define_vertex(v_lbt, sfWhite, define_vectorf(24, 8)));

    head->right = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(head->right, sfQuads);
    sfVertexArray_append(head->right, define_vertex(v_rft, sfWhite, define_vectorf(8, 8)));
    sfVertexArray_append(head->right, define_vertex(v_rfb, sfWhite, define_vectorf(8, 16)));
    sfVertexArray_append(head->right, define_vertex(v_rbb, sfWhite, define_vectorf(0, 16)));
    sfVertexArray_append(head->right, define_vertex(v_rbt, sfWhite, define_vectorf(0, 8)));

    head->top = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(head->top, sfQuads);
    sfVertexArray_append(head->top, define_vertex(v_lft, sfWhite, define_vectorf(16, 8)));
    sfVertexArray_append(head->top, define_vertex(v_lbt, sfWhite, define_vectorf(16, 0)));
    sfVertexArray_append(head->top, define_vertex(v_rbt, sfWhite, define_vectorf(8, 0)));
    sfVertexArray_append(head->top, define_vertex(v_rft, sfWhite, define_vectorf(8, 8)));

    head->back = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(head->back, sfQuads);
    sfVertexArray_append(head->back, define_vertex(v_lbt, sfWhite, define_vectorf(24, 8)));
    sfVertexArray_append(head->back, define_vertex(v_rbt, sfWhite, define_vectorf(32, 8)));
    sfVertexArray_append(head->back, define_vertex(v_rbb, sfWhite, define_vectorf(32, 16)));
    sfVertexArray_append(head->back, define_vertex(v_lbb, sfWhite, define_vectorf(24, 16)));

    head->bottom = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(head->bottom, sfQuads);
    sfVertexArray_append(head->bottom, define_vertex(v_lfb, sfWhite, define_vectorf(16, 0)));
    sfVertexArray_append(head->bottom, define_vertex(v_lbb, sfWhite, define_vectorf(24, 0)));
    sfVertexArray_append(head->bottom, define_vertex(v_rbb, sfWhite, define_vectorf(24, 8)));
    sfVertexArray_append(head->bottom, define_vertex(v_rfb, sfWhite, define_vectorf(16, 8)));

    head->front = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(head->front, sfQuads);
    sfVertexArray_append(head->front, define_vertex(v_lft, sfWhite, define_vectorf(16, 8)));
    sfVertexArray_append(head->front, define_vertex(v_rft, sfWhite, define_vectorf(8, 8)));
    sfVertexArray_append(head->front, define_vertex(v_rfb, sfWhite, define_vectorf(8, 16)));
    sfVertexArray_append(head->front, define_vertex(v_lfb, sfWhite, define_vectorf(16, 16)));
}