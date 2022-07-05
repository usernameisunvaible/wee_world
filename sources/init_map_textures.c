#include "../includes/includes.h"

texture_ *init_renderstates(char *path, int type, sfColor bgcolor)
{
    texture_ *texture = malloc(sizeof(texture_));

    texture->state = malloc(sizeof(sfRenderStates));
    texture->state->texture = sfTexture_createFromFile("assets/grass.png", NULL);
    texture->state->blendMode = sfBlendNone;
    texture->state->shader = NULL;
    texture->state->transform = sfTransform_fromMatrix(1,0,1,0,1,0,0,0,1);
    texture->type = type;
    texture->bgcolor = bgcolor;
    return texture;
}

texture_ **init_mapstates(void)
{
    int nb = 1;
    texture_ **list = malloc(sizeof(texture_ *) * nb);
    list[0] = init_renderstates("assets/grass.png", 1, sfGreen);


    return list;
}

void free_renderstates(texture_ *texture)
{
    sfTexture_destroy((sfTexture *)texture->state->texture);
    free(texture->state);
    free(texture);
}

void free_mapstates(texture_ **list)
{
    int nb = 1;

    for (int i = 0; i < nb; ++i)
        free_renderstates(list[i]);
    free(list);
}