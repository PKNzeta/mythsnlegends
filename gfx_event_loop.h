#ifndef H_GFX_EVENTS
#define H_GFX_EVENTS

#include <SDL/SDL.h>

typedef struct
{
    /* boolean values that determinate which keys are pressed */
    char kb[SDLK_LAST];

    /* the x and y coordonates of the mouse */
    int mousex;
    int mousey;

    /* the mouse buttons */
    char mouse[6];

    /* the SDL_QUIT Event as occured or not */
    char quit;

} gfx_events;

/* the structure where all events are recorded */
extern gfx_events Controls;

/* Handle each events that occured in SDL
 * since the last call of this function */
void gfx_events_update (void);

/* initialize the controls
 * all to 0 for the global controls struct */
void gfx_events_init (void);

void gfx_eventloop_textpause (void);

void gfx_eventloop_mainloop (void);

#endif /* H_GFX_EVENTS */
