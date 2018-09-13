/*
 * ApplicationBuilder.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "ApplicationBuilder.h"
#include <Arduino.h>

ApplicationBuilder::ApplicationBuilder():
	hwDisplay(),
	hwGeigerMuller(),
	hwKeyboard(),
	measurementHistory(),
	layoutHandler(hwDisplay, measurementHistory)
{
}

void ApplicationBuilder::init()
{
    Serial.begin(SerialBaudRateDefault);

    hwDisplay.init();
    hwGeigerMuller.init();
    hwKeyboard.init();
}

void ApplicationBuilder::run()
{
    // TODO: data processing: measurementHistory.addMeasurement();

    bool wasKeyPressObserved = hwKeyboard.wasKeyPressObserved();

    if(wasKeyPressObserved)
    {
        layoutHandler.handleKeyPress();
    }

   // while(1);// TODO: this is for debug
    delay(10);
}
