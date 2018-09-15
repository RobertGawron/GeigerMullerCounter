#ifndef LAYOUT_PULSE_COUNTER_H
#define LAYOUT_PULSE_COUNTER_H

#include "Layout.h"

class LayoutPulseCounter: public Layout
{
public:
    enum IntervalMode_t { MINUTE_INTERVALS = 0, HOUR_INTERVALS = 1 };
    LayoutPulseCounter(DisplayDevice& display, IntervalMode_t mode);
    ~LayoutPulseCounter() = default;
    virtual void draw(MeasurementProcessing& meassurements);

private:
    void drawLegend(MeasurementProcessing& meassurements);
    void drawGraph(MeasurementProcessing& meassurements);

    DisplayDevice& display;
    IntervalMode_t mode;

    // TODO: make it generic for other than hour/minute intervals.
    static const char* labelForMinuteCounter;
    static const char* labelForHourCounter;
    static const char* labelDosageUnit;
};

#endif
