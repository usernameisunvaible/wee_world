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

#include "proto.h"


    #define KEY_CODE elements->event.key.code
    #define PI 3.1415

    #define RECT_SIZE 50



#endif //INCLUDES_H