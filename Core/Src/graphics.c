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

	Current_Generator_parameters.frequency = g_Generator_parameters.frequency;
}

void Update_Waveform()
{
	Current_Generator_parameters.waveform = g_Generator_parameters.waveform;
	ssd1306_FillRectangle(67, 0, 128, 64, White);

	switch (Current_Generator_parameters.waveform)
	{
	case SIN:
		Draw_Sin();
		break;
	case TRIANGE:
		Draw_Triangle();
		break;
	case SQUARE:
		Draw_Square();
	}
}

void Draw_Sin()
{
	ssd1306_DrawArc(82, 32, 15, 90, 270, Black);
	ssd1306_DrawArc(111, 32, 15, 270, 360+90, Black);
}

void Draw_Triangle()
{
	SSD1306_VERTEX triangle_vertex[] =
	  {
	      {67,32},
	      {87,2},
	      {112,62},
	      {127,32}
	  };
	ssd1306_Polyline(triangle_vertex, sizeof(triangle_vertex)/sizeof(triangle_vertex[0]), Black);
}

void Draw_Square()
{
	SSD1306_VERTEX square_vertex[] =
		  {
		      {67,32},
		      {67,2},
		      {97,2},
		      {97,62},
			  {125,62},
			  {125,32}
		  };
		ssd1306_Polyline(square_vertex, sizeof(square_vertex)/sizeof(square_vertex[0]), Black);
}
