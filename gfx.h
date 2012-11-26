#ifndef H_GFX
#define H_GFX

#include <SDL/SDL.h>
//#include <SDL/SDL_framerate.h>
#include "gfx_event_loop.h"

/* Get the endianess */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#   define GFX_RMASK  0xff000000
#   define GFX_GMASK  0x00ff0000
#   define GFX_BMASK  0x0000ff00
#   define GFX_AMASK  0x000000ff
#else
#   define GFX_RMASK  0x000000ff
#   define GFX_GMASK  0x0000ff00
#   define GFX_BMASK  0x00ff0000
#   define GFX_AMASK  0xff000000
#endif

/* The SDL colormasks */
#define GFX_SDL_MASKS GFX_RMASK, GFX_GMASK, GFX_BMASK, GFX_AMASK

/* A handful macro to handle error */
#define GFX_SDL_PRINT_ERROR\
    error=1;\
    fprintf(stderr,"[EE] error: %s\n", SDL_GetError ());

/* The window resolution */
#define GFX_WIN_X_SIZE   640
#define GFX_WIN_Y_SIZE   480
#define GFX_WIN_BPP      32
#define GFX_WIN_RESOLUTION \
    GFX_WIN_X_SIZE, GFX_WIN_Y_SIZE, GFX_WIN_BPP


#define GFX_FPS 60

#include "gfx_tile.h"
#include "gfx_window.h"
#include "gfx_text.h"


/* here we're defining a structure in which we store all the tilesets or
 * whatever graphics needed, this way, they all will be easily accessible. */
typedef struct
{
    /* The main display and the FPS manager of SDL_gfx */
    SDL_Surface* screen;
    //FPSmanager   fps_manager;

    /* this is used for the animations */
    int frame;

    /* a 32x32 tileset */
    GFX_TILESET tiles32;
    /* a 16x16 tileset */
    GFX_TILESET tiles16;
    /* this one is used to write text and for graphics too */
    GFX_TILESET tiles_ascii;

    /* you can also imagine storing SDL_Surface* here or make a special
     * surface to draw noise on with eventually a dedicated thread */

    /* all the display filters */
    //GFX_FILTERS filters;

} GFX_PROGRAM_GRAPHICS;

extern GFX_PROGRAM_GRAPHICS Gfx;

/* Safely load a BMP from the disk
 * @param file : the filename of the bitmap to load
 * @return a pointer to the loaded surface or NULL on failure */
SDL_Surface* gfx_load_bmp (const char* file);

/* Init all the graphics system */
Uint8 gfx_init (void);

/* free all the graphics */
void gfx_free (void);

#endif /* H_GFX */
