/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef INIT_H_
    #define INIT_H_

    #define CLICK_F 1
    #define SHOW_F 1 << 1

typedef struct {
    long last;
    float fps;
}fps_;


typedef struct elements_s {
    sfRenderWindow *window;
    sfEvent event;
    all_my_tex_t *tex_list;
    chrono_t *chrono;
    all_my_font_t *font_list;
    sfVector2f win_size;
    sfVector2i m_pos;
    sfBool left;
    sfBool right;
    int is_on_p_menu;
    fps_ *fps;
}elements_t;

    #include "init_p.h"

#endif //INIT_H_
