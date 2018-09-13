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
	layoutWelcome(hwDisplay)
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
    bool wasKeyPressObserved = hwKeyboard.wasKeyPressObserved();

    if(wasKeyPressObserved)
    {
        Serial.print("key\n");
        layoutWelcome.draw();
    }

    delay(1);

#if 0
    void Layout::drawText(char* data, uint8_t x, uint8_t y)
    {
        itsDisplay.setTextSize(0);
        itsDisplay.setTextColor(BLACK);
        itsDisplay.setCursor(x, y);
        itsDisplay.print(data);
    }

    void Layout::drawNumber(uint8_t data, uint8_t x, uint8_t y)
    {
        itsDisplay.setTextSize(0);
        itsDisplay.setTextColor(BLACK);
        itsDisplay.setCursor(x, y);
        itsDisplay.print(data);
    }



    hwDisplay.getDisplayHandle().setTextSize(0);
    hwDisplay.getDisplayHandle().setTextColor(BLACK);
    hwDisplay.getDisplayHandle().setCursor(0, 0);
    hwDisplay.getDisplayHandle().print("xxx");
    hwDisplay.getDisplayHandle().display();
#endif
}
