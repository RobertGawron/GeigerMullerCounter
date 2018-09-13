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

void MeasurementHistory::addMeasurement(const MeasurementDuration_t measurementDuration, const uint16_t measurementValue)
{
    sampleBufferPerMinute.add(measurementValue);
}

uint16_t MeasurementHistory::getMeasurement(const uint16_t elementIndex) const
{
    /*Serial.print(elementIndex);
    Serial.print("-");
    Serial.print(sampleBufferPerMinute.getElement(elementIndex));
    Serial.print("     ");*/
    return sampleBufferPerMinute.getElement(elementIndex);
}

uint16_t MeasurementHistory::getMaximumMeasurement() const
{
    Serial.print( sampleBufferPerMinute.getMaximalElement());
    Serial.print("-");
    return sampleBufferPerMinute.getMaximalElement();
}

uint16_t MeasurementHistory::getMeasurementCount() const
{
    //Serial.print(sampleBufferPerMinute.getElementCount());
    return sampleBufferPerMinute.getElementCount();
}
