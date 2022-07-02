#ifndef INCLUDES_H
    #define INCLUDES_H



#if defined WIN32
    #include <time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <malloc.h>
    #include <share.h>
    #include <io.h>
    #include <mem.h>
    #include <math.h>
#else
    #include <math.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
#endif




#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include "../engine/includes/include_engine.h"

#include "map.h"
#include "chunk.h"

#include "proto.h"



    #define KEY_CODE elements->event.key.code
    #define PI 3.1415

    #define RECT_SIZE 75


    #define NB_CHUNK_MAX 31250

    #define NORD_OUEST ((infos->cos_angle * id.x - infos->cos_angle * id.y) * infos->bloc_size + infos->mid_x + infos->offset.x) , ((infos->sin_angle * id.y + infos->sin_angle * id.x - str_map[id.y * size.x + id.x]) * infos->bloc_size - infos->mid_y + infos->offset.y) 

    #define SUD_OUEST ((infos->cos_angle * id.x - infos->cos_angle * (id.y + 1)) * infos->bloc_size + infos->mid_x  + infos->offset.x) , ((infos->sin_angle * (id.y + 1) + infos->sin_angle * id.x - str_map[id.y * size.x + id.x]) * infos->bloc_size - infos->mid_y + infos->offset.y)

    #define SUD_EST ((infos->cos_angle * (id.x + 1) - infos->cos_angle * (id.y + 1)) * infos->bloc_size + infos->mid_x + infos->offset.x) , ((infos->sin_angle * (id.y + 1) + infos->sin_angle * (id.x + 1) - str_map[id.y * size.x + id.x])  * infos->bloc_size - infos->mid_y + infos->offset.y) 

    #define NORD_EST ((infos->cos_angle * (id.x + 1) - infos->cos_angle * id.y ) * infos->bloc_size + infos->mid_x + infos->offset.x) , ((infos->sin_angle * id.y  + infos->sin_angle * (id.x + 1) - str_map[id.y * size.x + id.x]) * infos->bloc_size - infos->mid_y + infos->offset.y)
#endif //INCLUDES_H