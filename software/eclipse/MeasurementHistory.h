// under GNU licence

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>

#include "MeasurementProcessing.h"
#include "MeasurementRegistrator.h"
#include "CircularBuffer.h"


class MeasurementHistory: public MeasurementProcessing, MeasurementRegistrator
{
public:
    MeasurementHistory();
    ~MeasurementHistory() = default;
    MeasurementHistory(const MeasurementHistory&) = delete;

    void addMeasurement(const uint16_t measurementValue);

    uint16_t getMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t index) const;
    uint16_t getMaximumMeasurement(const MeasurementDuration_t measurementDuration) const;
    uint16_t getMeasurementCount(const MeasurementDuration_t measurementDuration) const;

private:
    CircularBuffer<uint16_t, 4U> sampleBufferPerMinute;
    CircularBuffer<uint16_t, 4U> sampleBufferPerHour;
};

#endif
