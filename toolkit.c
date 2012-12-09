#include "gfx.h"
#include "menus.h"

#include "toolkit.h"

MENU toolkit_main_menu =
{
    {
        {"        Monster editor        ", toolkit_monster_editor},
        {"        Tileset editor        ", toolkit_tileset_editor},
        MENU_SEPARATOR,
        {"      \x11 Back                  ", NULL}
    },
    MENU_POSITION_CENTER(4)
};


void toolkit_draw_window
    (const char* win_name, int x, int y, int sizex, int sizey)
{
    int i;
    int xb = x;
    sizex = (sizex == 0)? GFX_WIN_X_SIZE / 16 : sizex;
    sizey = (sizey == 0)? GFX_WIN_Y_SIZE / 16 : sizey;

    gfx_tileset_draw_tile
            (&Gfx.tiles16, 110, x, y + (sizey * 16) - 16);
    gfx_tileset_draw_tile
            (&Gfx.tiles16, 111, x + (sizex * 16) - 16, y + (sizey * 16) - 16);
    gfx_tileset_draw_tile
            (&Gfx.tiles16, 114, x, y);
    gfx_tileset_draw_tile
            (&Gfx.tiles16, 115, x + (sizex * 16) - 16, y);

    for (i = 0; i < sizex - 2; i++)
    {
        gfx_tileset_draw_tile
            (&Gfx.tiles16, 113, x + (i * 16) + 16, y);
        gfx_tileset_draw_tile
            (&Gfx.tiles16, 113, x + (i * 16) + 16, y + (sizey * 16) - 16);
    }

    x = xb;

    for (i = 0; i < sizey - 2; i++)
    {
        gfx_tileset_draw_tile
            (&Gfx.tiles16, 112, x, y + (i * 16) + 16);
        gfx_tileset_draw_tile
            (&Gfx.tiles16, 112, x + (sizex * 16) - 16, y + (i * 16) + 16);
    }

    gfx_text_write (win_name, x + 20, y + 4, 1);
}

void toolkit_main (void)
{
    SDL_FillRect (Gfx.screen, NULL, 0x000000);
    menu_show (&toolkit_main_menu);
}
