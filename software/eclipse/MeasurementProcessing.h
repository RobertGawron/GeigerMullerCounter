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
    MeasurementProcessing() = default;
    virtual ~MeasurementProcessing() = default;

    virtual uint16_t getSample(const uint16_t index) const = 0;
    virtual uint16_t getMaximumValue() const = 0;
    virtual uint16_t count() const = 0;
};

#endif /* MEASUREMENTPROCESSING_H_ */
