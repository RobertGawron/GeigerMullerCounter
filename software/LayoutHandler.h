/*
 * LayoutBuilder.h
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#ifndef LAYOUTHANDLER_H_
#define LAYOUTHANDLER_H_

#include "LayoutWelcome.h"
#include "LayoutPulseCounter.h"

class LayoutHandler
{
public:
    LayoutHandler(DisplayDevice& hwDisplay, MeasurementHistory& data);
    virtual ~LayoutHandler() = default;

    void handleKeyPress();

private:
    LayoutWelcome layoutWelcome;
    LayoutPulseCounter layoutPulseCounterMinuteInterval;
    LayoutPulseCounter layoutPulseCounterHourInterval;

    // It's one less than defined above, because we don't want to use LayoutWelcome in runtime.
    static const uint8_t userLayoutsCount = 2;
    Layout* userLayouts[userLayoutsCount];
    uint8_t currentLayoutIndex;

    MeasurementHistory& data;
};

#endif /* LAYOUTHANDLER_H_ */