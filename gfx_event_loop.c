/* gfx_events.c
 * Wrote by <F Cardascia> <PKNzeta>
 * All rights reserved to original author
 * This file is part of v0lt, a graphical noise box */

#include "gfx_event_loop.h"
#include <SDL/SDL.h>

#include "gfx.h"

gfx_events Controls;

#define HANDLE_EVENT(evt)\
    if (event.type == evt)

void gfx_events_update
    (void)
{
    SDL_Event event;

    while (SDL_PollEvent (&event))
    {
        HANDLE_EVENT( SDL_KEYDOWN )
            Controls.kb[event.key.keysym.sym] = 1;

        HANDLE_EVENT( SDL_KEYUP )
            Controls.kb[event.key.keysym.sym] = 0;

        HANDLE_EVENT( SDL_MOUSEMOTION )
        {
            Controls.mousex = event.motion.x;
            Controls.mousey = event.motion.y;
        }

        HANDLE_EVENT( SDL_MOUSEBUTTONDOWN )
            Controls.mouse[event.button.button - 1] = 1;

        HANDLE_EVENT( SDL_MOUSEBUTTONUP )
            Controls.mouse[event.button.button - 1] = 0;

        HANDLE_EVENT( SDL_QUIT )
            Controls.quit = 1;
    }
}

void gfx_events_init
    (void)
{
    memset (&Controls, 0, sizeof (gfx_events));
}


void gfx_eventloop_textpause
    (void)
{
    Controls.kb[SDLK_p] = 0;
    gfx_text_write ("Press 'p' again to remove pause. ", 8, 8);
    SDL_Flip (Gfx.screen);

    while(!Controls.quit && !Controls.kb[SDLK_p])
    {
        gfx_events_update ();
//        SDL_framerateDelay (&Gfx.fps_manager);
    }
}

void gfx_eventloop_mainloop
    (void)
{
    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE])
    {
        if (Controls.mouse[0])
        {
            /*click*/
        }

        if (Controls.kb[SDLK_p])
        {
            gfx_eventloop_textpause ();
        }

        if (Controls.kb[SDLK_f])
        {
            gfx_window_toggle_fullscreen ();
        }

        gfx_update_screen ();
    }
}
