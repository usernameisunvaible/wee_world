#include "../includes/includes.h"

chunk_ *load_chunk(unsigned int coords)
{
    chunk_ *chunk = malloc(sizeof(chunk_));

    chunk->mapping = malloc(sizeof(char) * 1024);
    chunk->cube_map = malloc(sizeof(cube_ *) * 1024);
    for (unsigned int i = coords % NB_CHUNK_MAX; i < coords % NB_CHUNK_MAX + 32; ++i) {
        for (unsigned int j = coords / NB_CHUNK_MAX; j < coords / NB_CHUNK_MAX + 32; ++j) {
            chunk->mapping[j * 32 + i] = (char) (perlin2d(i, j, 0.02, 25) * 10);
        }
    }
    chunk->coords = coords;
    return chunk;
}
