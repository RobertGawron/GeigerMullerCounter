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
    bool wasKeyPressObserved = hwKeyboard.wasKeyPressObserved();

    if(wasKeyPressObserved)
    {

        // TODO: data processing: measurementHistory.addMeasurement();
        measurementHistory.addMeasurement(12);
        measurementHistory.addMeasurement(8);
        measurementHistory.addMeasurement(20);

        layoutHandler.handleKeyPress();
    }

    // while(1);// TODO: this is for debug
    delay(10);
}
