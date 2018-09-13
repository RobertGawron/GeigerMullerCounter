/*
 * LayoutBuilder.cpp
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#include "LayoutBuilder.h"

LayoutBuilder::LayoutBuilder(DisplayDevice& hwDisplay):
    layoutWelcome(hwDisplay),
    layoutPulseCounterMinuteInterval(hwDisplay, LayoutPulseCounter::MINUTE_INTERVALS),
    layoutPulseCounterHourInterval(hwDisplay, LayoutPulseCounter::HOUR_INTERVALS)
{
}


