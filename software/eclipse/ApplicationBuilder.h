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

class ApplicationBuilder
{
public:
	ApplicationBuilder();
	virtual ~ApplicationBuilder();
	void init();
	void run();

private:
	static const uint16_t SerialBaudRateDefault = 9600U;

	DisplayDevice hwDisplay;
	GMDevice hwGeigerMuller;
	KeyboardDevice hwKeyboard;

	LayoutWelcome layoutWelcome;
};

#endif /* APPLICATIONBUILDER_H_ */
