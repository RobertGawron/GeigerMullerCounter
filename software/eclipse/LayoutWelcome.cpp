#include "LayoutWelcome.h"

const char* LayoutWelcome::welcomeText = "Collecting..\n\nWait 60s.";

LayoutWelcome::LayoutWelcome(DisplayDevice& display) : display(display)
{
}

void LayoutWelcome::draw(IMeasurementHistory& data)
{
    display.clean();
    display.drawText(welcomeText, textXCoordinate, textYCoordinate);
}

