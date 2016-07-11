#include <string.h>
#include <stdio.h>
#include <3ds.h>

void setPixel(u8 *fb, u16 x, u16 y, u8 red, u8 green, u8 blue)
{
	fb[3 * (240 - y + (x - 1) * 240)] = blue;
	fb[3 * (240 - y + (x - 1) * 240) + 1] = green;
	fb[3 * (240 - y + (x - 1) * 240) + 2] = red;
}

void	drawRect(u8 *fb, int x1, int x2, int y1, int y2)
{
	int	save_x = x1;

	while (y1 < y2)
	{
		while (x1 < x2)
		{
			if (y1 >= 1 && y1 <= 240)
				setPixel(fb, x1, y1, 0xFF, 0xFF, 0xFF);
			x1++;
		}
		x1 = save_x;
		y1++;
	}
}

void	clear_image(u8 *fb)
{
	memset(fb, 0, 240*400*3);
}

int main(void)
{
	int i = 0;
	int x1, x2, y1, y2;

	x1 = 100;
	x2 = 200;
	y1 = 100;
	y2 = 200;
	PrintConsole topScreen;
	gfxInitDefault();
	//gfxSet3D(true); // uncomment if using stereoscopic 3D

	// Main loop
	consoleInit(GFX_TOP, &topScreen);
	consoleSelect(&topScreen);
	gfxSetDoubleBuffering(GFX_BOTTOM, false);
	while (aptMainLoop())
	{
		hidScanInput();
		// Your code goes here
		u32 kDown = hidKeysHeld(); // hidKeysHeld fonction de key repeat
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		// Example rendering code that displays a white pixel
		// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)
		u8* fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
		drawRect(fb, x1, x2, y1, y2);
		if (kDown & KEY_SELECT)
			memset(fb, 0, 240*400*3);
		if (kDown & KEY_RIGHT)
		{
			x1++;
			x2++;
		}
		if (kDown & KEY_LEFT)
		{
			x1--;
			x2--;
		}
		if (kDown & KEY_UP)
		{
			y1--;
			y2--;
		}
		if (kDown & KEY_DOWN)
		{
			y1++;
			y2++;
		}
		// Flush and swap framebuffers
		/*gfxFlushBuffers();*/
		/*gfxSwapBuffersGpu();*/
		gspWaitForEvent(GSPGPU_EVENT_VBlank0, false);
		/*gspWaitForVBlank();*/
		clear_image(fb);
	}
	gfxExit();
	return 0;
}
