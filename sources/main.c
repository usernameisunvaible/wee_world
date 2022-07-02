#include "../includes/includes.h"

elements_t *load_assets(sfVector2i screen)
{
    char *textures[] = {"\0"};
    char *fonts[] = {"\0"};
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
    
    while (sfRenderWindow_isOpen(elements->window)) {
        key_events(elements);
        
        printf("%f\n", elements->fps->fps);
        refresh_map(elements, s_map, textures);
        
        refresh_elements(elements);
    }
    
}