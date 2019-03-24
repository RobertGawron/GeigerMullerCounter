/*
 * display_updater.c
 *
 *  Created on: 03.02.2019
 *      Author: robert
 */

#include "display_updater.h"
#include "circular_buffer.h"
#include "display.h"

static const uint16_t DisplayUpdater_LCDHeightBlue = 48u;
static const uint16_t DisplayUpdater_LCDHeightYellow = 16u;
//static const uint16_t DisplayUpdater_LCDWidth = 128u;

const char* labelMinuteCounter = "cpm";
const char* labelHourCounter = "cph";
const char* labelDosageUnit = "uS/h";

void DisplayUpdater_Init()
{
    // empty
}

void DisplayUpdater_Update()
{
    SSD1306_Fill(0);

    Display_DrawText(0, 0, "33cpm 1uS/h");

#if DEBUG_SAMPLES
    CircularBuff_Insert(50U);
    CircularBuff_Insert(100U);
#endif

    // draw bar graph
    SampleStorage_Element_t maxValue = CircularBuff_GetMaxElement();


    for(uint16_t i = 0; i < CircularBuff_GetElementCount(); i++)
    {
        SampleStorage_Element_t sampleValue;
        uint16_t indexInBuffer = (uint16_t)(CircularBuff_GetElementCount() - (i + 1U));
        bool status = CircularBuff_GetElement(&sampleValue, indexInBuffer);

        if(status)
        {
            const uint16_t DisplayUpdater_LCDHeight = (DisplayUpdater_LCDHeightBlue + DisplayUpdater_LCDHeightYellow);

            uint16_t y0 = DisplayUpdater_LCDHeight;

            uint16_t graphHeight = DisplayUpdater_LCDHeightBlue;
            uint16_t  normalizedSampleValue = (uint16_t)( ((float)(sampleValue) / (float)(maxValue)) * graphHeight);
            uint16_t y1 = (uint16_t)(DisplayUpdater_LCDHeight - normalizedSampleValue);

            Display_DrawLine(i, y0, i, y1);
        }
    }

    Display_Update();
}
