#include "LayoutWelcome.h"

LayoutWelcome::LayoutWelcome(display_t& display) : Layout(display)
{
    // empty
}


void LayoutWelcome::draw(GMCounterBase* data, layoutConfig_t& conf)
{
    itsDisplay.clearDisplay();
    
    char* welcomeText = "initializing";
    drawText(welcomeText, 0U, 0U);

    itsDisplay.display();
}

