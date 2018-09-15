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
    uint16_t currentMillis = 0U;
    uint16_t previousKeyHandlingMillis = 0U;
    uint16_t previousGMDataHandlingMillis = 0U;
    bool wasKeyPressObserved = false;

    while(true)
    {
        currentMillis = millis();

        // Step 1: handle data from GM counter
        if (currentMillis - previousGMDataHandlingMillis >= intervalLoopGMDataHandling)
        {
            previousGMDataHandlingMillis = currentMillis;

            uint16_t pulseCounterValue = hwGeigerMuller.getCounterValue();
            //Serial.println(pulseCounterValue);
            hwGeigerMuller.resetCounterValue();
            measurementHistory.addMeasurement(pulseCounterValue);
        }

        // Step 2: handle key press
        if (currentMillis - previousKeyHandlingMillis >= intervalLoopKeyHandling)
        {
            previousKeyHandlingMillis = currentMillis;

            wasKeyPressObserved = hwKeyboard.wasKeyPressObserved();

            if(wasKeyPressObserved)
            {
                layoutHandler.handleKeyPress();
            }
        }
    }
}
