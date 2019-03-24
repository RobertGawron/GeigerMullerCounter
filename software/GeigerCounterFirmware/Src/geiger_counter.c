/*
 * geiger_counter.c
 *
 *  Created on: 10.02.2019
 *      Author: robert
 */

#include "geiger_counter.h"
#include "circular_buffer.h"
#include "sample_storage.h"

static uint16_t SampleStorage_ElementMaxValue = UINT16_MAX;


static volatile SampleStorage_Element_t occurenceCounter;
//extern uint16_t SampleStorage_ElementMaxValue;

inline void GeigerCounter_OnTimeSampleFinish()
{
    CircularBuff_Insert(occurenceCounter);

    // reset counter to start from the beginning for the new sample
    occurenceCounter = 0;
}

void GeigerCounter_Init()
{
    occurenceCounter = 0U;
}

void GeigerCounter_OnPulseObserved()
{
    if (occurenceCounter < SampleStorage_ElementMaxValue)
    {
        occurenceCounter++;
    }
}

