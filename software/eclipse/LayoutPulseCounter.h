#ifndef LAYOUT_PULSE_COUNTER_H
#define LAYOUT_PULSE_COUNTER_H

#include "Layout.h"

class LayoutPulseCounter: public Layout
{
public:
    LayoutPulseCounter(DisplayDevice& display);
    ~LayoutPulseCounter() = default;
    virtual void draw(/*GMCounterBase* data, layoutConfig_t& conf*/);
private:
    DisplayDevice& display;
};

#endif
