/*
 * circular_buffer.c
 *
 *  Created on: 02.02.2019
 *      Author: robert
 */
#include "circular_buffer.h"

// nicely fit to the screen size
#define MAX_ELEMENTS 128

typedef struct circular_buffer_t
{
    SampleStorage_Element_t data[MAX_ELEMENTS];

    uint16_t indexOfNextToInsert;
    uint16_t elementsInBuffer;
} circular_buffer_t;

static circular_buffer_t buffer;

void CircularBuff_Init()
{
    buffer.indexOfNextToInsert = 0;
    buffer.elementsInBuffer = 0;
}

SampleStorage_Element_t CircularBuff_GetMaxElement()
{
    SampleStorage_Element_t maxValue = 0u;
    for(int i = 0; i < CircularBuff_GetElementCount(); i++)
    {
        SampleStorage_Element_t element;
        bool status = CircularBuff_GetElement(&element, i);

        if(status)
        {
            if(element > maxValue)
            {
                maxValue = element;
            }
        }
    }
    return maxValue;
}

uint16_t CircularBuff_GetElementCount()
{
    return buffer.elementsInBuffer;
}

void CircularBuff_Insert(SampleStorage_Element_t element)
{
    buffer.data[buffer.indexOfNextToInsert] = element;

    buffer.indexOfNextToInsert++;
    buffer.indexOfNextToInsert %= MAX_ELEMENTS;

    if(buffer.elementsInBuffer < MAX_ELEMENTS)
    {
        buffer.elementsInBuffer++;
    }
}

// will return false on error, e.g. index is bigger than the buffer size
bool CircularBuff_GetElement(SampleStorage_Element_t* element, uint16_t index)
{
    if(index < MAX_ELEMENTS)
    {
        int16_t localIndex = (buffer.indexOfNextToInsert - 1U) - index;
        if(localIndex < 0)
        {
            localIndex = (MAX_ELEMENTS + localIndex);
        }

        *element = buffer.data[localIndex];
        return true;
    }
    else
    {
        return false;
    }
}
