/* history.c */

#include "stdlib.h"
#include "string.h"
#include "gfx.h"
#include "toolkit.h"
#include "messages.h"


MESSAGE* messages = NULL;

static void messages__draw_history (const int cur)
{
    SDL_Rect r = {16, 16, GFX_WIN_X_SIZE - 32, GFX_WIN_Y_SIZE - 32};
    int i = 0;
    MESSAGE* msg = messages;

    /* clear the screen */
    SDL_FillRect (Gfx.screen, &r, 0x000000);

    /* go to the good line */
    while (i != cur && msg != NULL)
    {
        msg = msg->nxt;
        i++;
    }

    /* then draw */
    i = 0;
    while (i < 255 && msg != NULL)
    {
        gfx_text_write (msg->line, 16, (GFX_WIN_Y_SIZE - 24) - (8 * i), 0);
        msg = msg->nxt;
        i++;
    }
}

static void messages__add_line (const char* line)
{
    MESSAGE* msg = malloc (sizeof (MESSAGE));
    memset (msg, 0, sizeof (MESSAGE));

    /* push the line into messages */
    {
        strncpy (msg->line, line, 95);
        msg->nxt = messages;
        messages = msg;
    }
    /* free the 256th entry of messages */
    {
        int i = 0;

        while (msg != NULL)
        {
            if (i == 254)
            {
                free (msg->nxt);
                msg->nxt = NULL;
            }
            msg = msg->nxt;
            i++;
        }
    }
}


void messages_tell (const char* text)
{
    int i = 0;
    MESSAGE* msg = NULL;

    messages__add_line (text);
    msg = messages;

    while (i < 3 && msg != NULL)
    {
        gfx_text_write (msg->line, 0, 16 - (8 * i), 0);
        msg = msg->nxt;
        i++;
    }
}


void messages_history (void)
{
    toolkit_draw_window ("Message History :");
    int cur = 0;

    while (!Controls.quit
    &&     !Controls.kb[SDLK_ESCAPE]
    &&     !Controls.kb[SDLK_RETURN])
    {
        gfx_update_screen ();
        messages__draw_history (cur);

        if (Controls.kb[SDLK_DOWN])
        {
            if (--cur < 0)
                cur = 0;
        }

        if (Controls.kb[SDLK_UP])
        {
            if (++cur > 255)
                cur = 255;
        }
    }

    Controls.kb[SDLK_ESCAPE] = Controls.kb[SDLK_RETURN] = 0;
}
