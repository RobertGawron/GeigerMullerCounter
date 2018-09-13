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
	hwKeyboard()//,
	//layoutWelcome(hwDisplay)
{
}

ApplicationBuilder::~ApplicationBuilder()
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
    hwDisplay.clean();
    bool wasKeyPressObserved = hwKeyboard.wasKeyPressObserved();

    if(wasKeyPressObserved)
    {
        Serial.print("key\n");
    }

   // Serial.print("key\n");
    delay(1);

#if 0
    hwDisplay.getDisplayHandle().setTextSize(0);
    hwDisplay.getDisplayHandle().setTextColor(BLACK);
    hwDisplay.getDisplayHandle().setCursor(0, 0);
    hwDisplay.getDisplayHandle().print("xxx");
    hwDisplay.getDisplayHandle().display();
#endif
}
