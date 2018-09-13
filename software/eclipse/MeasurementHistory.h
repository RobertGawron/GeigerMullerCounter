// under GNU licence

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>

#include "MeasurementProcessing.h"
#include "MeasurementRegistrator.h"


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


class MeasurementHistory: public MeasurementProcessing, MeasurementRegistrator
{
public:
    MeasurementHistory();
    ~MeasurementHistory() = default;
    MeasurementHistory(const MeasurementHistory&) = delete;

    void addMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t measurementValue);

    uint16_t getMeasurement(const uint16_t index) const;
    uint16_t getMaximumMeasurement() const;
    uint16_t getMeasurementCount() const;

private:
    CircularBuffer<uint16_t, 100U> sampleBufferPerMinute;
    CircularBuffer<uint16_t, 100U> sampleBufferPerHour;
};

#endif
