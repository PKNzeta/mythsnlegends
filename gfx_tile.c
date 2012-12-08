/* gfx_tile.c */

#include "gfx.h"
#include <SDL/SDL.h>

static void gfx_tileset_init__cp_bitmap
    (GFX_TILESET *t, SDL_Surface *src)
{
    int      tsize = t->size;
    int      i = 0;
    SDL_Rect r = { 0, 0, tsize, tsize};

    for (i = 0; i < t->count; i++)
    {
        t->tile[i].bitmap = SDL_CreateRGBSurface
                                (SDL_HWSURFACE, tsize, tsize, 32, 0, 0, 0, 0);
        t->tile[i].bitmap_transparent = SDL_CreateRGBSurface
                                (SDL_HWSURFACE, tsize, tsize, 32, 0, 0, 0, 0);
        SDL_BlitSurface (src, &r, t->tile[i].bitmap, NULL);
        SDL_BlitSurface (src, &r, t->tile[i].bitmap_transparent, NULL);
        SDL_SetColorKey
            (t->tile[i].bitmap_transparent, SDL_SRCCOLORKEY,
             SDL_MapRGB(t->tile[i].bitmap_transparent->format, 255, 0, 255));
        SDL_SetColorKey
            (t->tile[i].bitmap, SDL_SRCCOLORKEY,
             SDL_MapRGB(t->tile[i].bitmap_transparent->format, 255, 0, 255));
        SDL_SetAlpha (t->tile[i].bitmap_transparent, SDL_SRCALPHA, 16);
        r.x += tsize;

        if (r.x >= src->w)
        {
            r.x = 0;
            r.y += tsize;
        }
    }
}

Uint8 gfx_tileset_init
    (GFX_TILESET *t, const char *file, const Uint16 size)
{
    Uint8 error = 0;
    SDL_Surface *tmp_bitmap = SDL_LoadBMP (file);

    if (tmp_bitmap != NULL)
    {
        t->size = size;
        t->count = (tmp_bitmap->w / size) * (tmp_bitmap->h / size);
        gfx_tileset_init__cp_bitmap (t, tmp_bitmap);
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
    SDL_Rect rect_s = { x, y, t->size, t->size };

    SDL_BlitSurface (t->tile[num].bitmap, NULL, Gfx.screen, &rect_s);
}


void gfx_tileset_free
    (GFX_TILESET *t)
{
    int i;

    for (i = 0; i < TILE_MAX; i++)
    {
        if (t->tile[i].bitmap != NULL)
        {
            SDL_FreeSurface (t->tile[i].bitmap);
            SDL_FreeSurface (t->tile[i].bitmap_transparent);
        }
        t->tile[i].bitmap = t->tile[i].bitmap_transparent = NULL;
    }
}
