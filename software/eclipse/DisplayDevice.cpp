/*
 * DisplayDevice.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "DisplayDevice.h"

DisplayDevice::DisplayDevice() :
    // Software SPI (slower updates, more flexible pin options):
    // pin 7 - Serial clock out (SCLK)
    // pin 6 - Serial data out (DIN)
    // pin 5 - Data/Command select (D/C)
    // pin 4 - LCD chip select (CS)
    // pin 3 - LCD reset (RST)
    //Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
    display(3,4,5,6,7)
{
}

void DisplayDevice::init()
{
    display.begin();
    display.setContrast(contrastLevelDefault);
    clean();

}

void DisplayDevice::clean()
{
    display.clearDisplay();
    display.display();
}

DisplayDevice::~DisplayDevice()
{
}

DisplayDevice::DeviceHandle_t& DisplayDevice::getDisplayHandle()
{
    return display;
}
