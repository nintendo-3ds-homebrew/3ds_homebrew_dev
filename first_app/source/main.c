#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <3ds.h>

/*void drawpixel(u8* screen, u32 x,u32 y,u8 r,u8 g, u8 b) */
/*{*/
	/*u32 color = RGB8_to_565(r, g, b);*/
	/*int idx = (x * 240) + (239 - y);*/
	/*((u16*)screen)[idx] = (u16)color;*/
/*}*/

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

int main(void)
{
	int x = 30;
	int y = 30;
	int i = 0;
	PrintConsole bottomScreen;
	gfxInitDefault();
	//gfxSet3D(true); // uncomment if using stereoscopic 3D

	// Main loop
	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleSelect(&bottomScreen);

	while (aptMainLoop())
	{
		sleep(100);
			gspWaitForVBlank();
			hidScanInput();
			// Your code goes here
			u32 kDown = hidKeysDown();
			if (kDown & KEY_START)
				break; // break in order to return to hbmenu
			// Example rendering code that displays a white pixel
			// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)
			u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
			while (y < 200)
			{
				while (x < 200)
				{
					setPixel(fb, x, y, 0xFF, 0xFF, 0xFF);
					x++;
				}
				x = 30;
				y++;
			}
			if (kDown & KEY_SELECT)
				memset(fb, 0, 240*400*3);
			// Flush and swap framebuffers
			gfxFlushBuffers();
			gfxSwapBuffers();
	}
	gfxExit();
	return 0;
}
