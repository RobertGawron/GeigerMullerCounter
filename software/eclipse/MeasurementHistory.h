// under GNU licence

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>

#include "MeasurementProcessing.h"
#include "MeasurementRegistrator.h"


class IMeasurementHistory{
public:
    void a(){}
};

// This is circular buffer
template <typename ELEMENT_TYPE, size_t SIZE>
class MeasurementHistory : public IMeasurementHistory
{
public:

    MeasurementHistory(): newElementIndex(0U), lastElementIndex(0U), itemCount(0U)
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

    ELEMENT_TYPE get(const uint16_t index)
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

    uint16_t count()
    {
        return itemCount;
    }

    ELEMENT_TYPE getMaxValue()
    {
        ELEMENT_TYPE maxValue;

        for(uint16_t i = 0U; i < count(); i++)
        {
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


class TODO_class: public MeasurementProcessing, MeasurementRegistrator
{
public:
    TODO_class() = default;
    ~TODO_class() = default;
    TODO_class(const TODO_class&) = delete;

    void addMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t measurementValue);

    uint16_t getMeasurement(const uint16_t index) const;
    uint16_t getMaximumMeasurement() const;
    uint16_t getMeasurementCount() const;

private:
    MeasurementHistory<uint16_t, 100U> sampleBufferPerMinute;
    MeasurementHistory<uint16_t, 100U> sampleBufferPerHour;
};

#endif
