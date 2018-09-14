/*
 * GMDevice.h
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#ifndef GMDEVICE_H_
#define GMDEVICE_H_

#include <stdint.h>

class GMDevice
{
public:
	GMDevice() = default;
	virtual ~GMDevice() = default;
	void init();
	uint16_t getCounterValue();
	void resetCounterValue();

private:
	static const uint8_t gmInputPin = 2;
};

#endif /* GMDEVICE_H_ */
