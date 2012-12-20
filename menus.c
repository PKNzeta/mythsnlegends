#include <string.h>

#include "gfx.h"
#include "toolkit.h"
#include "game.h"
#include "menus.h"
#include "messages.h"
#include "map.h"

MENU option_menu =
{
    {
        {"        Fullscreen            ", gfx_window_toggle_fullscreen},
        {"        SDK                 \x10 ", toolkit_main},
        {"        Save Options          ", dbg_dummy},
        MENU_SEPARATOR,
        {"     \x11 Back                   ", NULL}
    },
    MENU_POSITION_CENTER(5)
};

MENU main_menu =
{
    {
        {"        Start New Game        ", dbg_map},
        {"        Load Game             ", dbg_dummy},
        {"        Options             \x10 ", game_options},
        MENU_SEPARATOR,
        {"        Quit                  ", NULL}
    },
    MENU_POSITION_CENTER(5)
};


static void menu__draw_frame (MENU* menu)
{
    int i = 0;
    int size = Gfx.tiles_ascii.size;

    gfx_text_write
        ("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
         "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf",
         menu->x - size, menu->y - size, 0, 255);

    while (i < menu->i)
    {
        gfx_text_write ("\xb3                              \xb3",
                         menu->x - size, menu->y + (i * size), 0, 255);
        i++;
    }

    gfx_text_write
        ("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
         "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9",
         menu->x - size, menu->y + (i * size), 0, 255);
}


static void menu__fade_bg (MENU* menu, int alpha)
{
    int size = Gfx.tiles_ascii.size;
    SDL_Rect  r = {menu->x - 8, menu->y - 8, (32*size), ((menu->i+2) * size)};
    SDL_Surface* surf = SDL_CreateRGBSurface
            (SDL_HWSURFACE, (32 * size), ((menu->i+2) * size), 32, 0, 0, 0, 128);
    SDL_SetAlpha (surf, SDL_SRCALPHA, alpha);
    SDL_BlitSurface (surf, NULL, Gfx.screen, &r);

    SDL_FreeSurface (surf);
}


static void menu__draw_menu (MENU* menu, int cur)
{
    int i = 0;
    int size = Gfx.tiles_ascii.size;

    menu__draw_frame (menu);
    menu__fade_bg (menu,32);

    do
    {
        if (i == cur)
        {
            gfx_text_write
                    (menu->menu[i].txt, menu->x, menu->y + (i * size), 1, 255);
        }
        else
        {
            gfx_text_write
                    (menu->menu[i].txt, menu->x, menu->y + (i * size), 0, 255);
        }
    } while (i++ < menu->i);
}


void menu_get_string (char* str, int len, int x, int y)
{
    SDL_Rect r = {x, y, (len+2) * 8, 16};
    char* str_cur = str;
    int ok = 0;

    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE] && !ok)
    {
        Controls.last = 0;
        gfx_update_screen ();

        if (Controls.kb[SDLK_LSHIFT] || Controls.kb[SDLK_RSHIFT])
        {
            Controls.last -= 32;
        }

        if (isalnum (Controls.last)
        ||  ispunct (Controls.last)
        ||  Controls.last == ' ')
        {
            *(str_cur++) = Controls.last;
        }

        if (Controls.last == SDLK_BACKSPACE)
        {
            *(str_cur) = ' ';
            if (str_cur - 1 >= str)
                *(--str_cur) = ' ';
        }


        if (Controls.last == SDLK_ESCAPE || Controls.quit)
        {
            str_cur = str;
            while (str_cur < str + len) *(str_cur++) = ' ';
        }

        if (Controls.last == SDLK_RETURN)
        {
            break;
        }

        (str_cur - str > len)? str_cur-- :0;
        (str_cur < str)? str_cur++ :0;

        SDL_FillRect (Gfx.screen, &r, 0x000000);

        gfx_text_write (str, x + 4, y + 4, 0, 255);
        gfx_text_write ("\x16", x + ((str_cur - str) * 8) + 4, y + 4, 1, 64);
    }
}

int menu_show (MENU* menu)
{
    int choice = 0;

    menu__fade_bg (menu, 255);
    Controls.kb[SDLK_RETURN] = 0;

    while (!Controls.quit && !Controls.kb[SDLK_ESCAPE])
    {
        menu__draw_menu (menu, choice);
        gfx_update_screen ();

        if (Controls.kb[SDLK_DOWN])
        {
            choice++;
            choice += (menu->menu[choice].func == menu_separator);
            if (choice >= menu->i)
                choice = 0;
            Controls.kb[SDLK_DOWN] = 0;
        }

        if (Controls.kb[SDLK_UP])
        {
            choice--;
            choice -= (menu->menu[choice].func == menu_separator);
            if (choice < 0)
                choice = menu->i - 1;
            Controls.kb[SDLK_UP] = 0;
        }

        if (Controls.kb[SDLK_RETURN])
        {
            if (menu->menu[choice].func != NULL)
            {
                menu->menu[choice].func ();
                menu__fade_bg (menu, 255);
                Controls.kb[SDLK_RETURN] = 0;
            }
            else
            {
                break;
            }
        }
    }
    Controls.kb[SDLK_ESCAPE] = 0;

    return choice;
}


void menu_separator (void)
{
    /* NULL */
}

void game_options (void)
{
    menu_show (&option_menu);
}
