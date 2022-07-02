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

    char *map = malloc(sizeof(char) * 64 *64);
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            map[j * 64 + i] = (char) (perlin2d(i, j, 0.02, 25) * 10);
        }
    }
    map_ *s_map = load_map(map, define_vectori(64, 64), elements);
    texture_ **textures = init_mapstates();
    sfText *fps = text_factory(define_text_params("0","assets/akhirtathun.ttf", define_vectorf(0, 0), 25), elements);
    char buf[4];
    chunk_ *chunk = load_chunk(0);

    while (sfRenderWindow_isOpen(elements->window)) {
        sfRenderWindow_clear(elements->window, sfBlack);
        key_events(elements);
        generate_chunk_arrays(s_map, chunk, elements);
        refresh_chunk(define_vectorf(0, 0), chunk, elements, textures);
        // refresh_map(elements, s_map, textures);
        refresh_text(elements, fps, my_itoa((int) elements->fps->fps, buf));
        refresh_elements(elements);
    }
    
}