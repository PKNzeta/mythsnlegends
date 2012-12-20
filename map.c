#include <stdlib.h>
#include "map.h"
#include "gfx.h"

/* Number of blocks to draw in 640x480:
 * 640 / 32 = 20 - 1 = 19 blocks width
 * 480 / 32 = 15 - 2 = 13 blocks height */
#define N_BLK_X     ((GFX_WIN_X_SIZE / 32) - 1)
#define N_BLK_Y     ((GFX_WIN_Y_SIZE / 32) - 2)


static void
map__each_blocks
( MAP* map,
  void (*func) (MAP_BLOCK*, int, int, void*),
  void* ptr )
{
    int x, y;

    for (y = 0; y < MAX_MAP_Y; y++)
    {
        for (x = 0; x < MAX_MAP_X; x++)
        {
            func (&map->blocks[x][y], x, y, ptr);
        }
    }
}


void
map_draw (MAP* m, int x, int y)
{
    if (m->bmp_need_refresh)
    {
        SDL_FillRect (m->bmp, NULL, 0x000000);
        map__each_blocks (m, map_block_draw, (void*) m->bmp);
        m->bmp_need_refresh = 0;
    }
    SDL_Rect src = {((x-9) * 32), ((y-6) * 32), N_BLK_X * 32, N_BLK_Y * 32};
    SDL_Rect dst = {16, 32, N_BLK_X * 32, N_BLK_Y * 32};

    SDL_BlitSurface (m->bmp, &src, Gfx.screen, &dst);
}


static void
tmp_map__create_block (MAP_BLOCK* blk, int x, int y, void* nil)
{
    (void) nil;
    *blk = block_dirt;
    blk->tile = &Gfx.tiles32.tile[6];
    blk->x = x;
    blk->y = y;
}


MAP*
map_create_new_with_dirt (MAP* map)
{
    MAP* m = malloc (sizeof (MAP));

    map__each_blocks (m, tmp_map__create_block, NULL);
    m->bmp = SDL_CreateRGBSurface
              (SDL_SWSURFACE, MAX_MAP_X * 32, MAX_MAP_Y * 32, 32, 0, 0, 0, 0);
    m->bmp_need_refresh = 1;
    m->nxt = map;
    map = m;

    return m;
}


void
dbg_map (void)
{
    MAP* m = map_create_new_with_dirt (NULL);

    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE])
    {
        SDL_FillRect (Gfx.screen, NULL, 0x000000);
        map_draw (m,0,0);// rand () % 100, rand () % 100);
        gfx_tileset_draw_tile (&Gfx.tiles_ascii.tile[38], Gfx.screen,
                           (GFX_WIN_X_SIZE/2) - 4,
                           (GFX_WIN_Y_SIZE/2) - 4,
                           255);
        gfx_update_screen ();
    }
}
