#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#include "defines.h"
#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"
#include "tm_stm32f4_stmpe811.h"

int main(void) {
	TM_STMPE811_TouchData touchData;

	SystemInit();
	/* Initialize ILI9341 LCD on board */
	TM_ILI9341_Init();
	TM_ILI9341_Fill(ILI9341_COLOR_BLACK);
	TM_ILI9341_Rotate(TM_ILI9341_Orientation_Landscape_2);

	TM_ILI9341_Puts(90, 90, "uFormicarium v0.1", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(90, 100, "Temperature 30deg", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(90, 110, "Humidity 40%", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(90, 120, "Formicarium #1", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);

	//Initialize Touch Sensor
	if (TM_STMPE811_Init() != TM_STMPE811_State_Ok) {
		TM_ILI9341_Puts(20, 20, "STMPE811 Error", &TM_Font_11x18,
				ILI9341_COLOR_ORANGE, ILI9341_COLOR_BLACK);

		while (1)
			;
	}
	//Select touch screen orientation
	touchData.orientation = TM_STMPE811_Orientation_Portrait_2;

	// draw graph
	TM_ILI9341_DrawLine(0, ILI9341_WIDTH / 2, ILI9341_HEIGHT, ILI9341_WIDTH / 2,
			ILI9341_COLOR_WHITE);

	int i;
	for (i = 0; i < ILI9341_HEIGHT; i++) {
		TM_ILI9341_DrawPixel(i, i * i * 0.0005 + ILI9341_WIDTH / 2,
				ILI9341_COLOR_WHITE);
	}

	while (1) {
		if (TM_STMPE811_ReadTouch(&touchData) == TM_STMPE811_State_Pressed) {
			init_graph_layout();
		}
		/*
		if (TM_STMPE811_ReadTouch(&touchData) == TM_STMPE811_State_Pressed) {
			//Touch valid
			//touchData.x,touchData.y
			TM_ILI9341_Puts(20, 80, "pressed", &TM_Font_11x18,
					ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);

			TM_ILI9341_DrawPixel(touchData.x, touchData.y, 0x0000);
		} else {
			TM_ILI9341_Puts(20, 80, "Not Pressed", &TM_Font_11x18,
					ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);
		}
		*/
	}
}
