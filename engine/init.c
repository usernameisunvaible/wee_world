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
    

    elements->win_size = define_vectorf(size.x, size.y);
    sfVideoMode mode = {elements->win_size.x, elements->win_size.y, 32};
    elements->window = sfRenderWindow_create(mode, "RPG",
sfClose | sfFullscreen, NULL);
    sfWindow_setFramerateLimit(elements->window, 60);
    elements->tex_list = init_tex(textures_path);
    elements->font_list = init_font(font_path_list);
    elements->chrono = init_chrono();
    elements->m_pos = sfMouse_getPositionRenderWindow(elements->window);
    elements->left = sfMouse_isButtonPressed(sfMouseLeft);
    elements->right = sfMouse_isButtonPressed(sfMouseRight);
    elements->fps = malloc(sizeof(fps_));
    elements->fps->last = elements->chrono->ms;
    elements->fps->fps = 0;
    return elements;
}

void close_elements(elements_t *elements)
{
    free_tex(elements->tex_list);
    free(elements->chrono);
    sfRenderWindow_destroy(elements->window);
}

void refresh_elements(elements_t *elements)
{
    elapse_time(elements->chrono);
    sfRenderWindow_display(elements->window);
    elements->m_pos = sfMouse_getPositionRenderWindow(elements->window);
    elements->left = sfMouse_isButtonPressed(sfMouseLeft);
    elements-> right = sfMouse_isButtonPressed(sfMouseRight);
    elements->fps->fps = 1000.0 / (elements->chrono->ms - elements->fps->last);
    elements->fps->last = elements->chrono->ms;
}