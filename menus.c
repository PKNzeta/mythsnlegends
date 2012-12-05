#include "gfx.h"
#include "toolkit_monster_edit.h"
#include "game.h"
#include "menus.h"

#define N_MAIN_MENU_ENTRY 5

/* dummy */
void game_options (void)
{
    /* NULL */
}

MENU main_menu =
{
    {
        {"         Start new game         ", game_start_new},
        {"         Load saved game        ", game_load},
        {"         Options                ", game_options},
        {"         Monster editor         ", toolkit_monster_editor},
        {"         Quit                   ", NULL}
    },
    N_MAIN_MENU_ENTRY,
    (GFX_WIN_X_SIZE / 2) - (16 * 8),
    (GFX_WIN_Y_SIZE / 2) - (8 * N_MAIN_MENU_ENTRY)
};

static void menu__draw_frame (MENU* menu)
{
    SDL_Rect     r1 = {menu->x, menu->y, 32 * 8, menu->i * 8};
    SDL_Rect     r2 = {1, 1, (32 * 8) - 2, (menu->i * 8) - 2};
    SDL_Surface* surf = SDL_CreateRGBSurface
            (SDL_HWSURFACE, 32 * 8, menu->i * 8, 32, 0, 0, 0, 128);
    SDL_FillRect (surf, NULL, 0xffffff);
    SDL_FillRect (surf, &r2, 0x000000);
    SDL_BlitSurface (surf, NULL, Gfx.screen, &r1);

    SDL_FreeSurface (surf);
}

static void menu__draw_menu (MENU* menu, int cur)
{
    int       i = 0;
    SDL_Rect  r = {menu->x + 1, menu->y + 1, (32 * 8) - 2, (menu->i * 8) - 2};
    SDL_Surface* surf = SDL_CreateRGBSurface
            (SDL_HWSURFACE, (32 * 8) - 2, (menu->i * 8) - 2, 32, 0, 0, 0, 128);
    SDL_FillRect (surf, NULL, 0x000000);
    SDL_SetAlpha (surf, SDL_SRCALPHA, 32);
    SDL_BlitSurface (surf, NULL, Gfx.screen, &r);

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

    SDL_FreeSurface (surf);
}

int menu_show_menu (MENU* menu)
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
                menu->menu[choice].func ();
                SDL_FillRect (Gfx.screen, NULL, 0x000000);
                menu__draw_frame (menu);
            }
            else
            {
                break;
            }
        }
    }

    return choice;
}
