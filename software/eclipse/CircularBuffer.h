/*
 * CircularBuffer.h
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stddef.h>
#include <stdint.h>

template <typename ELEMENT_TYPE, size_t SIZE>
class CircularBuffer
{
public:

    CircularBuffer(): newElementIndex(0U), lastElementIndex(0U), itemCount(0U)
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

    ELEMENT_TYPE getElement(const uint16_t index) const
    {
        //int16_t localIndex =

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

    uint16_t getElementCount() const
    {
        return itemCount;
    }

    ELEMENT_TYPE getMaximalElement() const
    {
        ELEMENT_TYPE maxValue;

        for(uint16_t i = 0U; i < getElementCount(); i++)
        {
            if(item[i] > maxValue)
            {
                maxValue = item[i];
            }
        }

        return maxValue;
    }

private:

    ELEMENT_TYPE item[SIZE];

    uint16_t newElementIndex;
    uint16_t lastElementIndex;
    uint16_t itemCount;
};




#endif /* CIRCULARBUFFER_H_ */
