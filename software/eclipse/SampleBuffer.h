// under GNU licence

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>


class ISampleBuffer{
public:
    void a(){}
};

template <typename ELEMENT_TYPE, size_t SIZE>
class SampleBuffer : public ISampleBuffer
{
public:

    SampleBuffer(): newElementIndex(0U), lastElementIndex(0U), itemCount(0U)
    {
        for(uint16_t i = 0U; i < SIZE; i++)
        {
            item[i] = 0U;
        }
    }

    void add(ELEMENT_TYPE itemToAdd)
    {
        item[newElementIndex] = itemToAdd;

        newElementIndex++;
        newElementIndex %= SIZE;

        if(itemCount < SIZE)
        {
            itemCount++;
        }
    }

    ELEMENT_TYPE get(uint16_t index)
    {
        return item[index];
#if 0
        // no index checking!

        uint16_t localIndex = 0U;

        localIndex = newElementIndex;

        if(localIndex >= (index + 1U))
        {
            localIndex -= (index + 1U);
        }
        else
        {
            index -= (localIndex - 1U);
            localIndex = SIZE - index;
        }

        return localItem[localIndex];
#endif
    }

    uint16_t count()
    {
        return itemCount;
    }

    ELEMENT_TYPE getMaxValue()
    {
        ELEMENT_TYPE maxValue;

        for(uint16_t i = 0U; i < count(); i++)
        {
           // Serial.print(item[i]);
           /// Serial.print(".");
            if(item[i] > maxValue)
            {
                maxValue = item[i];
            }
        }

        return maxValue;
    }

    void reset()
    {
        itemCount = 0U;
        newElementIndex = 0U;
    }

private:

    ELEMENT_TYPE item[SIZE];

    uint16_t newElementIndex;
    uint16_t lastElementIndex;
    uint16_t itemCount;
};

#endif
