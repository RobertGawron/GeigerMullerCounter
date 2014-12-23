#include "layout_intro.h"

#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"
#include "tm_stm32f4_stmpe811.h"
#include "intro.h"

//extern unsigned intro_size;
//extern unsigned intro_data[][2];
void layout_intro_init() {
	TM_ILI9341_Rotate(TM_ILI9341_Orientation_Landscape_2);

	TM_ILI9341_Fill(ILI9341_COLOR_WHITE);
	/*
	 TM_ILI9341_Puts(90, 90, "uFormicarium v0.1", &TM_Font_7x10,
	 ILI9341_COLOR_BLUE, ILI9341_COLOR_GRAY);
	 TM_ILI9341_Puts(90, 100, "Temperature 30deg", &TM_Font_7x10,
	 ILI9341_COLOR_BLUE, ILI9341_COLOR_GRAY);
	 TM_ILI9341_Puts(90, 110, "Humidity 40%", &TM_Font_7x10,
	 ILI9341_COLOR_BLUE, ILI9341_COLOR_GRAY);
	 */
	//TM_ILI9341_Puts(90, 120, "Formicarium #1", &TM_Font_7x10,
	//		ILI9341_COLOR_BLUE, ILI9341_COLOR_GRAY);

	int i;
	for (i=0; i<intro_size; i++)
	{
		TM_ILI9341_DrawPixel(intro_data[i][0], intro_data[i][1],
						ILI9341_COLOR_BLACK);
	}
}
