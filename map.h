#ifndef H__MAP
#define H__MAP

#include <SDL.h>

#include "map_block.h"

typedef struct map_struct
{
    MAP_BLOCK blocks[200][200];

    SDL_Surface* bitmap;

    /* Camera */
    MAP_BLOCK* cursor;
    int x_cur; int y_cur;
    int x_off; int y_off;

    struct map_struct* places[16];

    struct map_struct* nxt;
    struct map_struct* prv;
} MAP;


#endif /* H__MAP */
