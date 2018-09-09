/*
 * GMDevice.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "GMDevice.h"

#include <Arduino.h>

// global variables for interrupt handling
static const uint8_t  ledPin = 13;
volatile uint8_t gmPinState = LOW;
volatile int pulseCounter = 0;

void interruptHandler()
{
    gmPinState = !gmPinState;

    if (gmPinState == HIGH)
    {
        pulseCounter++;
    }

    digitalWrite(ledPin, gmPinState);
}

GMDevice::GMDevice()
{
}

GMDevice::~GMDevice()
{
}

void GMDevice::init()
{
    // setup GM status diode
    pinMode(ledPin, OUTPUT);

    // setup GM input pin
    pinMode(gmInputPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(gmInputPin), interruptHandler, CHANGE);


}
