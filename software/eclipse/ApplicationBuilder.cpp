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
	layoutWelcome(hwDisplay),
	layoutPulseCounter(hwDisplay)
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
        Serial.print("key\n");
        //layoutWelcome.draw();

    }

    layoutPulseCounter.draw();

    delay(10);
}
