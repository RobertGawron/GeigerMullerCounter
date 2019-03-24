/*
 * display_updater.c
 *
 *  Created on: 03.02.2019
 *      Author: robert
 */

#include "display_updater.h"
#include "circular_buffer.h"
#include "dose_counter.h"
#include "display.h"

#include <stdlib.h>

static const uint16_t DisplayUpdater_LCDHeightBlue = 48u;
static const uint16_t DisplayUpdater_LCDHeightYellow = 16u;
//static const uint16_t DisplayUpdater_LCDWidth = 128u;

static const char* labelMinuteCounter = "cpm";

#if 0
static const char* labelDosageUnit = "uS/h";
#endif

static char* labeWelcomeTop = "collecting sample";
static char* labeWelcomeBottom = "please wait 60sec.";

static const char* labelError = "## error ##";


#define LABEL_DOSE_LENGTH 16U
char labelDose[LABEL_DOSE_LENGTH];

static void DisplayUpdater_PrintDoseLabel();

void DisplayUpdater_Init()
{
    Display_DrawText(0, DisplayUpdater_LCDHeightYellow, labeWelcomeTop);
    Display_DrawText(0, DisplayUpdater_LCDHeightYellow + 10U, labeWelcomeBottom);

    Display_Update();
}

void DisplayUpdater_Update()
{
    Display_Clean();

    // draw dose label
    DisplayUpdater_PrintDoseLabel();

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

void DisplayUpdater_PrintDoseLabel()
{
    SampleStorage_Element_t latestSampleValue;
    uint16_t latestSampleIndex = 0U;
    bool status = CircularBuff_GetElement(&latestSampleValue, latestSampleIndex);

    uint16_t stringOffset = 0U;

    if (status)
    {
        // TODO check string size to avoid buffer overflow

        uint16_t base = 10;
        itoa(latestSampleValue, &labelDose[stringOffset], base);

        stringOffset = strlen(labelDose);
        strcpy(&labelDose[stringOffset], labelMinuteCounter);
#if 0
        uint16_t dosage = DoseCounter_calculate();
        stringOffset = strlen(labelDose);
        itoa(dosage, &labelDose[stringOffset], base);

        stringOffset = strlen(labelDose);
        strcpy(&labelDose[stringOffset], labelDosageUnit);
#endif
    }
    else
    {
        strcpy(&labelDose[stringOffset], labelError);
    }

    Display_DrawText(0, 0, labelDose);
}
