/*
 * LayoutBuilder.cpp
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#include "LayoutHandler.h"

LayoutHandler::LayoutHandler(DisplayDevice& hwDisplay, MeasurementHistory& data):
    layoutWelcome(hwDisplay),
    layoutPulseCounterMinuteInterval(hwDisplay, LayoutPulseCounter::MINUTE_INTERVALS),
    layoutPulseCounterHourInterval(hwDisplay, LayoutPulseCounter::HOUR_INTERVALS),
    currentLayoutIndex(0U),
    data(data)
{
    userLayouts[0] = &layoutPulseCounterMinuteInterval;
    userLayouts[1] = &layoutPulseCounterHourInterval;
}


void LayoutHandler::handleKeyPress()
{
    userLayouts[currentLayoutIndex]->draw(data);

    currentLayoutIndex++;
    currentLayoutIndex %= userLayoutsCount;
}

