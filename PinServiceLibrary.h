/*
 Name:		PinServiceLibrary.h
 Created:	16/10/2017 16:20:55
 Author:	feaer.fiundin
 Editor:	http://www.visualmicro.com
*/

#ifndef _PinServiceLibrary_h
#define _PinServiceLibrary_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct pinDate
{
	int number;
	uint8_t pinMode;
	uint8_t pinStatus;
};
class PinServiceClass
{
protected:


public:
	void init();
	pinDate newPin(int number, uint8_t pinMode, uint8_t pinstatus);
	void arrayNewInit(pinDate pinNameArray[], int pinNumberArray[], uint8_t pinMode, uint8_t pinStatus);
	void newInit(pinDate &pinName, int pinNumber, uint8_t pinMode, uint8_t pinStatus);
	void pinInit(pinDate newpininit);
	void pinChangeStatus(pinDate &pinchange, uint8_t newStatus);
	void pinChangeStatus(pinDate pinchange[], uint8_t newStatus);
	void pinReverseStatus(pinDate &pinReverse);
	void pinReverseStatus(pinDate pinReverse[]);
	uint8_t readPinStatus(pinDate pinToRead);




};

extern PinServiceClass PinService;

#endif

