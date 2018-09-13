// under GNU licence

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>


template <typename ELEMENT_TYPE, size_t SIZE>
class CircularBuffer
{
public:

    CircularBuffer(): itsIndex(0U), itemCount(0U)
    {
        for(uint16_t i = 0U; i < SIZE; i++)
        {
            localItem[i] = 0U;
        }
    }

    void add(ELEMENT_TYPE item)
    {
        localItem[itsIndex] = item;

        itsIndex++;
        itsIndex %= SIZE;

        if(itemCount < SIZE)
        {
            itemCount++;
        }
    }

    ELEMENT_TYPE get(uint16_t index)
    {
        // no index checking!

        uint16_t localIndex = 0U;

        localIndex = itsIndex;

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
    }

    uint16_t count()
    {
        return itemCount;
    }


    void reset()
    {
        itemCount = 0U;
        itsIndex = 0U;
    }

private:

    ELEMENT_TYPE localItem[SIZE];
    uint16_t itsIndex; 
    uint16_t itemCount;
};

#endif
