#include <stdlib.h>
#include "map_block.h"
#include "gfx.h"


void map_block_draw (MAP_BLOCK* blk, int x, int y, void* surf)
{
    SDL_Rect r = {x * 32, y * 32, 32, 32};
    SDL_BlitSurface (blk->tile->bitmap, NULL, (SDL_Surface*) surf, &r);
}


/* temporary, normaly, it has to be loaded from file, and not hardcoded */
MAP_BLOCK block_dirt =
{
    0, 0,

    0,

    NULL,

    {NULL},

    NULL
};


