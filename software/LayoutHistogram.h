#ifndef LAYOUT_HISTOGRAM_H
#define LAYOUT_HISTOGRAM_H

#include "Layout.h"

class LayoutHistogram: public Layout
{
public:

    LayoutHistogram(display_t& display);

    virtual void draw(GMCounterBase* data, layoutConfig_t& conf);

private:

    uint8_t getBinsCount(GMCounterBase* data);

    uint16_t getMaxHistogramSampleValue(GMCounterBase* data, uint8_t binsCount);

    // limited by physical vertical pixel amount, decreased to 
    // fit legend on the top of the graph
    const uint8_t graphHeight = 40U;

    // arbitrary value
    float binDivider = 1.5;

};

#endif

