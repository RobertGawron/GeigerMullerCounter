#ifndef LAYOUT_H
#define LAYOUT_H

#include "DisplayDevice.h"
#include "MeasurementHistory.h"

class Layout
{
public:
    virtual ~Layout() = default;
    virtual void draw(IMeasurementHistory& data) = 0;
};

#endif

