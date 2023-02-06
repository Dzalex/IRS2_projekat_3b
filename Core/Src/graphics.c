/*
 * graphics.c
 *
 *  Created on: Feb 5, 2023
 *      Author: milos
 */

#include "graphics.h"
#include "main.h"
#include "ssd1306.h"

#define WAVEFORM_X 66
#define WAVEFORM_Y 0

struct generator_params Current_Generator_parameters;

void Init_Graphics()
{
	ssd1306_Init();

	ssd1306_Fill(White);
	ssd1306_SetCursor(2,0);
	ssd1306_WriteString("Freq: ", Font_11x18, Black);
	ssd1306_SetCursor(2, 18);
	ssd1306_WriteString("9999Hz ", Font_11x18, Black);

	Draw_Sin();

	ssd1306_UpdateScreen();

	Current_Generator_parameters = g_Generator_parameters;
}

void Update_Graphics()
{
	if (Current_Generator_parameters.frequency != g_Generator_parameters.frequency)
	{
		Update_Frequency();
	}

	if (Current_Generator_parameters.waveform != g_Generator_parameters.waveform)
	{
		Update_Waveform();
	}

	ssd1306_UpdateScreen();
}

void Update_Frequency()
{

	Current_Generator_parameters.frequency = g_Generator_parameters.frequency
}

void Update_Waveform()
{

	Current_Generator_parameters.waveform = g_Generator_parameters.waveform
void Draw_Sin()
{
	ssd1306_DrawArc(82, 32, 15, 90, 270, Black);
	ssd1306_DrawArc(111, 32, 15, 270, 360+90, Black);
}
}
