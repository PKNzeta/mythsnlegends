#include "gfx.h"
#include "menus.h"

#include "toolkit.h"

MENU toolkit_main_menu =
{
    {
        {"        Monsters Editor       ", toolkit_monster_editor},
        {"        Tiles Editor          ", toolkit_tileset_editor},
        MENU_SEPARATOR,
        {"     \x11 Back                   ", NULL}
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

    gfx_tileset_draw_tile (&Gfx.tiles16.tile[110], Gfx.screen,
                           x, y + (sizey * 16) - 16, 255);
    gfx_tileset_draw_tile (&Gfx.tiles16.tile[111],
                           Gfx.screen, x + (sizex * 16) - 16,
                           y + (sizey * 16) - 16, 255);
    gfx_tileset_draw_tile (&Gfx.tiles16.tile[114],
                           Gfx.screen, x, y, 255);
    gfx_tileset_draw_tile (&Gfx.tiles16.tile[115],
                           Gfx.screen, x + (sizex * 16) - 16, y, 255);

    for (i = 0; i < sizex - 2; i++)
    {
        gfx_tileset_draw_tile (&Gfx.tiles16.tile[113],
                               Gfx.screen, x + (i * 16) + 16, y, 255);
        gfx_tileset_draw_tile (&Gfx.tiles16.tile[113],
                               Gfx.screen, x + (i * 16) + 16,
                               y + (sizey * 16) - 16, 255);
    }

    x = xb;

    for (i = 0; i < sizey - 2; i++)
    {
        gfx_tileset_draw_tile (&Gfx.tiles16.tile[112],
                               Gfx.screen, x, y + (i * 16) + 16, 255);
        gfx_tileset_draw_tile (&Gfx.tiles16.tile[112],
                               Gfx.screen,
                               x + (sizex * 16) - 16, y + (i * 16) + 16, 255);
    }

    gfx_text_write (win_name, x + 20, y + 4, 1, 255);
}

void toolkit_main (void)
{
    SDL_FillRect (Gfx.screen, NULL, 0x000000);
    menu_show (&toolkit_main_menu);
}
