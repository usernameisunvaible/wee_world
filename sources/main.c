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

    map_ *map = load_map(elements, 14);
    texture_ **textures = init_mapstates();
    sfText *fps = text_factory(define_text_params("0","assets/akhirtathun.ttf", define_vectorf(0, 0), 25), elements);
    char buf[4];
    player_ *player = init_player(map, define_vectori(3000, 3000), elements );
    framebuffer_t *fbr = init_framebuffer(define_vectori(elements->win_size.x, elements->win_size.y));
    character_ *character = init_charactere(elements, map);


    while (sfRenderWindow_isOpen(elements->window)) {
        sfRenderWindow_clear(elements->window, sfBlack);
        key_events(elements, player);
        move_player(player, elements, map);
        load_arround(player_chunk(player->pos_on_map, map), map);
        jump(player, elements, map, map->chunk_list[4]);
        appli_move(player, map, elements);

        for (int i = 0; i < 9; ++i) {
            generate_chunk_arrays(player->pos_on_map, map, map->chunk_list[i], elements);
            refresh_chunk( map->chunk_list[i], elements, textures, map);
        }

        refresh_annims(player->character, elements, map);
        refresh_framebuffer(fbr, elements);
        refresh_text(elements, fps, my_itoa((int) elements->fps->fps, buf));
        refresh_elements(elements);
        map->infos->offset = define_vectorf(0, 0);
    }
    free_player(player);
    free_framebuffer(fbr);
    free_map(map);
    free_elements(elements);
    free_mapstates(textures);
    sfText_destroy(fps);
}