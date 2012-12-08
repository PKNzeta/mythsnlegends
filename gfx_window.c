#include "gfx.h"
#include "gfx_event_loop.h"

static int fs = 0;

Uint8 gfx_window_init
    (void)
{
    Uint8 error = 0;

    /* if we have successfuly initialized SDL and set up the screen */
    if ( (SDL_Init (SDL_INIT_EVERYTHING) != -1)
    &&   (Gfx.screen = SDL_SetVideoMode
            (GFX_WIN_RESOLUTION,
             SDL_HWSURFACE | SDL_DOUBLEBUF /*| SDL_FULLSCREEN */)))
    {
        /* Icon & Window name */
        SDL_WM_SetCaption (PROGRAM_NAME, NULL);
        SDL_ShowCursor (1);
    }
    else
    {
        GFX_SDL_PRINT_ERROR;
    }
    return !error;
}

static int last_frame = 0;

void gfx_update_screen
    (void)
{
    int this_frame = SDL_GetTicks ();

    if (last_frame == 0)
    {
        last_frame = SDL_GetTicks ();
    }

    gfx_events_update ();

    if (++Gfx.frame > 16)
    {
        Gfx.frame = 0;
    }

    while (this_frame - last_frame < 30)
    {
        SDL_Delay (5);
        this_frame = SDL_GetTicks ();
    }

    last_frame = this_frame;
    while (SDL_Flip (Gfx.screen) != 0);

//    SDL_framerateDelay (&Gfx.fps_manager);
}


/* these two macros tell how pixel must be handled function of his pixel format
 * GFX_RETURN_PIXEL_COLOR used by gfx_get_pixel_color()
 * GFX_SET_PIXEL_COLOR used by gfx_set_pixel_color()
 * ------------------------------------------------------------------------- */
#if GFX_WIN_BPP == 8

#   define GFX_RETURN_PIXEL_COLOR \
        return *p;
#   define GFX_SET_PIXEL_COLOR \
        *p = pixel;

#elif GFX_WIN_BPP == 16

#   define GFX_RETURN_PIXEL_COLOR \
        return *(Uint16 *) p;
#   define GFX_SET_PIXEL_COLOR \
        *(Uint16*)p = pixel;

#elif GFX_WIN_BPP == 24

#   if SDL_BYTEORDER == SDL_BIG_ENDIAN

#       define GFX_RETURN_PIXEL_COLOR \
            return p[0] << 16 | p[1] << 8 | p[2];
#       define GFX_SET_PIXEL_COLOR \
            p[0] = (pixel >> 16) & 0xff; \
            p[1] = (pixel >> 8) & 0xff; \
            p[2] = pixel & 0xff;

#   else
#       define GFX_RETURN_PIXEL_COLOR \
            return p[0] | p[1] << 8 | p[2] << 16;
#       define GFX_SET_PIXEL_COLOR \
            p[0] = pixel & 0xff; \
            p[1] = (pixel >> 8) & 0xff; \
            p[2] = (pixel >> 16) & 0xff;

#   endif /* SDL_BYTEORDER */

#else

#   define GFX_RETURN_PIXEL_COLOR \
        return *(Uint32 *) p;
#   define GFX_SET_PIXEL_COLOR \
        *(Uint32 *)p = pixel;

#endif /* GFX_WIN_BPP */
/* ------------------------------------------------------------------------- */


inline Uint8* gfx_get_pixel_ptr
    (int x, int y)
{
    Uint8* ptr;

    /* avoid out of screen coordonates */
    if ( (x >= 0 && x < GFX_WIN_X_SIZE)
    &&   (y >= 0 && y < GFX_WIN_Y_SIZE))
    {
        ptr = Gfx.screen->pixels + y * Gfx.screen->pitch + x * (GFX_WIN_BPP / 8);
    }
    else
    {
        ptr = NULL;
    }
    return ptr;
}


inline Uint32 gfx_get_pixel_color
    (Uint16 x, Uint16 y)
{
    Uint8 *p = gfx_get_pixel_ptr (x, y);

    if (p != NULL)
    {
        GFX_RETURN_PIXEL_COLOR;
    } else
        return 0;
}

inline Uint32 gfx_get_pixel_color_from_ptr
    (Uint8* p)
{
    GFX_RETURN_PIXEL_COLOR;
}

inline void gfx_set_pixel_color
    (Uint16 x, Uint16 y, Uint32 pixel)
{
    Uint8 *p = gfx_get_pixel_ptr (x, y);

    if (p != NULL)
    {
        GFX_SET_PIXEL_COLOR;
    }
}

inline void gfx_set_pixel_color_from_ptr
    (Uint8* p, Uint32 pixel)
{
    GFX_SET_PIXEL_COLOR;
}


void gfx_window_toggle_fullscreen (void)
{
    if (!SDL_WM_ToggleFullScreen (Gfx.screen))
    {
        SDL_FreeSurface (Gfx.screen);

        if (fs == 0)
        {
            Gfx.screen = SDL_SetVideoMode (GFX_WIN_RESOLUTION,
                SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
        }
        else
        {
            Gfx.screen = SDL_SetVideoMode (GFX_WIN_RESOLUTION,
                SDL_HWSURFACE | SDL_DOUBLEBUF);
        }
    }

    fs = !fs;
}
