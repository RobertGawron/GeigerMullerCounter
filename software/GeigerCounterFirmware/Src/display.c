#include "display.h"

void Display_Init()
{
    (void)SSD1306_Init();
}

void Display_Update()
{
    SSD1306_UpdateScreen();
}

void Display_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    SSD1306_DrawLine(x0, y0, x1, y1, SSD1306_COLOR_WHITE);
}

void Display_DrawText(uint16_t x0, uint16_t y0, char* str)
{
    SSD1306_GotoXY (x0, y0);
    SSD1306_Puts (str, &Font_7x10, 1);
}
