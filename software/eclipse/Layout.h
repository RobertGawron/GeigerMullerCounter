#ifndef LAYOUT_H
#define LAYOUT_H
#if 0
#include "GMCounter.h"

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

typedef Adafruit_PCD8544 display_t;

typedef struct pulseCounterConfig
{
    char* pulseLabel;
    char* doseLabel;
} pulseCounterConfig_t;

typedef union layoutConfig
{
    char* legendText;
    pulseCounterConfig_t pulseConfig; 
} layoutConfig_t;


class Layout
{
public:
    Layout(display_t& display);

    virtual void draw(GMCounterBase* data, layoutConfig_t& conf) = 0;

protected:

    void drawText(char* data, uint8_t x, uint8_t y);

    void drawNumber(uint8_t data, uint8_t x, uint8_t y);

    display_t& itsDisplay;
};

#endif
#endif

