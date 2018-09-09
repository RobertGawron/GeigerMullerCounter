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

class ApplicationBuilder
{
public:
	ApplicationBuilder();
	virtual ~ApplicationBuilder();
	void init();
	void run();

private:
	DisplayDevice hwDisplay;
	GMDevice hwGeigerMuller;
	KeyboardDevice keyboardDevice;
};

#endif /* APPLICATIONBUILDER_H_ */
