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
	sampleBufferPerMinute(),
	sampleBufferPerHour(),
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

    sampleBufferPerMinute.add(1);
    sampleBufferPerMinute.add(17);
}

void ApplicationBuilder::run()
{
    bool wasKeyPressObserved = hwKeyboard.wasKeyPressObserved();

    if(wasKeyPressObserved)
    {
        Serial.print("key\n");
        layoutWelcome.draw(sampleBufferPerMinute);

    }

    layoutPulseCounter.draw(sampleBufferPerMinute);
while(1);
    delay(10);
}
