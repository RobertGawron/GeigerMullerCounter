#ifndef LAYOUT_H
#define LAYOUT_H

#include "DisplayDevice.h"
#include "MeasurementHistory.h"

class Layout
{
public:
    virtual ~Layout() = default;
    virtual void draw(MeasurementProcessing& meassurements) = 0;
};

#endif

