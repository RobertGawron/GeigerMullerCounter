/*
 * display.h
 *
 *  Created on: 10.02.2019
 *      Author: robert
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "stm32f1xx_hal.h"
#include "ssd1306.h"

// this file wraps hardware related stuff of the display

void Display_Init();

void Display_Clean();

void Display_Update();

void Display_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void Display_DrawText(uint16_t x0, uint16_t y0, char* str);

#endif /* DISPLAY_H_ */
