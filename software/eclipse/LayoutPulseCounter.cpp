#include "LayoutPulseCounter.h"
#if 0
LayoutPulseCounter::LayoutPulseCounter(display_t& display) : Layout(display)
{
    // empty
}

void LayoutPulseCounter::draw(GMCounterBase* data, layoutConfig_t& conf)
{
    itsDisplay.clearDisplay();

    // show legend
    uint8_t pulseValue = data->getSample(0U);
    drawNumber(pulseValue, 0U, 0U);
    drawText(conf.pulseConfig.pulseLabel, 18U, 0U);
    

    // TODO: dirty hack, we want to show value only when
    // showing graph for pulses per minute.
    if(conf.pulseConfig.doseLabel != "")
    {
        // TODO use a wrapper for writting numbers
        float doseValue = data->getDose();
        itsDisplay.setTextSize(0);
        itsDisplay.setTextColor(BLACK);
        itsDisplay.setCursor(36, 0);
        itsDisplay.print(doseValue);

        drawText(conf.pulseConfig.doseLabel, 59U, 0U);
    }


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

#endif
