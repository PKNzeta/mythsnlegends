#include "gfx.h"

void toolkit_draw_window (const char* win_name)
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

    gfx_text_write (win_name, 24, 4, 1);
}
