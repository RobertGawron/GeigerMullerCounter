#include "LayoutPulseCounter.h"
#include "DoseCounter.h"

#include "MeasurementRegistrator.h"

const char* LayoutPulseCounter::labelForMinuteCounter = "cpm";
const char* LayoutPulseCounter::labelForHourCounter = "cph";
const char* LayoutPulseCounter::labelDosageUnit = "uS/h";

LayoutPulseCounter::LayoutPulseCounter(DisplayDevice& display, IntervalMode_t mode) : display(display), mode(mode)
{
}

void LayoutPulseCounter::draw(MeasurementProcessing& meassurements)
{
    display.clean();
    drawLegend(meassurements);
    drawGraph(meassurements);
    display.paint();
}

void LayoutPulseCounter::drawLegend(MeasurementProcessing& meassurements)
{
    switch(mode)
    {
        case MINUTE_INTERVALS:
        {
            display.drawText(labelForMinuteCounter, 0, 0);
            DoseCounter doseCounter;
            doseCounter.calculate();
            display.drawText(labelDosageUnit, 59U, 0U);
        } break;

        case HOUR_INTERVALS:
        {
            display.drawText(labelForHourCounter, 0, 0);
        } break;

        default:
        {
            // shouldn't happen
        } break;
    }
}

void LayoutPulseCounter::drawGraph(MeasurementProcessing& meassurements)
{
    MeasurementProcessing::MeasurementDuration_t measurementDuration = MeasurementProcessing::MEASUREMENT_MINUTE;

    const uint8_t graphHeight = display.getHeight() - 10U; // TODO: magic number, because we need space for text too
    int maxValue = meassurements.getMaximumMeasurement(measurementDuration);

    for (uint16_t i = 0U; (i < meassurements.getMeasurementCount(measurementDuration)) && (i < display.getWidth()); i++)
    {
        int sampleValue = meassurements.getMeasurement(measurementDuration, i);

        // data normalization to nicely fit to screen low/high values
        sampleValue = uint8_t( (float(sampleValue) / float(maxValue)) *graphHeight);

        display.drawLine(i, 0, i, sampleValue);
    }
}
