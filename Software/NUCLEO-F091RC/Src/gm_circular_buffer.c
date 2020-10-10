#include "gm_circular_buffer.h"

// nicely fit to the screen size
// TODO this shouldn't be here
#define MAX_ELEMENTS 128

typedef struct gm_circular_buffer_t
{
    GMMeasurement_Value_t data[MAX_ELEMENTS];

    uint16_t indexOfNextToInsert;
    uint16_t elementsInBuffer;
} gm_circular_buffer_t;

static gm_circular_buffer_t buffer;

void GMCircularBuffer_Init()
{
    buffer.indexOfNextToInsert = 0;
    buffer.elementsInBuffer = 0;
}

GMMeasurement_Value_t GMCircularBuffer_GetMaxElement()
{
    GMMeasurement_Value_t maxValue = 0u;
    for(uint16_t i = 0; i < GMCircularBuffer_GetElementCount(); i++)
    {
        GMMeasurement_Value_t element;
        bool status = GMCircularBuffer_GetElement(&element, i);

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

uint16_t GMCircularBuffer_GetElementCount()
{
    return buffer.elementsInBuffer;
}

void GMCircularBuffer_Insert(GMMeasurement_Value_t element)
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
bool GMCircularBuffer_GetElement(GMMeasurement_Value_t* element, uint16_t index)
{
    if(index < MAX_ELEMENTS)
    {
        int16_t localIndex = (int16_t)( (int16_t)(buffer.indexOfNextToInsert - 1) - (int16_t)index );
        if(localIndex < 0)
        {
            localIndex = (int16_t)(MAX_ELEMENTS + localIndex);
        }

        *element = buffer.data[localIndex];
        return true;
    }
    else
    {
        return false;
    }
}
