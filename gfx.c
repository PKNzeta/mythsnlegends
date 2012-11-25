#include "gfx.h"

GFX_PROGRAM_GRAPHICS Gfx;

static Uint8 gfx_init__load_graphics
    (void)
{
    Uint8 error =
        gfx_tileset_init (&Gfx.tiles32, "tileset32.bmp", 32) +
        gfx_tileset_init (&Gfx.tiles16, "tileset16.bmp", 16) +
        gfx_tileset_init (&Gfx.tiles_ascii, "tileset_ascii.bmp", 8);

    return (error == 3)? 1: 0;
}


Uint8 gfx_init
    (void)
{
    Uint8 error = 0;

    if (gfx_window_init ()
    &&  gfx_init__load_graphics ())
    {
        //gfx_filters_init (&Gfx.filters);
//        SDL_initFramerate (&Gfx.fps_manager);
//        SDL_setFramerate (&Gfx.fps_manager, GFX_FPS);
    }
    else
    {
        error = 1;
    }
    Gfx.frame = 0;

    return !error;
}

void gfx_free
    (void)
{
    gfx_tileset_free (&Gfx.tiles32);
    gfx_tileset_free (&Gfx.tiles16);
    gfx_tileset_free (&Gfx.tiles_ascii);

    SDL_FreeSurface (Gfx.screen);
}


SDL_Surface* gfx_load_bmp
    (const char* file)
{
    SDL_Surface* surf = SDL_LoadBMP (file);
    Uint8 error = 0;

    if (surf == NULL)
    {
        GFX_SDL_PRINT_ERROR;
        error = 1;
    }

    return (error)? NULL : surf;
}
