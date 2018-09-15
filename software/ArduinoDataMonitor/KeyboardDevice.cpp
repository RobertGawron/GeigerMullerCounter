/*
 * KeyboardDevice.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "KeyboardDevice.h"
#include <Arduino.h>
#include <stdint.h>

KeyboardDevice::KeyboardDevice():
    keyWasPressedInPreviousTick(false)
{
}

void KeyboardDevice::init()
{
    // only one button is supported
    pinMode(userKeyPin, INPUT);
}

bool KeyboardDevice::wasKeyPressObserved()
{
    uint8_t hwKeyState = digitalRead(userKeyPin); //HW low means key is pressed

    bool logicalKeyState = (hwKeyState == 0) ? true : false;
    bool keyEvent = ( logicalKeyState & (!keyWasPressedInPreviousTick) );
    keyWasPressedInPreviousTick = logicalKeyState;

    return keyEvent;
}
