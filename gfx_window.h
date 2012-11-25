/* gfx_window.h
 * Wrote by <F Cardascia> <PKNzeta>
 * All rights reserved to original author
 * This file is part of v0lt, a graphical noise box */

#ifndef H_GFX_WINDOW
#define H_GFX_WINDOW

#include <SDL/SDL.h>

/** Initialize the window
 * @return 1 on success 0 on failure */
Uint8 gfx_window_init (void);

/** Update the screen */
void gfx_update_screen (void);

/* get a pointer to pixel at position x,y */
Uint8* gfx_get_pixel_ptr (int x, int y);

/** Get the color of pixel at coordanate x,y (or with the address)
 * @param x
 * @param y
 * @return a Uint32 of the pixel at x,y */
Uint32 gfx_get_pixel_color (Uint16 x, Uint16 y);
Uint32 gfx_get_pixel_color_from_ptr (Uint8* p);

/** Set the color of the pixel at x,y (or with the address)
 * @param x
 * @param y
 * @param pixel : The color to set for the pixel at x,y */
void gfx_set_pixel_color (Uint16 x, Uint16 y, Uint32 pixel);
void gfx_set_pixel_color_from_ptr (Uint8* p, Uint32 pixel);

void gfx_window_toggle_fullscreen (void);

#endif /* H_GFX_WINDOW */
