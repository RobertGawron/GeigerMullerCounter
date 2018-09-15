/*
 * MeasurementRegistrator.h
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#ifndef MEASUREMENTREGISTRATOR_H_
#define MEASUREMENTREGISTRATOR_H_

#include <stdint.h>

class MeasurementRegistrator
{
public:
    MeasurementRegistrator() = default;
    virtual ~MeasurementRegistrator() = default;

    virtual void addMeasurement(const uint16_t measurementValue) = 0;
};

#endif /* MEASUREMENTREGISTRATOR_H_ */
