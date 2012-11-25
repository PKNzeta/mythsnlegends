#ifndef H__MAP_BLOCK
#define H__MAP_BLOCK

#include "item.h"

typedef struct map_block
{
    int walkable[9];
    int tile;
    ITEM_INV contain;
} MAP_BLOCK;

#endif /* H__MAP_BLOCK */
