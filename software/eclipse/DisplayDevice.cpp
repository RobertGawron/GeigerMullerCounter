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
    paint();
}

uint8_t DisplayDevice::getHeight() const
{
    return LCDHEIGHT;
}

uint8_t DisplayDevice::getWidth() const
{
    return LCDWIDTH;
}

void DisplayDevice::drawLine(const uint8_t x, const uint8_t y, const uint8_t dx, const uint8_t dy)
{
    display.drawLine(x, (getHeight() - y), x, (getHeight() - dy), BLACK);
}

void DisplayDevice::paint()
{
    display.display();
}

void DisplayDevice::drawText(const char* text, const uint8_t x, const uint8_t y)
{
       display.setTextSize(0);
       display.setTextColor(BLACK);
       display.setCursor(2, 1);
       display.print(text);
}

