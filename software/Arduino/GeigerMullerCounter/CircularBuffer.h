// under GNU licence

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>


template <typename item_t, size_t ITEM_MAX>
class CircularBuffer
{
public:

    CircularBuffer(): itsIndex(0U), itemCount(0U)
    {
        for(uint16_t i = 0U; i < ITEM_MAX; i++)
        {
            localItem[i] = 0U;
        }
    }

    void add(item_t item)
    {
        localItem[itsIndex] = item;

        itsIndex++;
        itsIndex %= ITEM_MAX;

        if(itemCount < ITEM_MAX)
        {
            itemCount++;
        }
    }

    item_t get(uint16_t index)
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
            localIndex = ITEM_MAX - index;
        }

        return localItem[localIndex];
    }

    uint16_t count()
    {
        return itemCount;
    }

#if 0
    void reset()
    {
        itemCount = 0U;
        itsIndex = 0U;
    }
#endif
private:

    item_t localItem[ITEM_MAX];
    uint16_t itsIndex; 
    uint16_t itemCount;
};

#endif
