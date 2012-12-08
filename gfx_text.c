#include "gfx.h"

#define GFX_TXT_OFFSET 0

void gfx_text__draw_hint (int x, int y)
{
    SDL_Surface* hint = SDL_CreateRGBSurface
        (SDL_HWSURFACE, TSIZE, TSIZE, 32, 0, 0, 0, 0);
    SDL_Rect rect = {x, y, TSIZE, TSIZE};

    SDL_FillRect (hint, NULL, 0xffffff);
    SDL_SetColorKey(hint, SDL_SRCCOLORKEY, SDL_MapRGB(hint->format, 0, 0, 0));
    SDL_SetAlpha (hint, SDL_SRCALPHA, 16);

    SDL_BlitSurface (hint, NULL, Gfx.screen, &rect);
    SDL_FreeSurface (hint);
}


void gfx_text_write
    (const char* text, int x, int y, int select)
{
    int xx = x;
    unsigned char* txt_ptr = (unsigned char*) text;

    while (*txt_ptr != '\0')
    {
        while (*txt_ptr == '\n')
        {
            x = xx; y += TSIZE; txt_ptr++;
        }

        if (select)
        {
            gfx_text__draw_hint (x, y);
        }

        if (*txt_ptr == ' ')
        {
            x += TSIZE; txt_ptr++;
        }
        else if (*txt_ptr == '#')
        {
            gfx_tileset_draw_tile (&Gfx.tiles_ascii, rand () % 256, x, y);
            x += TSIZE; txt_ptr++;
        }
        else
        {
            gfx_tileset_draw_tile
                (&Gfx.tiles_ascii, *txt_ptr + GFX_TXT_OFFSET, x, y);
            x += TSIZE; txt_ptr++;
        }
    }
}
