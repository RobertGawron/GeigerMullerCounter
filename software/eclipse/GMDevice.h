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
	GMDevice();
	virtual ~GMDevice();
	void init();

private:
	static const uint8_t ledPin = 13;
	static const uint8_t gmInputPin = 2;

};

#endif /* GMDEVICE_H_ */
