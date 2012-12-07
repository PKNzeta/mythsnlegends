#include "gfx.h"
#include "toolkit.h"

static void toolkit__monster_editor_loop (void)
{
    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE])
    {
        if (Controls.mouse[0])
        {
            /*click*/
        }

        if (Controls.kb[SDLK_f])
        {
            gfx_window_toggle_fullscreen ();
            toolkit_draw_window ("Monster Editor");
        }

        gfx_update_screen ();
    }

    Controls.kb[SDLK_ESCAPE] = 0;
}

void toolkit_monster_editor (void)
{
    SDL_FillRect (Gfx.screen, NULL, 0x000000);
    toolkit_draw_window ("Monster Editor");
    toolkit__monster_editor_loop ();
}
