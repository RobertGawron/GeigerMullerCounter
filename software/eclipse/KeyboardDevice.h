/*
 * KeyboardDevice.h
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#ifndef KEYBOARDDEVICE_H_
#define KEYBOARDDEVICE_H_

#include <stdint.h>

class KeyboardDevice
{
public:
    KeyboardDevice();
    virtual ~KeyboardDevice();
    void init();

private:
    static const uint8_t userKeyPin = 8;
};

#endif /* KEYBOARDDEVICE_H_ */
