// under GNU licence

#ifndef GM_COUNTER_H
#define GM_COUNTER_H

#include "CircularBuffer.h"


typedef uint8_t sample_t;


class GMCounterBase
{
public:

    virtual void addSample(sample_t value);

    virtual sample_t getSample(uint16_t index);
    
    virtual uint16_t getSampleCount();
    
    virtual sample_t getMaxSampleValue();
    
    virtual uint16_t getBinValue(uint8_t binId, uint8_t binTotal);
    
    virtual sample_t getMinSampleValue();
    
    virtual sample_t getMean(uint16_t sampleRange);
};



template <size_t ITEM_MAX>
class GMCounter: public GMCounterBase
{
public:

    GMCounter()
    {
        // empty
    }

    virtual void addSample(sample_t value)
    {
        sample.add(value);
    }

    virtual sample_t getSample(uint16_t index)
    {
        return sample.get(index);
    }

    virtual uint16_t getSampleCount()
    {
        return sample.count();
    }

    virtual sample_t getMaxSampleValue()
    {
        sample_t maxValue = 0U;

        for(uint16_t i = 0U; i < sample.count(); i++)
        {
            if (sample.get(i) > maxValue)
            {
                maxValue = sample.get(i);
            }
        }

        return maxValue;

    }

    virtual sample_t getMean(uint16_t sampleRange)
    {
        sample_t retValue = 0U;

        for(uint16_t i = 0U; i < sampleRange; i++)
        {
            retValue += sample.get(i);
        }

        retValue /= sampleRange;
        
        return retValue;
    }

    // binTotal counts from 1, not from 0 as e.g. array indexes
    virtual uint16_t getBinValue(uint8_t binId, uint8_t binTotal)
    {
        // no index checking!

        sample_t retValue = 0U;

        sample_t maximum = getMaxSampleValue();
        sample_t minimum = getMinSampleValue();
        sample_t binLength = float(maximum - minimum) / float(binTotal);

        sample_t start = minimum + (binId *  binLength);
        sample_t stop = start + binLength;

        for(uint16_t i = 0U; i < getSampleCount(); i++)
        {
            if ((getSample(i) >= start) && (getSample(i) < stop))
            {

                retValue++;
            }
        }

        return retValue;
    }

private:

    virtual sample_t getMinSampleValue()
    {
        sample_t minValue = sample.get(0);

        for(uint16_t i = 0U; i < sample.count(); i++)
        {
            if (sample.get(i) < minValue)
            {
                minValue = sample.get(i);
            }
        }

        return minValue;
    }

    CircularBuffer<sample_t, ITEM_MAX> sample;
};

#endif
