#include "gfx.h"

void gfx_text_write
    (const char* text, int x, int y)
{
    int xx = x;
    char* txt_ptr = (char*) text;

    while (*txt_ptr != '\0')
    {
        while (*txt_ptr == '\n')
        {
            x = xx; y += 8; txt_ptr++;
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
