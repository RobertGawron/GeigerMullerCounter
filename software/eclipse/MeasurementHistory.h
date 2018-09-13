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

    void addMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t measurementValue);

    uint16_t getMeasurement(const uint16_t index) const;
    uint16_t getMaximumMeasurement() const;
    uint16_t getMeasurementCount() const;

private:
    CircularBuffer<uint16_t, 100U> sampleBufferPerMinute;
    CircularBuffer<uint16_t, 100U> sampleBufferPerHour;
};

#endif
