#include "gfx.h"

void gfx_text__draw_hint (int x, int y)
{
    SDL_Surface* hint = SDL_CreateRGBSurface
        (SDL_HWSURFACE, 8, 8, 32, 0, 0, 0, 128);
    SDL_Rect rect = {x, y, 8, 8};

    SDL_FillRect (hint, NULL, 0xffffff);
    SDL_SetColorKey(hint, SDL_SRCCOLORKEY, SDL_MapRGB(hint->format, 0, 0, 0));
    SDL_SetAlpha (hint, SDL_SRCALPHA, 128);

    SDL_BlitSurface (hint, NULL, Gfx.screen, &rect);
}

void gfx_text_write
    (const char* text, int x, int y, int select)
{
    int xx = x;
    char* txt_ptr = (char*) text;

    while (*txt_ptr != '\0')
    {
        while (*txt_ptr == '\n')
        {
            x = xx; y += 8; txt_ptr++;
        }

        if (select)
        {
            gfx_text__draw_hint (x, y);
        }

        if (*txt_ptr == ' ')
        {
            x += 8; txt_ptr++;
        }
        else if (*txt_ptr == '#')
        {
            gfx_tileset_draw_tile (&Gfx.tiles_ascii, rand () % 256, x, y);
            x += 8; txt_ptr++;
        }
        else
        {
            gfx_tileset_draw_tile (&Gfx.tiles_ascii, *txt_ptr-1, x, y);
            x += 8; txt_ptr++;
        }
    }
}
