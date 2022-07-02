#ifndef PROTO_H
    #define PROTO_H

void key_events (elements_t *elements);
float to_rad(float deg);
float dcos(float deg);
float dsin(float deg);
double dist_points(sfVector2f pa, sfVector2f pb);
map_ *load_map(char *str_map, sfVector2i size, elements_t *elements);
void refresh_map(elements_t *elements, map_ *map, texture_ **list);
float pythagore(float a, float b);
texture_ **init_mapstates(void);
float perlin2d(float x, float y, float freq, int depth);
char *my_itoa(int n, char *s);
cube_ *load_cube(sfVector2i id, char *str_map, elements_t *elements, int type, math_inf_ *infos);
chunk_ *load_chunk(unsigned int coords);
void refresh_chunk(sfVector2f player_pos, chunk_ *chunk, elements_t *elements, texture_ **list);
void generate_chunk_arrays(map_ *map, chunk_ *chunk, elements_t *elements);
void free_cube(cube_ *cube);

#endif //PROTO_H