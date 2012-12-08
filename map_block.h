#ifndef H__MAP_BLOCK
#define H__MAP_BLOCK

#include "item.h"

typedef struct map_block
{
    int walkable[9];
    int tile_num;
    int tile_variation;
    ITEM* contain[ITEM_INV_MAX];
    void (*draw_func) (struct map_block*, int, int);
} MAP_BLOCK;

MAP_BLOCK block_dirt;

#endif /* H__MAP_BLOCK */
