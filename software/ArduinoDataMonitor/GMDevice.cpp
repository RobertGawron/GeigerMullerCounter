/*
 * GMDevice.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "GMDevice.h"
#include <Arduino.h>

// global variable for interrupt handling
volatile uint8_t pulseCounter = 0;

void interruptHandlerGM()
{
    pulseCounter++;
}

uint16_t GMDevice::getCounterValue()
{
    return pulseCounter;
}

void GMDevice::resetCounterValue()
{
    pulseCounter = 0U;
}

void GMDevice::init()
{
    // setup GM input pin
    pinMode(gmInputPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(gmInputPin), interruptHandlerGM, RISING);
}
