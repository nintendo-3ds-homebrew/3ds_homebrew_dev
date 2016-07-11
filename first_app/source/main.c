#include <string.h>
#include <stdio.h>
#include <3ds.h>

void drawPixel(u32 x, u32 y, u32 color, u8 *fbAdr)
{
	int idx = (x * 240) + (239 - y);
	((u16*)fbAdr)[idx] = (u16)color;
}

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
			setPixel(fb, x1, y1, 0xFF, 0xFF, 0xFF);
			x1++;
		}
		x1 = save_x;
		y1++;
	}
}

int main(void)
{
	int i = 0;
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
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		// Example rendering code that displays a white pixel
		// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)
		u8* fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
		drawRect(fb, 100, 200, 100, 200);
		if (kDown & KEY_SELECT)
			memset(fb, 0, 240*400*3);
		if (kDown & KEY_RIGHT)
		{
			printf("ok");
		}
		// Flush and swap framebuffers
		/*gfxFlushBuffers();*/
		gfxSwapBuffersGpu();
		gspWaitForEvent(GSPGPU_EVENT_VBlank0, false);
		/*gspWaitForVBlank();*/
	}
	gfxExit();
	return 0;
}
