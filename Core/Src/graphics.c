/*
 * graphics.c
 *
 *  Created on: Feb 5, 2023
 *      Author: milos
 */

#include "graphics.h"
#include "main.h"
#include "ssd1306.h"

void Init_Graphics()
{
	ssd1306_Init();

	ssd1306_Fill(White);
	ssd1306_SetCursor(2,0);
	ssd1306_WriteString("Freq: ", Font_11x18, Black);
	ssd1306_SetCursor(2, 18);
	ssd1306_WriteString("9999Hz ", Font_11x18, Black);


	ssd1306_UpdateScreen();
}
