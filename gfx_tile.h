/* gfx_tile.h */

#ifndef H_GFX_TILE
#define H_GFX_TILE

#include <SDL/SDL.h>

#define TILE_MAX 1024

typedef struct tile_struct
{
    SDL_Surface* bitmap;
} TILE;

/** A structure to store information relative to a loaded tileset file */
typedef struct
{
  /* the bitmap we use for drawing */
  TILE tile[TILE_MAX];

  /* the size in pixel of a single tile (it must be squares) */
  Uint16 size;

  /* The total number of tiles */
  Uint16 count;

} GFX_TILESET;

/** Initialize a tileset structure
 * @param t : the address of the tileset to init
 * @param file : the filename of the bitmap to use
 * @param size : the width of a single tile, a tile must be a sqaure
 * @return 1 on success 0 on failure */
Uint8 gfx_tileset_init
    (GFX_TILESET* t, const char* file, const Uint16 size);

/** Draw a tile from the given tileset at x y, upper left corner
 * @param t : the address of the tileset to use
 * @param tile_num : the tile number we want to draw
 * @param x : where to draw on the X axis
 * @param y : where to draw on the Y axis */
void gfx_tileset_draw_tile
    (TILE* t, SDL_Surface* surf, const Sint16 x, const Sint16 y, int alpha);

/** Free ressources allocated for the tileset t
 * @param t : a pointer to the tileset to free
 * @return 1 on success 0 on failure */
void gfx_tileset_free (GFX_TILESET* t);

#endif /* H_GFX_TILE */


