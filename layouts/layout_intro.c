#include "layout_intro.h"

#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"
#include "tm_stm32f4_stmpe811.h"
#include "intro.h"

void layout_intro_init() {
	TM_ILI9341_Rotate(TM_ILI9341_Orientation_Landscape_2);

	TM_ILI9341_Fill(ILI9341_COLOR_WHITE);

	unsigned i;
	for (i = 0; i < intro_size; i++) {
		TM_ILI9341_DrawPixel(intro_data[i][0], intro_data[i][1],
				ILI9341_COLOR_BLACK);
	}
}
