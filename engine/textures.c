/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "includes/include_engine.h"

sfTexture *get_texture(char *path, all_my_tex_t *list)
{
    all_my_tex_t *temp;

    temp = list;
    while (temp != NULL) {
        if (str_comp(path, temp->path))
            return temp->texture;
        temp = temp->next;
    }
    return NULL;
}

static sfBool add_tex(char *path, all_my_tex_t **list)
{
    sfVector2u buf;
    all_my_tex_t *part = malloc(sizeof(all_my_tex_t));
    part->pixels = malloc(sizeof(sfUint8) * buf.x * buf.y * 4);

    if (part == NULL) {return sfFalse;}
    if (part->pixels == NULL) {free(part); return sfFalse;}
    part->path = path;
    part->image = sfImage_createFromFile(path);
    part->texture = sfTexture_createFromImage(part->image, NULL);
    buf = sfTexture_getSize(part->texture);
    part->pixels = sfImage_getPixelsPtr(part->image);
    part->next = *list;
    *list = part;
    return sfTrue;
}

void free_texture(all_my_tex_t *list)
{
    all_my_tex_t *temp;

    temp = list;
    while (list != NULL) {
        list = list->next;
        sfImage_destroy(temp->image);
        sfTexture_destroy(temp->texture);
        free((sfUint8 *)temp->pixels);
        free(temp);
        temp = list;
    }
}

all_my_tex_t *init_texture(char **textures_paths)
{
    all_my_tex_t *list = NULL;

    for (int i = 0; textures_paths[i][0]; ++i) {
        if (add_tex(textures_paths[i], &list) == sfFalse) {
            free_texture(list);
            return NULL;
        }
    }
    return list;
}
