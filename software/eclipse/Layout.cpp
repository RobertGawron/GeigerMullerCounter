#include "Layout.h"
#if 0
Layout::Layout(display_t& display) : itsDisplay(display)
{
    // empty
}

void Layout::drawText(char* data, uint8_t x, uint8_t y)
{
    itsDisplay.setTextSize(0);
    itsDisplay.setTextColor(BLACK);
    itsDisplay.setCursor(x, y);
    itsDisplay.print(data);
}

void Layout::drawNumber(uint8_t data, uint8_t x, uint8_t y)
{
    itsDisplay.setTextSize(0);
    itsDisplay.setTextColor(BLACK);
    itsDisplay.setCursor(x, y);
    itsDisplay.print(data);
}

#endif
