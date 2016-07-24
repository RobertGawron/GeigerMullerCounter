#ifndef LAYOUT_PULSE_COUNTER_H
#define LAYOUT_PULSE_COUNTER_H

#include "Layout.h"

class LayoutPulseCounter: public Layout
{
public:

    LayoutPulseCounter(display_t& display);

    virtual void draw(GMCounterBase* data, layoutConfig_t& conf);
;
};

#endif

