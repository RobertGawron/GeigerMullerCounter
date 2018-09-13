#include "LayoutPulseCounter.h"

const char* LayoutPulseCounter::labelForMinuteCounter = "cpm";
const char* LayoutPulseCounter::labelForHourCounter = "cph";
const char* LayoutPulseCounter::labelDosageUnit = "uS/h";

LayoutPulseCounter::LayoutPulseCounter(DisplayDevice& display, IntervalMode_t mode) : display(display), mode(mode)
{
}

void LayoutPulseCounter::draw(ISampleBuffer& data)
{
    display.clean();
    drawLegend(data);
    drawGraph(data);
    display.paint();
}

void LayoutPulseCounter::drawLegend(ISampleBuffer& data)
{
    // TODO: for debug
    MeasurementHistory<int, 20> buffer;
    buffer.add(10);
    buffer.add(5);
    buffer.add(3);


}

void LayoutPulseCounter::drawGraph(ISampleBuffer& data)
{
    // TODO: for debug
    MeasurementHistory<int, 20> buffer;
    buffer.add(10);
    buffer.add(5);
    buffer.add(3);

    const uint8_t graphHeight = display.getHeight() - 10U; // TODO: magic number, because we need space for text too
    int maxValue = buffer.getMaxValue();

    for (uint16_t i = 0U; (i < buffer.count()) && (i < display.getWidth()); i++)
    {
        int sampleValue = buffer.get(i);

        // data normalization to nicely fit to screen low/high values
        sampleValue = uint8_t( (float(sampleValue) / float(maxValue)) *graphHeight);

        display.drawLine(i, 0, i, sampleValue);
    }
}
