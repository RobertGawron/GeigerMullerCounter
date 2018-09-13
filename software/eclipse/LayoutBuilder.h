/*
 * LayoutBuilder.h
 *
 *  Created on: 13 wrz 2018
 *      Author: robert
 */

#ifndef LAYOUTBUILDER_H_
#define LAYOUTBUILDER_H_

#include "LayoutWelcome.h"
#include "LayoutPulseCounter.h"

class LayoutBuilder
{
public:
    LayoutBuilder(DisplayDevice& hwDisplay);
    virtual ~LayoutBuilder() = default;
private:
    LayoutWelcome layoutWelcome;
    LayoutPulseCounter layoutPulseCounterMinuteInterval;
    LayoutPulseCounter layoutPulseCounterHourInterval;
};

#endif /* LAYOUTBUILDER_H_ */
