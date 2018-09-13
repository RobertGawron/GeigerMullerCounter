#ifndef LAYOUT_PULSE_COUNTER_H
#define LAYOUT_PULSE_COUNTER_H

#include "Layout.h"

class LayoutPulseCounter: public Layout
{
public:
    LayoutPulseCounter(DisplayDevice& display);
    ~LayoutPulseCounter() = default;
    virtual void draw(ISampleBuffer& data);
private:
    DisplayDevice& display;
};

#endif
