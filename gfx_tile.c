/* gfx_tile.c
 * Wrote by <F Cardascia> <PKNzeta>
 * All rights reserved to original author
 * This file is part of v0lt, a graphical noise box */

#include "gfx.h"
#include <SDL/SDL.h>

/* copy each tiles on a single line. this way, we avoid
 * computing of y axis when drawing with gfx_tiles_draw() */
static void gfx_tileset_init__cp_bitmap
    (SDL_Surface *src, SDL_Surface *dest)
{
    SDL_Rect cp_rect_tmp = { 0, 0, src->w, dest->h };
    SDL_Rect cp_rect_tiles = { 0, 0, src->w, dest->h };

    do
    {
        SDL_BlitSurface (src, &cp_rect_tmp, dest, &cp_rect_tiles);
        cp_rect_tmp.y += dest->h;
        cp_rect_tiles.x += src->w;
    }
    while (cp_rect_tmp.y != src->h);
}

Uint8 gfx_tileset_init
    (GFX_TILESET *t, const char *file, const Uint16 size)
{
    Uint8 error = 0;
    SDL_Surface *tmp_bitmap = SDL_LoadBMP (file);

    /* if we have successfully loaded tmp_bitmap
     * and allocated memory for the tileset bitmap */
    if ( (tmp_bitmap != NULL)
    &&   (t->bitmap = SDL_CreateRGBSurface
            (SDL_HWSURFACE, tmp_bitmap->w * (tmp_bitmap->h / size), size,
             32, GFX_SDL_MASKS)) != NULL )
    {
        t->size = size;
        t->count = t->bitmap->w / size;
        SDL_SetColorKey (tmp_bitmap, SDL_SRCCOLORKEY, 0xff00ff);
        gfx_tileset_init__cp_bitmap (tmp_bitmap, t->bitmap);
        SDL_FreeSurface (tmp_bitmap);
    }
    else
    {
        GFX_SDL_PRINT_ERROR;
    }

    return !error;
}


void gfx_tileset_draw_tile
    (GFX_TILESET *t, const Uint16 num, const Sint16 x, const Sint16 y)
{
    SDL_Rect rect_t = { (num * t->size), 0, t->size, t->size };
    SDL_Rect rect_s = { x, y, t->size, t->size };

    SDL_BlitSurface (t->bitmap, &rect_t, Gfx.screen, &rect_s);
}


void gfx_tileset_free
    (GFX_TILESET *t)
{
    SDL_FreeSurface (t->bitmap);

    t->bitmap = NULL;
}
