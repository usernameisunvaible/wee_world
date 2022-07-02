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
    // chunk_ *chunk = load_chunk(0);
    chunk_ **chunk_list = malloc(sizeof(chunk_ *) * 9);
    chunk_list[0] = load_chunk(0);
    chunk_list[1] = load_chunk(1);
    chunk_list[2] = load_chunk(2);
    chunk_list[3] = load_chunk(NB_CHUNK_MAX );
    chunk_list[4] = load_chunk(NB_CHUNK_MAX + 1);
    chunk_list[5] = load_chunk(NB_CHUNK_MAX + 2);
    chunk_list[6] = load_chunk(NB_CHUNK_MAX * 2 );
    chunk_list[7] = load_chunk(NB_CHUNK_MAX * 2 + 1);
    chunk_list[8] = load_chunk(NB_CHUNK_MAX * 2 + 2);

    while (sfRenderWindow_isOpen(elements->window)) {
        sfRenderWindow_clear(elements->window, sfBlack);
        key_events(elements);
        for (int i = 0; i < 9; ++i) {
            generate_chunk_arrays(s_map, chunk_list[i], elements);
            refresh_chunk(define_vectorf(0, 0), chunk_list[i], elements, textures);

        }
        // refresh_map(elements, s_map, textures);
        refresh_text(elements, fps, my_itoa((int) elements->fps->fps, buf));
        refresh_elements(elements);
    }
    
}