#ifndef H__MAP_BLOCK
#define H__MAP_BLOCK

#include "gfx.h"
#include "item.h"

typedef struct map_block
{
    /* coordonates of the block */
    int x; int y;

    /* the block is walkable or not */
    int walkable;

    /* the block has been revealed or not */
    int fow;

    /* the block is lighten or not */
    int light;

    /* the block graphics */
    TILE* tile;

    /* items contained in the block */
    ITEM* contain[ITEM_INV_MAX];

    /* blocks links */
    struct map_block* u;
    struct map_block* d;
    struct map_block* l;
    struct map_block* r;

    /* pathfinder token */
    int pth_token;

    /* the function used to draw the block */
    void (*draw_func) (struct map_block*, int, int, SDL_Surface*);

} MAP_BLOCK;

MAP_BLOCK block_dirt; //temp

void map_block_draw (MAP_BLOCK* blk, int x, int y, void* surf);

#endif /* H__MAP_BLOCK */
