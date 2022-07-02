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
    framebuffer_t *fbr = init_framebuffer(define_vectori(1920, 1080));
    while (sfRenderWindow_isOpen(elements->window)) {
        
        sfRenderWindow_clear(elements->window, sfBlack);
        key_events(elements, player);
        // player->pos_on_map.x += 0.05;
        
        draw_rect(fbr, define_rect(0, 0, 1920, 1080), sfTransparent);
        for (int i = 0; i < 1; ++i) {
            generate_chunk_arrays(player->pos_on_map, s_map, chunk_list[i], elements);
            refresh_chunk( chunk_list[i], elements, textures);

        }
        draw_circle_from_point(define_vectori(((s_map->infos->cos_angle * get_pos_on_map(player, s_map).x - s_map->infos->cos_angle * get_pos_on_map(player, s_map).y ) * s_map->infos->bloc_size + s_map->infos->offset.x), ((s_map->infos->sin_angle * player->pos_on_map.y + s_map->infos->sin_angle * player->pos_on_map.x - (chunk_list[0]->mapping[(int)(get_pos_on_map(player, s_map).y) * 32 + (int)(get_pos_on_map(player, s_map).x)]) * s_map->infos->bloc_size + s_map->infos->offset.y))), 10, fbr, sfMagenta);
        refresh_framebuffer(fbr, elements);

        
        move_player(player, chunk_list[0], s_map);
        // refresh_map(elements, s_map, textures);
    //     (float)cos(angle/180.0) * vec.x - cos(angle/180.0) * vec.y ;
    // = (float)sin(angle/180.0) * vec.y + sin(angle/180.0) * vec.x - vec.z ;


        // put_pixel(fbr,player->pos_on_map.x +  1920/2, player->pos_on_map.y + 1080 /2 , sfWhite) ;/
        refresh_text(elements, fps, my_itoa((int) elements->fps->fps, buf));
        
        refresh_elements(elements);

    }
    
}