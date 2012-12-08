#include <stdlib.h>
#include "map_block.h"
#include "gfx.h"

/* very temporary imple */


void map_block_draw (MAP_BLOCK* blk, int x, int y)
{
    if (blk->draw_func == NULL)
    {
        gfx_tileset_draw_tile (&Gfx.tiles32, blk->tile_num, x, y);
    }
    else
    {
        blk->draw_func (blk, x, y);
    }
}


/* temporary, it has to be loaded from file, and not hardcoded */
MAP_BLOCK block_dirt =
{
    { 0, 0, 0,
      0, 0, 0,
      0, 0, 0 },

    9, 3,

    {NULL},

    NULL
};


