#include <LedArray.h>

LedArray::LedArray(byte csPin, byte clkPin, byte dataPin) {
	_csPin = csPin;
	_clkPin = clkPin;
	_dataPin = dataPin;	
}

void LedArray::begin() {
	setupPin();
	
	initChip();

}	

void LedArray::setupPin() {
	pinMode(_csPin, OUTPUT);
	pinMode(_dataPin, OUTPUT);
	pinMode(_clkPin, OUTPUT);
}

void LedArray::initChip() {
	writeData(0x09, 0x00);
	writeData(0x0a, 0x03);
	writeData(0x0b, 0x07);
	writeData(0x0c, 0x01);
	writeData(0x0f, 0x00);
}

void LedArray::writeByte(byte data) {
	for(byte i = 0; i < 8; i++)
	{	
		digitalWrite(_clkPin, LOW);	  

		digitalWrite(_dataPin, (data & 0x80) ? HIGH : LOW);

		data =  data << 1;

		digitalWrite(_clkPin, HIGH); 
	}        
}

void LedArray::writeData(byte address, byte data) {
	digitalWrite(_csPin, LOW);

	writeByte(address);
	writeByte(data);
	
	digitalWrite(_csPin, HIGH); 
}

void LedArray::writeBlock(byte* data) {
	for(byte address = 1; address < 9; address++)
		writeData(address, data[address - 1]);
}
