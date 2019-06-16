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
#include "LayoutHandler.h"
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

	static const uint16_t intervalLoopKeyHandling = 10U;
	static const uint16_t intervalLoopGMDataHandling = 1000U;

	DisplayDevice hwDisplay;
	GMDevice hwGeigerMuller;
	KeyboardDevice hwKeyboard;

	MeasurementHistory measurementHistory;
	LayoutHandler layoutHandler;
};

#endif /* APPLICATIONBUILDER_H_ */