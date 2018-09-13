#include "LayoutWelcome.h"
#if 0
LayoutWelcome::LayoutWelcome(display_t& display) : Layout(display)
{
    // empty
}


void LayoutWelcome::draw(GMCounterBase* data, layoutConfig_t& conf)
{
    itsDisplay.clearDisplay();
    
    char* welcomeText = "initializing\n\nwait 60 sec";
    drawText(welcomeText, 0U, 0U);

    itsDisplay.display();
}
#endif
