/*
 * ApplicationBuilder.cpp
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#include "ApplicationBuilder.h"

ApplicationBuilder::ApplicationBuilder():
	hwDisplay(),
	hwGeigerMuller(),
	keyboardDevice()
{
}

ApplicationBuilder::~ApplicationBuilder()
{
}

void ApplicationBuilder::init()
{
    hwDisplay.init();
    hwGeigerMuller.init();
    keyboardDevice.init();
}

void ApplicationBuilder::run()
{
    //
}
