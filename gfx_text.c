#include "gfx.h"

#define GFX_TXT_OFFSET 0

void gfx_text_write
    (const char* text, int x, int y, int select)
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
            gfx_tileset_draw_tile_transparent (&Gfx.tiles_ascii, 219, x, y);
        }

        if (*txt_ptr == ' ')
        {
            x += Gfx.tiles_ascii.size; txt_ptr++;
        }
        else if (*txt_ptr == '#')
        {
            gfx_tileset_draw_tile (&Gfx.tiles_ascii, rand () % 256, x, y);
            x += Gfx.tiles_ascii.size; txt_ptr++;
        }
        else
        {
            gfx_tileset_draw_tile
                (&Gfx.tiles_ascii, *txt_ptr + GFX_TXT_OFFSET, x, y);
            x += Gfx.tiles_ascii.size; txt_ptr++;
        }
    }
}
