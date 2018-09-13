/*
 * ApplicationBuilder.h
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#ifndef APPLICATIONBUILDER_H_
#define APPLICATIONBUILDER_H_

#include "GMDevice.h"
#include "DisplayDevice.h"
#include "KeyboardDevice.h"
#include "LayoutWelcome.h"
#include "LayoutPulseCounter.h"
#include "MeasurementHistory.h"

class ApplicationBuilder
{
public:
	ApplicationBuilder();
	virtual ~ApplicationBuilder() = default;
	void init();
	void run();

private:
	static const uint16_t SerialBaudRateDefault = 9600U;

	DisplayDevice hwDisplay;
	GMDevice hwGeigerMuller;
	KeyboardDevice hwKeyboard;

	MeasurementHistory<uint16_t, 100U> sampleBufferPerMinute;
	MeasurementHistory<uint16_t, 100U> sampleBufferPerHour;

	LayoutWelcome layoutWelcome;
	LayoutPulseCounter layoutPulseCounter;
};

#endif /* APPLICATIONBUILDER_H_ */
