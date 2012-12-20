#include "gfx.h"

#define GFX_TXT_OFFSET 0

void gfx_text_write
    (const char* text, int x, int y, int select, int alpha)
{
    int xx = x;
    unsigned char* txt_ptr = (unsigned char*) text;

    while (*txt_ptr != '\0')
    {
        while (*txt_ptr == '\n')
        {
            x = xx; y += Gfx.tiles_ascii.size; txt_ptr++;
        }

        if (select)
        {
            gfx_tileset_draw_tile
                (&Gfx.tiles_ascii.tile[219], Gfx.screen, x, y, 16);
        }

        if (*txt_ptr == ' ')
        {
            x += Gfx.tiles_ascii.size; txt_ptr++;
        }
        else if (*txt_ptr == '#')
        {
            gfx_tileset_draw_tile
                (&Gfx.tiles_ascii.tile[rand () % 256],
                 Gfx.screen, x, y, rand () % 256);
            x += Gfx.tiles_ascii.size; txt_ptr++;
        }
        else
        {
            gfx_tileset_draw_tile
                (&Gfx.tiles_ascii.tile[*txt_ptr + GFX_TXT_OFFSET],
                 Gfx.screen, x, y, alpha);
            x += Gfx.tiles_ascii.size; txt_ptr++;
        }
    }
}
