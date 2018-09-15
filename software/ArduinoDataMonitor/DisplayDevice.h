/*
 * DisplayDevice.h
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#ifndef DISPLAYDEVICE_H_
#define DISPLAYDEVICE_H_

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

class DisplayDevice {
public:
    typedef Adafruit_PCD8544 DeviceHandle_t;

	DisplayDevice();
	virtual ~DisplayDevice() = default;
	void init();

	void clean();
	void paint();
    uint8_t getHeight() const;
    uint8_t getWidth() const;
	void drawText(const char* text, const uint8_t x, const uint8_t y);
	// coordinates starts from lower right corner
	void drawLine(const uint8_t x, const uint8_t y, const uint8_t dx, const uint8_t dy);

private:

	Adafruit_PCD8544 display;
	static const uint8_t contrastLevelDefault = 45U;
};

#endif /* DISPLAYDEVICE_H_ */
