/*
 * KeyboardDevice.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "KeyboardDevice.h"
#include <Arduino.h>

KeyboardDevice::KeyboardDevice()
{
}

KeyboardDevice::~KeyboardDevice()
{
}

void KeyboardDevice::init()
{
    // setup button to select requested layout
    pinMode(userKeyPin, INPUT);
}
