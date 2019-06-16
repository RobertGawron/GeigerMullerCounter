#include "LayoutHistogram.h"

#include <stddef.h>
#include <stdint.h>

LayoutHistogram::LayoutHistogram(display_t& display) : Layout(display)
{
    // empty
}

void LayoutHistogram::draw(GMCounterBase* data, layoutConfig_t& conf)
{
    // no null-pinter check for data
    itsDisplay.clearDisplay();

    // show legend
    drawText(conf.legendText, 0U, 0U);

    uint8_t binsCount = getBinsCount(data);
    uint16_t maxValue = getMaxHistogramSampleValue(data, binsCount);

   const uint16_t binWidth = itsDisplay.width() / binsCount;

    // avoid problem with number rounding by using substitution and addition
    uint8_t x0 = 0;
    uint8_t x1 = binWidth;

    for (uint16_t i = 0U; (i < binsCount) && (i < itsDisplay.width()); i++)
    {
        uint16_t binValue = data->getBinValue(i, binsCount);

        // data normalization
        binValue = uint8_t( (float(binValue) / float(maxValue)) *float(graphHeight));        

        const uint8_t y0 = itsDisplay.height() - binValue;
        const uint8_t y1 = itsDisplay.height();

        for(int j = x0; j<x1; j++)
        {
            itsDisplay.drawLine(j, y0, j, y1, BLACK);

        }

        x0+= binWidth;
        x1+= binWidth;
    }

    itsDisplay.display();
}


uint8_t LayoutHistogram::getBinsCount(GMCounterBase* data)
{
    uint8_t binsCount = 0U;

    sample_t maximum = data->getMaxSampleValue();
    sample_t minimum = data->getMinSampleValue();
    
    binsCount = sample_t( float(maximum - minimum ) / binDivider);
    binsCount = (binsCount < data->getSampleCount() ) ? binsCount : (data->getSampleCount() / binDivider);
    binsCount = (binsCount < LCDWIDTH ) ? binsCount : (LCDWIDTH - 1U); 


  //Serial.println(binsCount);


    return binsCount;
}

uint16_t LayoutHistogram::getMaxHistogramSampleValue(GMCounterBase* data, uint8_t binsCount)
{
    uint16_t maxValue = 0;

    for (uint16_t i = 0U; (i < binsCount) && (i < LCDWIDTH); i++)
    {
        if (data->getBinValue(i, binsCount) > maxValue)
        {
            maxValue = data->getBinValue(i, binsCount); 
        }
    }

    return maxValue;
}

