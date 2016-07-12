#ifndef LIB3DSFT_H
#define LIB3DSFT_H

#include <string.h>
#include <stdio.h>
#include <3ds.h>
#include <math.h>

void	set_pixel(u8 *fb, u16 x, u16 y, u8 red, u8 green, u8 blue);
void	draw_rect(u8 *fb, int x1, int x2, int y1, int y2);
void	draw_ellipse(u8 *fb, int x, int y);
void	clear_image(u8 *fb);

#endif
