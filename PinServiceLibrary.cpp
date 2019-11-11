/*
 Name:		PinServiceLibrary.cpp
 Created:	16/10/2017 16:20:55
 Author:	feaer.fiundin
 Editor:	http://www.visualmicro.com
*/

#include "PinServiceLibrary.h"



void PinServiceClass::init()
{


}

pinDate PinServiceClass::newPin(int number, uint8_t pinMode, uint8_t pinstatus)
{
	pinDate newpindate;
	newpindate.number = number;
	newpindate.pinMode = pinMode;
	newpindate.pinStatus = pinstatus;
	return newpindate;
}

void PinServiceClass::arrayNewInit(pinDate pinNameArray[], int pinNumberArray[], uint8_t pinMode, uint8_t pinStatus)
{
	int arraySize = min(sizeof(pinNameArray), sizeof(pinNumberArray));
	for (int i = 0;i < arraySize; i++) {
		newInit(pinNameArray[i], pinNumberArray[i], pinMode, pinStatus);
	}
}

void PinServiceClass::newInit(pinDate &pinName, int pinNumber, uint8_t pinMode, uint8_t pinStatus)
{
	pinName = newPin(pinNumber, pinMode, pinStatus);
	pinInit(pinName);

}

void PinServiceClass::pinInit(pinDate newpininit)
{
	pinMode(newpininit.number, newpininit.pinMode);
	digitalWrite(newpininit.number, newpininit.pinStatus);
}

void PinServiceClass::pinChangeStatus(pinDate &pinchange, uint8_t newStatus)
{

	int pinActualStatus = digitalRead(pinchange.number);
	if (pinActualStatus != newStatus) {
		digitalWrite(pinchange.number, newStatus);
		pinchange.pinStatus = newStatus;
	}
}

void PinServiceClass::pinChangeStatus(pinDate pinchange[], uint8_t newStatus)
{
	int arraySize = sizeof(pinchange);
	for (int i = 0; i < arraySize; i++) {
		pinChangeStatus(pinchange[i], newStatus);
	}
}

void PinServiceClass::pinReverseStatus(pinDate & pinReverse)
{
	if (pinReverse.pinStatus = HIGH) {
		digitalWrite(pinReverse.number, LOW);
		pinReverse.pinStatus = LOW;
	}
	else {
		digitalWrite(pinReverse.number, HIGH);
		pinReverse.pinStatus = HIGH;
	}
}

void PinServiceClass::pinReverseStatus(pinDate pinReverse[])
{
	int arraySize = sizeof(pinReverse);
	for (int i = 0; i < arraySize; i++) {
		pinReverseStatus(pinReverse[i]);
	}
}

uint8_t PinServiceClass::readPinStatus(pinDate pinToRead)
{
	uint8_t pinStatus = digitalRead(pinToRead.number);
	return pinStatus;
}


PinServiceClass PinService;

