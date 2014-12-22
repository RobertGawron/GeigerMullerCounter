#include "layout_graph.h"

#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"
#include "tm_stm32f4_stmpe811.h"

void layout_graph_init()
{
	TM_ILI9341_Fill(ILI9341_COLOR_GRAY);

	// draw graph
	TM_ILI9341_DrawLine(0, ILI9341_WIDTH / 2, ILI9341_HEIGHT, ILI9341_WIDTH / 2,
			ILI9341_COLOR_WHITE);

	int i;
	for (i = 0; i < ILI9341_HEIGHT; i++) {
		TM_ILI9341_DrawPixel(i, i * i * 0.0005 + ILI9341_WIDTH / 2,
				ILI9341_COLOR_WHITE);
	}
}
