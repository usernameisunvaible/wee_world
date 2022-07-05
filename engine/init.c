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



elements_t *init_elements(char **textures_path, char **font_path_list, sfVector2i size)
{
    elements_t *elements = malloc(sizeof(elements_t));
    
    if (elements == NULL) {return NULL;}
    elements->win_size = define_vectorf(size.x, size.y);
    sfVideoMode mode = {elements->win_size.x, elements->win_size.y, 32};
    elements->window = sfRenderWindow_create(mode, "WeeWorld", sfClose | sfFullscreen, NULL);
    if (elements->window == NULL) {
        free(elements);
        return NULL;
    }
    elements->tex_list = init_texture(textures_path);
    if (elements->tex_list == NULL && textures_path[0][0]) {
        sfRenderWindow_destroy(elements->window);
        free(elements);
        return NULL;
    }
    elements->font_list = init_font(font_path_list);
    if (elements->font_list == NULL && font_path_list[0][0]) {
        free_texture(elements->tex_list);
        sfRenderWindow_destroy(elements->window);
        free(elements);
        return NULL;
    }
    elements->chrono = init_chrono();
    if(elements->chrono == NULL) {
        free_font(elements->font_list);
        free_texture(elements->tex_list);
        sfRenderWindow_destroy(elements->window);
        free(elements);
        return NULL;
    }
    elements->fps = malloc(sizeof(fps_));
    if (elements->fps == NULL) {
        free_chrono(elements->chrono);
        free_font(elements->font_list);
        free_texture(elements->tex_list);
        sfRenderWindow_destroy(elements->window);
        free(elements);
        return NULL;
    }

    elements->m_pos = sfMouse_getPositionRenderWindow(elements->window);
    elements->left = sfMouse_isButtonPressed(sfMouseLeft);
    elements->right = sfMouse_isButtonPressed(sfMouseRight);
    elements->fps->last = elements->chrono->ms;
    elements->fps->fps = 0;
    return elements;
}


void free_elements(elements_t *elements)
{
    if (elements->tex_list)
        free_texture(elements->tex_list);
    if (elements->font_list)
        free_font(elements->font_list);
    free_chrono(elements->chrono);
    free(elements->fps);
    sfRenderWindow_destroy(elements->window);
    free(elements);
}

void refresh_elements(elements_t *elements)
{
    refresh_chrono(elements->chrono);
    sfRenderWindow_display(elements->window);
    elements->m_pos = sfMouse_getPositionRenderWindow(elements->window);
    elements->left = sfMouse_isButtonPressed(sfMouseLeft);
    elements-> right = sfMouse_isButtonPressed(sfMouseRight);
    elements->fps->fps = 1000.0 / (elements->chrono->ms - elements->fps->last);
    elements->fps->last = elements->chrono->ms;
}