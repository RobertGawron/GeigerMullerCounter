#include "intro_layout.h"
#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"
#include "tm_stm32f4_stmpe811.h"

void init_intro_layout()
{
	TM_ILI9341_Fill(ILI9341_COLOR_BLACK);

	TM_ILI9341_Puts(90, 90, "uFormicarium v0.1", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(90, 100, "Temperature 30deg", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(90, 110, "Humidity 40%", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(90, 120, "Formicarium #1", &TM_Font_7x10,
			ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
}
