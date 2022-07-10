#ifndef PROTO_H
    #define PROTO_H

void key_events(elements_t *elements, player_ *player);
float to_rad(float deg);
float dcos(float deg);
float dsin(float deg);
double dist_points(sfVector2f pa, sfVector2f pb);
map_ *load_map(elements_t *elements, int seed);
void refresh_map(elements_t *elements, map_ *map, texture_ **list);
float pythagore(float a, float b);
texture_ **init_mapstates(void);
float perlin2d(float x, float y, float freq, int depth, int seed);
char *my_itoa(int n, char *s);
cube_ *load_cube(sfVector2i id, char *str_map, elements_t *elements, int type, math_inf_ *infos, sfVector2i real_id, sfBool player);
chunk_ *load_chunk(unsigned int coords, int seed);
void refresh_chunk(chunk_ *chunk, elements_t *elements, texture_ **list, map_ *map);
void generate_chunk_arrays(sfVector3f player_pos, map_ *map, chunk_ *chunk, elements_t *elements);
void free_cube(cube_ *cube);
player_ *init_player(map_ *s_map, sfVector2i player_spawn, elements_t *elements);
sfVector2f get_pos_on_map(sfVector3f pos_on_map, map_ *s_map);
void appli_move(player_ *player, map_ *s_map, elements_t *elements);
void move_player(player_ *player, elements_t *elements, map_ *s_map);
unsigned int player_chunk(sfVector3f pos_on_map, map_ *s_map);
void load_near_chunks(unsigned int player_chunk, chunk_ **chunk_list, int seed);
void load_arround(unsigned int player_chunk, map_ *map);
void free_chunk(chunk_ *chunk);
void jump(player_ *player, elements_t *elements, map_ *s_map, chunk_ *chunk);
void free_map(map_ *map);
void free_mapstates(texture_ **list);
void free_player(player_ *player);
void player_collisions(player_ *player, elements_t *elements, map_ *s_map);

void refresh_left_leg(brick_ *left_leg, map_ *map, character_ *character, elements_t *elements);
character_ *init_charactere(elements_t *elements, map_ *map);
// void del_me_show_leg(elements_t *elements, sfVertexArray *leg);
void display_brick(elements_t *elements, brick_ *brick);
sfVector2f iso(sfVector3f p, map_ *map, sfVector2f offset);
void refresh_right_leg(brick_ *left_leg, map_ *map, character_ *character, elements_t *elements);
void refresh_body(brick_ *body, map_ *map, character_ *character, elements_t *elements);
void refresh_annims(character_ *character, elements_t *elements, map_ *map, sfBool idle);
void refresh_left_arm(brick_ *left_leg, map_ *map, character_ *character, elements_t *elements);
void refresh_right_arm(brick_ *right_arm, map_ *map, character_ *character, elements_t *elements);
void refresh_head(brick_ *head, map_ *map, character_ *character, elements_t *elements);



#endif //PROTO_H