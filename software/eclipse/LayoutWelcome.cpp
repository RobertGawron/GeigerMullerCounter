#include "LayoutWelcome.h"

const char* LayoutWelcome::welcomeText = "Collecting..\n\nWait 60s.";

LayoutWelcome::LayoutWelcome(DisplayDevice& display) : display(display)
{
}

void LayoutWelcome::draw(/*GMCounterBase* data, layoutConfig_t& conf*/)
{
    display.clean();
    display.drawText(welcomeText, textXCoordinate, textYCoordinate);
}

