#include "LayoutWelcome.h"

LayoutWelcome::LayoutWelcome(DisplayDevice& display) : display(display)
{
}

void LayoutWelcome::draw(/*GMCounterBase* data, layoutConfig_t& conf*/)
{
    display.getDisplayHandle().clearDisplay();
    
    char* welcomeText = "initializing\n\nwait 60 sec";
    //drawText(welcomeText, 0U, 0U);
    display.getDisplayHandle().setTextSize(0);
    display.getDisplayHandle().setTextColor(BLACK);
    display.getDisplayHandle().setCursor(2, 1);
    display.getDisplayHandle().print(welcomeText);

    display.getDisplayHandle().display();
}

