#ifndef LAYOUT_H
#define LAYOUT_H

#include "DisplayDevice.h"
#include "SampleBuffer.h"
class Layout
{
public:
    virtual ~Layout() = default;
    virtual void draw(ISampleBuffer& data) = 0;
};

#endif

