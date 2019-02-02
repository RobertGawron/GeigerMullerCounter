/*
 * geiger_counter.c
 *
 *  Created on: 10.02.2019
 *      Author: robert
 */

#include "geiger_counter.h"
#include "circular_buffer.h"
#include "sample_storage.h"

// use for tests if no real hw is available
#define USE_RANDOM_TEST_COUNT 0

#if USE_RANDOM_TEST_COUNT
    #include <stdlib.h>
#endif

volatile static SampleStorage_Element_t occurenceCounter;
extern uint16_t SampleStorage_ElementMaxValue;

inline void GeigerCounter_OnTimeSampleFinish()
{
#if USE_RANDOM_TEST_COUNT
    occurenceCounter = (rand() % 20) + 50;
#endif

    CircularBuff_Insert(occurenceCounter);

    // reset counter to start from the beginning for the new sample
    occurenceCounter = 0;
}

void GeigerCounter_Init()
{
    occurenceCounter = 0U;

#if USE_RANDOM_TEST_COUNT
    srand(123456);
#endif
}

void GeigerCounter_OnPulseObserved()
{
    if (occurenceCounter < SampleStorage_ElementMaxValue)
    {
        occurenceCounter++;
    }
}

