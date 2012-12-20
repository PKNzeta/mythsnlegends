#ifndef H__MAP
#define H__MAP

#include "map_block.h"
#include "char.h"

#define MAX_MAP_X 100
#define MAX_MAP_Y 100

typedef struct map_struct
{
    /* the map blocks */
    MAP_BLOCK blocks[MAX_MAP_X][MAX_MAP_Y];

    /* character present in this map */
    CHARACTER mobs[128];

    SDL_Surface* bmp;
    int          bmp_need_refresh;

    /* this is for special places or buildings */
    struct map_struct* places[16];

    struct map_struct* nxt;
    struct map_struct* prv;
} MAP;

MAP* map_create_new_with_dirt (MAP* map);
void map_update_bmp (MAP* map);

void dbg_map (void);

#endif /* H__MAP */
