#include "PinServiceLibrary.h"

/*
File Name : PinServiceLibrary.h
Created : 16 / 10 / 2017 16 : 20 : 55
Author : Stefano Crivellin -- feaer.fiundin at googlemail dot com
Version : 0.1.00
Editor : http://www.visualmicro.com
Licence:		CC BY - NC
Licence html : <a rel = "license" href = "http://creativecommons.org/licenses/by-nc/4.0/"><img alt = "Licenza Creative Commons" style = "border-width:0" src = "https://i.creativecommons.org/l/by-nc/4.0/88x31.png" / >< / a><br / ><span xmlns : dct = "http://purl.org/dc/terms/" property = "dct:title">PinServiceLybrary< / span> di<a xmlns : cc = "http://creativecommons.org/ns#" href = "https://github.com/feaerfiundin/PinServiceLibrary" property = "cc:attributionName" rel = "cc:attributionURL">Setfano Crivellin< / a> è distribuito con Licenza <a rel = "license" href = "http://creativecommons.org/licenses/by-nc/4.0/">Creative Commons Attribuzione - Non commerciale 4.0 Internazionale< / a>.<br / >Permessi ulteriori rispetto alle finalità della presente licenza possono essere disponibili presso <a xmlns : cc = "http://creativecommons.org/ns#" href = "https://github.com/feaerfiundin/PinServiceLibrary" rel = "cc:morePermissions">https ://github.com/feaerfiundin/PinServiceLibrary</a>

History:
0.1.00 - Initial Version
0.1.01 - Add documentation


*/




void PinServiceClass::init()
{
	
}

pinDate PinServiceClass::newPin(int number, uint8_t pinMode, uint8_t pinstatus)
{
	pinDate newpindate;
	newpindate.number = number;
	newpindate.pinMode = pinMode;
	newpindate.pinStatus = pinstatus;
	pinInit(newpindate);
	return newpindate;
}

void PinServiceClass::arrayNewInit(pinDate pinNameArray[], int pinNumberArray[], uint8_t pinMode, uint8_t pinStatus)
{
	int arraySize = min(sizeof(pinNameArray), sizeof(pinNumberArray));
	for (int i = 0;i < arraySize; i++) {
		newInit(pinNameArray[i], pinNumberArray[i], pinMode, pinStatus);
	}
}

void PinServiceClass::newInit(pinDate pinName, int pinNumber, uint8_t pinMode, uint8_t pinStatus)
{
	pinName = newPin(pinNumber, pinMode, pinStatus);
	pinInit(pinName);

}

void PinServiceClass::pinInit(pinDate newpininit)
{
	pinMode(newpininit.number, newpininit.pinMode);
	digitalWrite(newpininit.number, newpininit.pinStatus);
}

void PinServiceClass::pinChangeStatus(pinDate pinchange, uint8_t newStatus)
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

