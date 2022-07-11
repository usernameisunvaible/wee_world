#include "../../../includes/includes.h"

    //       o
    //      /|\
    //      / \

sfVector2f iso(sfVector3f p, map_ *map, sfVector2f offset, int angle)
{

    if (angle == 90 || angle == 270) {
        float temp = p.x;
        p.x = p.y;
        p.y = temp;
        // p.x *= -1;
        p.y *= -1;
    }
    if (angle == 90 || angle == 180) {
        p.x = (dcos(180) * p.x) + (p.y * -dsin(180));
        p.y = (dsin(180) * p.x) + (p.y * dcos(180));
    }

    return define_vectorf(map->infos->cos_angle * p.x - map->infos->cos_angle * p.y + offset.x, (map->infos->sin_angle * p.y + map->infos->sin_angle * p.x) + p.z + offset.y);
}

brick_ *init_brick(void)
{
    brick_ *temp = malloc(sizeof(brick_));
    temp->left = sfVertexArray_create();
    temp->right = sfVertexArray_create();
    temp->bottom = sfVertexArray_create();
    temp->top = sfVertexArray_create();
    temp->front = sfVertexArray_create();
    temp->back = sfVertexArray_create();
    return temp;
}

annim_ *init_annim(int dir)
{
    annim_ *annim = malloc(sizeof(annim_));
    annim->angle = 180;
    annim->dir = dir;
    annim->p1 = define_vectorf(0, 0);
    annim->p2 = define_vectorf(0, 0);
    annim->p3 = define_vectorf(0, 0);
    annim->p4 = define_vectorf(0, 0);
    annim->timer = 0;
    annim->timer_tot = 0;
    return annim;
}

character_ *init_charactere(elements_t *elements, map_ *map)
{
    sfVector3f initial_pos = define_vectortf(0, 0, 0);
    character_ *character = malloc(sizeof(character_));
    character->size = define_vectortf( map->infos->bloc_size / 2,  map->infos->bloc_size / 3 ,  map->infos->bloc_size / 3 * 6);
    character->l_leg = init_brick();
    character->r_leg = init_brick();
    character->annim_l_leg = init_annim(1);
    character->annim_r_leg = init_annim(0);
    character->body = init_brick();
    character->l_arm = init_brick();
    character->annim_l_arm = init_annim(0);
    character->r_arm = init_brick();
    character->annim_r_arm = init_annim(1);
    character->head = init_brick();
    character->skin = malloc(sizeof(sfRenderStates));
    character->skin->texture = sfTexture_createFromFile("assets/skin.png", NULL);
    character->skin->blendMode = sfBlendNone;
    character->skin->shader = NULL;
    character->skin->transform = sfTransform_fromMatrix(1,0,1,0,1,0,0,0,1);
    character->angle = 0;
    character->do_annim = sfFalse;

    // character->size.x = (dcos(character->angle) * character->size.x) + (character->size.y * -dsin(character->angle));
    // character->size.y = (dsin(character->angle) * character->size.x) + (character->size.y * dcos(character->angle));
    return character;

}



void refresh_annim_top(annim_ *annim, character_ *character, elements_t *elements, sfBool do_annim)
{
    int droit = 180;
    int ouverture = 50;
    int offset_bottom = 12;
    int angle_bottom = droit - 90;


    annim->timer_tot += elements->chrono->ms - annim->timer;
    while (annim->timer_tot >= PLAYER_ANNIM_SPEED)
    {
        if (do_annim == sfTrue) {
            if (annim->angle <= 180 + ouverture && annim->dir == 1) {
                annim->angle += 2;
            }
            if (annim->angle >= 180 + ouverture && annim->dir == 1) {
                annim->dir = 0;
                annim->angle -= 2;
            }
            if (annim->angle >= 180 - ouverture && annim->dir == 0) {
                annim->angle -= 2;
            }
            if (annim->angle <= 180 - ouverture && annim->dir == 0) {
                annim->dir = 1;
                annim->angle += 2;
            }
        }
        annim->timer_tot -= PLAYER_ANNIM_SPEED;
    }
    annim->timer = elements->chrono->ms;

    angle_bottom = annim->angle - 90;
    annim->p1 = define_vectorf(roundf(dcos((annim->angle + 180)) * (character->size.y / 2)), roundf(dsin((annim->angle + 180)) * (character->size.y / 2)));
    annim->p3 = define_vectorf(roundf(dcos((angle_bottom + offset_bottom)) * (character->size.z  / 10 * 4)), roundf(dsin((angle_bottom + offset_bottom)) * (character->size.z  / 10 * 4)));
    annim->p2 = define_vectorf(roundf(dcos((angle_bottom - offset_bottom)) * (character->size.z  / 10 * 4)), roundf(dsin((angle_bottom - offset_bottom)) * (character->size.z  / 10 * 4)));
    annim->p4 = define_vectorf(roundf(dcos(annim->angle) * (character->size.y / 2)), roundf(dsin(annim->angle) * (character->size.y / 2)));
}

void refresh_annim_botom(annim_ *annim, character_ *character, elements_t *elements, sfBool do_annim)
{
    int droit = 180;
    int ouverture = 50;
    int offset_bottom = 9;
    int angle_bottom = droit - 90;


    annim->timer_tot += elements->chrono->ms - annim->timer;
    while (annim->timer_tot >= PLAYER_ANNIM_SPEED)
    {
        if (do_annim == sfTrue) {
            if (annim->angle <= 180 + ouverture && annim->dir == 1) {
                annim->angle += 2;
            }
            if (annim->angle >= 180 + ouverture && annim->dir == 1) {
                annim->dir = 0;
                annim->angle -= 2;
            }
            if (annim->angle >= 180 - ouverture && annim->dir == 0) {
                annim->angle -= 2;
            }
            if (annim->angle <= 180 - ouverture && annim->dir == 0) {
                annim->dir = 1;
                annim->angle += 2;
            }
        }
        annim->timer_tot -= PLAYER_ANNIM_SPEED;
    }
    annim->timer = elements->chrono->ms;

    angle_bottom = annim->angle - 90;
    annim->p1 = define_vectorf(roundf(dcos((annim->angle + 180)) * character->size.y / 2), roundf(dsin((annim->angle + 180)) * character->size.y / 2));
    annim->p3 = define_vectorf(roundf(dcos((angle_bottom + offset_bottom)) * character->size.z / 2), roundf(dsin((angle_bottom + offset_bottom)) * character->size.z / 2));
    annim->p2 = define_vectorf(roundf(dcos((angle_bottom - offset_bottom)) * character->size.z / 2), roundf(dsin((angle_bottom - offset_bottom)) * character->size.z / 2));
    annim->p4 = define_vectorf(roundf(dcos(annim->angle) * character->size.y / 2), roundf(dsin(annim->angle) * character->size.y / 2));
}

void refresh_annims(character_ *character, elements_t *elements, map_ *map)
{
    refresh_annim_top(character->annim_l_arm, character, elements, character->do_annim);
    refresh_annim_top(character->annim_r_arm, character, elements, character->do_annim);
    refresh_annim_botom(character->annim_l_leg, character, elements, character->do_annim);
    refresh_annim_botom(character->annim_r_leg, character, elements, character->do_annim);
    refresh_left_leg(character->l_leg, map, character, elements, character->angle);
    refresh_right_leg(character->r_leg, map, character, elements, character->angle);
    refresh_body(character->body, map, character, elements, character->angle);
    refresh_left_arm(character->l_arm,map, character, elements, character->angle);
    refresh_right_arm(character->r_arm,map, character, elements, character->angle);
    refresh_head(character->head, map, character, elements, character->angle);
    display_character(elements, character);
    // display_brick(elements, character->r_arm, character);
    // display_brick(elements, character->r_leg, character);
    // display_brick(elements, character->l_leg, character);
    // display_brick(elements, character->body, character);
    // display_brick(elements, character->l_arm, character);
    // display_brick(elements, character->head, character);
}

void display_brick(elements_t *elements, brick_ *brick, character_ *character)
{
    sfRenderWindow_drawVertexArray(elements->window, brick->right, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, brick->bottom, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, brick->back, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, brick->front, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, brick->left, character->skin);
    sfRenderWindow_drawVertexArray(elements->window, brick->top, character->skin);
}





