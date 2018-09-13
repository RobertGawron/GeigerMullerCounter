#ifndef LAYOUT_H
#define LAYOUT_H

#include "DisplayDevice.h"

class Layout
{
public:
    virtual ~Layout() = default;
    virtual void draw() = 0;
};

#endif

