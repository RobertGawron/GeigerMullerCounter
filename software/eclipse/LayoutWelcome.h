#ifndef LAYOUT_WELCOME_H
#define LAYOUT_WELCOME_H

#include "Layout.h"

class LayoutWelcome: public Layout
{
public:
    LayoutWelcome(DisplayDevice& display);
    ~LayoutWelcome() = default;
    virtual void draw(/*GMCounterBase* data, layoutConfig_t& conf*/);
private:
    DisplayDevice& display;

    static const char* welcomeText;
    static const uint8_t textXCoordinate = 0U;
    static const uint8_t textYCoordinate = 0U;
};

#endif
