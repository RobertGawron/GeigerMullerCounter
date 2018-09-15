/*
 * MeasurementHistory.cpp
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#include "MeasurementHistory.h"
#include <Arduino.h>

MeasurementHistory::MeasurementHistory():
    sampleBufferPerMinute(),
    sampleBufferPerHour()
{
}

void MeasurementHistory::addMeasurement(const uint16_t measurementValue)
{
    sampleBufferPerMinute.add(measurementValue);
}

uint16_t MeasurementHistory::getMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t elementIndex) const
{
    return sampleBufferPerMinute.getElement(elementIndex);
}

uint16_t MeasurementHistory::getMaximumMeasurement(const MeasurementDuration_t measurementDuration) const
{
    return sampleBufferPerMinute.getMaximalElement();
}

uint16_t MeasurementHistory::getMeasurementCount(const MeasurementDuration_t measurementDuration) const
{
    return sampleBufferPerMinute.getElementCount();
}
