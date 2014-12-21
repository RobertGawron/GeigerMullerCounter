#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#include "defines.h"
#include "tm_stm32f4_ili9341.h"
#include "tm_stm32f4_fonts.h"

int main(void) {
	SystemInit();
	/* Initialize ILI9341 LCD on board */
	TM_ILI9341_Init();
    TM_ILI9341_Fill(ILI9341_COLOR_BLACK);
    TM_ILI9341_Rotate(TM_ILI9341_Orientation_Landscape_2);

    TM_ILI9341_Puts(90, 90, "uFormicarium v0.1", &TM_Font_7x10, ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
    TM_ILI9341_Puts(90, 100, "Temperature 30deg", &TM_Font_7x10, ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
    TM_ILI9341_Puts(90, 110, "Humidity 40%", &TM_Font_7x10, ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);
    TM_ILI9341_Puts(90, 120, "Formicarium #1", &TM_Font_7x10, ILI9341_COLOR_YELLOW, ILI9341_COLOR_BLACK);


	while(1)
	{
		;
	}
}
