#include "../include/lib3dsft.h"

int main(void)
{
	int i = 0;
	int x1, x2, y1, y2;

	x1 = 100;
	x2 = 200;
	y1 = 100;
	y2 = 200;
	PrintConsole	topScreen;
	gfxInitDefault();
	//gfxSet3D(true); // uncomment if using stereoscopic 3D

	// Main loop
	consoleInit(GFX_TOP, &topScreen);
	consoleSelect(&topScreen);
	gfxSetDoubleBuffering(GFX_BOTTOM, false);
	while (aptMainLoop())
	{
		int step = 15;
		int h = 100;
		int k = 100;
		int r = 50;
		int tetha = 1;
		int x = 0;
		int y = 0;
		hidScanInput();
		// Your code goes here
		u32 kDown = hidKeysHeld(); // hidKeysHeld fonction de key repeat
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		// Example rendering code that displays a white pixel
		// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)
		u8	*fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
		draw_rect(fb, x1, x2, y1, y2);
		if (kDown & KEY_SELECT)
			clear_image(fb);
		if (kDown & KEY_RIGHT)
		{
			x1+=10;
			x2+=10;
		}
		if (kDown & KEY_LEFT)
		{
			x1-=10;
			x2-=10;
		}
		if (kDown & KEY_UP)
		{
			y1-=10;
			y2-=10;
		}
		if (kDown & KEY_DOWN)
		{
			y1+=10;
			y2+=10;
			y--;
		}
		while (tetha <= 360)
		{
			x = h + r*cos(tetha);
			y = k + r*sin(tetha);
			put_pixel(fb, x, y, 0x00, 0xFF, 0x00);
			tetha++;
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
