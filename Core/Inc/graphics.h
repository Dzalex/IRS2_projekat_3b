/*
 * graphics.h
 *
 *  Created on: Feb 5, 2023
 *      Author: milos
 */

#ifndef INC_GRAPHICS_H_
#define INC_GRAPHICS_H_

#include "main.h"

extern struct generator_params g_Generator_parameters;

void Init_Graphics();
void Update_Graphics();
void Update_Frequency();
void Update_Waveform();
void Draw_Sin();

#endif /* INC_GRAPHICS_H_ */
