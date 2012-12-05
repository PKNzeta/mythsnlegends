#include "gfx.h"

static void toolkit__monster_editor_draw_window (void)
{
    int x = 16;
    int y = 16;

    gfx_tileset_draw_tile (&Gfx.tiles16, 110, 0, GFX_WIN_Y_SIZE - 16);
    gfx_tileset_draw_tile (&Gfx.tiles16, 111, GFX_WIN_X_SIZE - 16, GFX_WIN_Y_SIZE - 16);
    gfx_tileset_draw_tile (&Gfx.tiles16, 114, 0, 0);
    gfx_tileset_draw_tile (&Gfx.tiles16, 115, GFX_WIN_X_SIZE - 16, 0);

    while (x < GFX_WIN_X_SIZE - 16)
    {
        gfx_tileset_draw_tile (&Gfx.tiles16, 113, x, 0);
        gfx_tileset_draw_tile (&Gfx.tiles16, 113, x, GFX_WIN_Y_SIZE - 16);
        x += 16;
    }

    while (y < GFX_WIN_Y_SIZE - 16)
    {
        gfx_tileset_draw_tile (&Gfx.tiles16, 112, 0, y);
        gfx_tileset_draw_tile (&Gfx.tiles16, 112, GFX_WIN_X_SIZE - 16, y);
        y += 16;
    }
}

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
            toolkit__monster_editor_draw_window ();
        }

        gfx_update_screen ();
    }

    Controls.kb[SDLK_ESCAPE] = 0;
}

void toolkit_monster_editor (void)
{
    toolkit__monster_editor_draw_window ();
    toolkit__monster_editor_loop ();
}
