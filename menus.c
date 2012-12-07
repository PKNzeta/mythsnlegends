#include "gfx.h"
#include "toolkit_monster_edit.h"
#include "game.h"
#include "menus.h"
#include "messages.h"

#define POS_MENU_ENTRY_CENTER(n)\
    n,\
    (GFX_WIN_X_SIZE / 2) - (10 * 8),\
    (GFX_WIN_Y_SIZE / 2) - (8 * n)

MENU option_menu =
{
    {
        {"   Fullscreen       ", gfx_window_toggle_fullscreen},
        {"   Monster Editor   ", toolkit_monster_editor},
        {"   Save Options     ", dbg_dummy},
        {" \x12 Back             ", NULL}
    },
    POS_MENU_ENTRY_CENTER(4)
};

MENU main_menu =
{
    {
        {"   Start New Game   ", messages_history}, //dbg_dummy},
        {"   Load Game        ", dbg_dummy},
        {"   Options        \x11 ", game_options},
        {"   Quit             ", NULL}
    },
    POS_MENU_ENTRY_CENTER(4)
};


static void menu__draw_frame (MENU* menu)
{
    int i = 0;

    gfx_text_write ("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
                    "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf",
                    menu->x - 8, menu->y - 8, 0);

    while (i < menu->i)
    {
        gfx_text_write ("\xb3                    \xb3",
                         menu->x - 8, menu->y + (i * 8), 0);
        i++;
    }

    gfx_text_write ("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
                    "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9",
                    menu->x - 8, menu->y + (i * 8), 0);
}


static void menu__fade_bg (MENU* menu)
{
    SDL_Rect  r = {menu->x, menu->y, (20 * 8), (menu->i * 8)};
    SDL_Surface* surf = SDL_CreateRGBSurface
            (SDL_HWSURFACE, (20 * 8), (menu->i * 8), 20, 0, 0, 0, 128);
    SDL_FillRect (surf, NULL, 0x000000);
    SDL_SetAlpha (surf, SDL_SRCALPHA, 32);
    SDL_BlitSurface (surf, NULL, Gfx.screen, &r);

    SDL_FreeSurface (surf);
}


static void menu__draw_menu (MENU* menu, int cur)
{
    int       i = 0;

    menu__fade_bg (menu);

    while (i < menu->i)
    {
        if (i == cur)
        {
            gfx_text_write (menu->menu[i].txt, menu->x, menu->y + (i * 8), 1);
        }
        else
        {
            gfx_text_write (menu->menu[i].txt, menu->x, menu->y + (i * 8), 0);
        }
        i++;
    }
}

int menu_show (MENU* menu)
{
    int choice = 0;

    menu__draw_frame (menu);

    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE])
    {
        menu__draw_menu (menu, choice);
        gfx_update_screen ();

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

        if (Controls.kb[SDLK_RETURN])
        {
            if (menu->menu[choice].func != NULL)
            {
                Controls.kb[SDLK_RETURN] = 0;
                menu->menu[choice].func ();
                //SDL_FillRect (Gfx.screen, NULL, 0x000000);
                menu__draw_frame (menu);
                Controls.kb[SDLK_RETURN] = 0;
            }
            else
            {
                break;
            }
        }
    }

    return choice;
}


void game_options (void)
{
    menu_show (&option_menu);
}
