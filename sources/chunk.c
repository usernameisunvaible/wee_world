#include "../includes/includes.h"

void load_arround(unsigned int player_chunk, map_ *map)
{
    int a = 0;

    for (int i = 0; i < 9; ++i) {
        a = 0;
        for (int j = 0; j < 9; ++j) {
            if (map->chunk_list[i]->coords == player_chunk - map->infos->arround_chunks[j])
                a = 1;
        }
        if (a == 0)
            break;
    }
    if (a == 0) {
        for (int i = 0; i < 9; ++i) {
            free_chunk(map->chunk_list[i]);
            map->chunk_list[i] = NULL;
        }
        load_near_chunks(player_chunk, map->chunk_list, map->infos->seed);
    } else {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 1024; ++j) {
                free_cube(map->chunk_list[i]->cube_map[j]);
            }
        }
    }
}
