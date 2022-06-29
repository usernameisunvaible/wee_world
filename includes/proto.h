#ifndef PROTO_H
    #define PROTO_H

void key_events (elements_t *elements);
float to_rad(float deg);
float dcos(float deg);
float dsin(float deg);
double dist_points(sfVector2f pa, sfVector2f pb);
map_ *load_map(char *str_map, sfVector2i size, elements_t *elements);
void refresh_map(elements_t *elements, map_ *map);
float pythagore(float a, float b);

#endif //PROTO_H