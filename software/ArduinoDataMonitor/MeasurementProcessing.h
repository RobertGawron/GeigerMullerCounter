/*
 * MeasurementProcessing.h
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#ifndef MEASUREMENTPROCESSING_H_
#define MEASUREMENTPROCESSING_H_

#include <stdint.h>

class MeasurementProcessing
{
public:
    enum MeasurementDuration_t { MEASUREMENT_MINUTE = 0U, MEASUREMENT_HOUR = 1U };
    MeasurementProcessing() = default;
    virtual ~MeasurementProcessing() = default;

    virtual uint16_t getMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t index) const = 0;
    virtual uint16_t getMaximumMeasurement(const MeasurementDuration_t measurementDuration) const = 0;
    virtual uint16_t getMeasurementCount(const MeasurementDuration_t measurementDuration) const = 0;
};

#endif /* MEASUREMENTPROCESSING_H_ */
