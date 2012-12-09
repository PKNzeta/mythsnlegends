#include <stdlib.h>

#include "gfx.h"
#include "toolkit.h"
#include "menus.h"
#include "game.h"
#include "files.h"
#include "messages.h"


static void toolkit_tileset_open_dir (void)
{
    int x = (GFX_WIN_X_SIZE / 2) - ((24 * 16) / 2);
    int y = (GFX_WIN_Y_SIZE / 2) - ((16 * 3) / 2);
    char pth[42] = " ";

    toolkit_draw_window ("Enter a Directory Name:", x, y, 24, 3);
    menu_get_string (pth, 42, x + 16, y + 16);
    messages_tell (pth);
}

MENU tileset_editor_main_menu =
{
    {
        {"        Open Directory        ", toolkit_tileset_open_dir},
        {"        Open Tileset          ", dbg_dummy},//toolkit_tileset_open},
        MENU_SEPARATOR,
        {"      \x11 Back                  ", NULL}
    },
    MENU_POSITION_CENTER(4)
};

void toolkit_tileset_editor (void)
{
    toolkit_draw_window ("Tileset Editor :", 0, 0, 0, 0);
    menu_show (&tileset_editor_main_menu);
}
