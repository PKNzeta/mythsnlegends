#include "gfx.h"
#include "toolkit_monster_edit.h"
#include "game.h"
#include "menus.h"
#include "messages.h"
#include "map.h"

/* n  is the number of item in the menu */
#define MENU_POSITION_CENTER(n)\
    n,\
    (GFX_WIN_X_SIZE / 2) - (10 * GFX_TEXT_SIZE),\
    (GFX_WIN_Y_SIZE / 2) - (GFX_TEXT_SIZE * n)

MENU option_menu =
{
    {
        {"   Fullscreen       ", gfx_window_toggle_fullscreen},
        {"   Monster Editor   ", toolkit_monster_editor},
        {"   Save Options     ", dbg_dummy},
        {" \x11 Back             ", NULL}
    },
    MENU_POSITION_CENTER(4)
};

MENU main_menu =
{
    {
        {"   Start New Game   ", dbg_dummy},
        {"   Load Game        ", dbg_dummy},
        {"   Options        \x10 ", game_options},
        {"   Quit             ", NULL}
    },
    MENU_POSITION_CENTER(4)
};


static void menu__draw_frame (MENU* menu)
{
    int i = 0;
    int size = Gfx.tiles_ascii.size;

    gfx_text_write ("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
                    "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf",
                    menu->x - size, menu->y - size, 0);

    while (i < menu->i)
    {
        gfx_text_write ("\xb3                    \xb3",
                         menu->x - size, menu->y + (i * size), 0);
        i++;
    }

    gfx_text_write ("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
                    "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9",
                    menu->x - size, menu->y + (i * size), 0);
}


static void menu__fade_bg (MENU* menu)
{
    int size = Gfx.tiles_ascii.size;
    SDL_Rect  r = {menu->x, menu->y, (20 * size), (menu->i * size)};
    SDL_Surface* surf = SDL_CreateRGBSurface
            (SDL_HWSURFACE, (20 * size), (menu->i * size), 20, 0, 0, 0, 128);
    SDL_SetAlpha (surf, SDL_SRCALPHA, 64);
    SDL_BlitSurface (surf, NULL, Gfx.screen, &r);

    SDL_FreeSurface (surf);
}


static void menu__draw_menu (MENU* menu, int cur)
{
    int i = 0;
    int size = Gfx.tiles_ascii.size;

    menu__fade_bg (menu);

    do
    {
        if (i == cur)
        {
            gfx_text_write
                    (menu->menu[i].txt, menu->x, menu->y + (i * size), 1);
        }
        else
        {
            gfx_text_write
                    (menu->menu[i].txt, menu->x, menu->y + (i * size), 0);
        }
    } while (i++ < menu->i);
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
                choice = 0;
            Controls.kb[SDLK_DOWN] = 0;
        }

        if (Controls.kb[SDLK_UP])
        {
            if (--choice < 0)
                choice = menu->i - 1;
            Controls.kb[SDLK_UP] = 0;
        }

        if (Controls.kb[SDLK_RETURN])
        {
            if (menu->menu[choice].func != NULL)
            {
                Controls.kb[SDLK_RETURN] = 0;
                menu->menu[choice].func ();
                SDL_FillRect (Gfx.screen, NULL, 0x000000);
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
