#include "LayoutPulseCounter.h"

LayoutPulseCounter::LayoutPulseCounter(display_t& display) : Layout(display)
{
    // empty
}

void LayoutPulseCounter::draw(GMCounterBase* data, layoutConfig_t& conf)
{
    itsDisplay.clearDisplay();

    // show legend
    uint8_t currentValue = data->getSample(0U);
    drawNumber(currentValue, 0U, 0U);
    //drawText(conf.legendText, 20U, 0U);
    drawText(conf.legendText, 20U, 0U);
//Serial.println(conf.legendText);

    // show graph
    const uint8_t graphHeight = 40U;
    sample_t maxValue = data->getMaxSampleValue();

    for (uint16_t i = 0U; (i < data->getSampleCount()) && (i < LCDWIDTH); i++)
    {
        sample_t sampleValue = data->getSample(i);
        
        // data normalization
        sampleValue = uint8_t( (float(sampleValue) / float(maxValue)) *graphHeight);        

        const uint16_t x = LCDWIDTH - i - 1U;
        itsDisplay.drawLine(x, itsDisplay.height(), x, itsDisplay.height() - sampleValue, BLACK);
    }

    itsDisplay.display();
}

