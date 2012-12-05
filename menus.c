#include "gfx.h"
#include "toolkit_monster_edit.h"
#include "game.h"
#include "menus.h"

MENU main_menu =
{
    {
        {"Start new game", game_start_new},
        {"Load saved game", game_load},
        {"Monster editor", toolkit_monster_editor},
        {"Quit", NULL}
    },
    4
};

static void menu__draw_menu (MENU* menu, int offset, int cur)
{
    int i = 0;

    while (i < menu->i)
    {
        if (i == cur)
        {
            gfx_text_write (
                menu->menu[i].txt,
                (GFX_WIN_X_SIZE / 2) - 128, offset + i * 8, 1);
        }
        else
        {
            gfx_text_write (
                menu->menu[i].txt,
                (GFX_WIN_X_SIZE / 2) - 128, offset + i * 8, 0);
        }
        i++;
    }
}

int menu_show_menu (MENU* menu)
{
    int offset = (GFX_WIN_Y_SIZE / 2) - (menu->i * 4);
    int choice = 0;

    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE])
    {
        SDL_FillRect (Gfx.screen, NULL, 0x000000);
        menu__draw_menu (menu, offset, choice);
        gfx_update_screen ();

        if (Controls.mouse[0])
        {
            /*click*/
        }

        if (Controls.kb[SDLK_DOWN])
        {
            if (++choice >= menu->i)
                choice--;
            Controls.kb[SDLK_DOWN] = 0;
        }

        if (Controls.kb[SDLK_UP])
        {
            if (--choice < 0)
                choice = 0;
            Controls.kb[SDLK_UP] = 0;
        }

        if (Controls.kb[SDLK_f])
        {
            gfx_window_toggle_fullscreen ();
        }

        if (Controls.kb[SDLK_RETURN])
        {
            if (menu->menu[choice].func != NULL)
            {
                menu->menu[choice].func ();
            }
            else
            {
                break;
            }
        }
    }

    return choice;
}
