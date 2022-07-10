
#include "../../includes/includes.h"

chunk_ *load_chunk(unsigned int coords, int seed)
{
    chunk_ *chunk = malloc(sizeof(chunk_));

    int x = 0;
    int y = 0;

    chunk->mapping = malloc(sizeof(char) * 1024);
    chunk->cube_map = malloc(sizeof(cube_ *) * 1024);
    chunk->coords = coords;
    for (unsigned int i = (chunk->coords % NB_CHUNK_MAX) * 32; i < (chunk->coords % NB_CHUNK_MAX) * 32 + 32; ++i) {
        for (unsigned int j = (chunk->coords / NB_CHUNK_MAX) * 32; j < (chunk->coords / NB_CHUNK_MAX) * 32 + 32; ++j) {
            chunk->mapping[y * 32 + x] = (char) (perlin2d(i, j, 0.02, 25, seed) * 10);
            ++y;
        }
        y = 0;
        ++x;
    }
    return chunk;
}

void free_chunk(chunk_ *chunk)
{
    if (chunk != NULL) {
        free(chunk->mapping);
        for (int i = 0; i < 1024; ++i)
            free_cube(chunk->cube_map[i]);
        free(chunk->cube_map);
    }
    free(chunk);
}

void load_near_chunks(unsigned int player_chunk, chunk_ **chunk_list, int seed)
{
    chunk_list[0] = load_chunk(player_chunk - NB_CHUNK_MAX - 1, seed);
    chunk_list[1] = load_chunk(player_chunk - NB_CHUNK_MAX, seed);
    chunk_list[2] = load_chunk(player_chunk - NB_CHUNK_MAX + 1, seed);
    chunk_list[3] = load_chunk(player_chunk - 1, seed);
    chunk_list[4] = load_chunk(player_chunk, seed);
    chunk_list[5] = load_chunk(player_chunk+ 1, seed);
    chunk_list[6] = load_chunk(player_chunk + NB_CHUNK_MAX - 1, seed);
    chunk_list[7] = load_chunk(player_chunk + NB_CHUNK_MAX, seed);
    chunk_list[8] = load_chunk(player_chunk + NB_CHUNK_MAX + 1, seed);
}
