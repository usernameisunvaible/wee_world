#include "../includes/includes.h"

elements_t *load_assets(sfVector2i screen)
{
    char *textures[] = {"\0"};
    char *fonts[] = {"assets/akhirtathun.ttf", "\0"};
    return init_elements(textures, fonts, screen);
}




int main (int ac, char **av)
{
    elements_t *elements = load_assets(define_vectori(1920, 1080));

    char *map ;
    map_ *s_map = load_map(map, define_vectori(32, 32), elements);
    texture_ **textures = init_mapstates();
    sfText *fps = text_factory(define_text_params("0","assets/akhirtathun.ttf", define_vectorf(0, 0), 25), elements);
    char buf[4];
    player_ *player = init_player();

    framebuffer_t *fbr = init_framebuffer(define_vectori(elements->win_size.x, elements->win_size.y));
    while (sfRenderWindow_isOpen(elements->window)) {
        
        sfRenderWindow_clear(elements->window, sfBlack);
        key_events(elements, player);
        move_player(player, elements);
        appli_move(player, s_map, elements, s_map->chunk_list[0]);
        for (int i = 0; i < 1; ++i) {
            generate_chunk_arrays(player->pos_on_map, s_map, s_map->chunk_list[i], elements);
            refresh_chunk( s_map->chunk_list[i], elements, textures);
        }
        draw_circle_from_point(define_vectori(elements->win_size.x/2, elements->win_size.y / 2), 10, fbr, sfMagenta);
        refresh_framebuffer(fbr, elements);
        refresh_text(elements, fps, my_itoa((int) elements->fps->fps, buf));
        refresh_elements(elements);
        s_map->infos->offset = define_vectorf(0, 0);

    }
}