#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#include "defines.h"
#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"

int main(void) {
	SystemInit();
	/* Initialize ILI9341 LCD on board */
	TM_ILI9341_Init();
    TM_ILI9341_Fill(ILI9341_COLOR_ORANGE);

    TM_ILI9341_Puts(90, 310, "uFormicarium v0.1", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_ORANGE);

	while(1)
	{
		;
	}
}
