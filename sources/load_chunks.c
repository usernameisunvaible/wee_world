
#include "../includes/includes.h"

chunk_ *load_chunk(unsigned int coords)
{
    chunk_ *chunk = malloc(sizeof(chunk_));

    int x = 0;
    int y = 0;

    chunk->mapping = malloc(sizeof(char) * 1024);
    chunk->cube_map = malloc(sizeof(cube_ *) * 1024);
    chunk->coords = coords;
    for (unsigned int i = (chunk->coords % NB_CHUNK_MAX) * 32; i < (chunk->coords % NB_CHUNK_MAX) * 32 + 32; ++i) {
        for (unsigned int j = (chunk->coords / NB_CHUNK_MAX) * 32; j < (chunk->coords / NB_CHUNK_MAX) * 32 + 32; ++j) {
            chunk->mapping[y * 32 + x] = (char) (perlin2d(i, j, 0.02, 25) * 10);
            ++y;
        }
        y = 0;
        ++x;
    }
    return chunk;
}
