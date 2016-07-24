#ifndef LAYOUT_WELCOME_H
#define LAYOUT_WELCOME_H

#include "Layout.h"

class LayoutWelcome: public Layout
{
public:
    LayoutWelcome(display_t& display);

    virtual void draw(GMCounterBase* data, layoutConfig_t& conf);

};

#endif

