#ifndef __LED_ARRAY_H__
#define __LED_ARRAY_H__

#include "Arduino.h"

class LedArray {
public:
	LedArray(byte csPin, byte clkPin, byte dataPin);

	void begin();
	void writeData(byte address, byte data);
	void writeBlock(byte* data);
protected:
	byte _csPin, _clkPin, _dataPin;

	void setupPin();
	void initChip();

	void writeByte(byte data);
};


#endif __LED_ARRAY_H__
