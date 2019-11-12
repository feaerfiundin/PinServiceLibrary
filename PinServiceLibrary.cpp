#include "PinServiceLibrary.h"

/*
File Name : PinServiceLibrary.h
Created : 16 / 10 / 2017 16 : 20 : 55
Author : Stefano Crivellin -- feaer.fiundin at googlemail dot com
Version : 0.1.02
Editor : http://www.visualmicro.com
Licence:		CC BY - NC
Licence html : <a rel = "license" href = "http://creativecommons.org/licenses/by-nc/4.0/"><img alt = "Licenza Creative Commons" style = "border-width:0" src = "https://i.creativecommons.org/l/by-nc/4.0/88x31.png" / >< / a><br / ><span xmlns : dct = "http://purl.org/dc/terms/" property = "dct:title">PinServiceLybrary< / span> di<a xmlns : cc = "http://creativecommons.org/ns#" href = "https://github.com/feaerfiundin/PinServiceLibrary" property = "cc:attributionName" rel = "cc:attributionURL">Setfano Crivellin< / a> è distribuito con Licenza <a rel = "license" href = "http://creativecommons.org/licenses/by-nc/4.0/">Creative Commons Attribuzione - Non commerciale 4.0 Internazionale< / a>.<br / >Permessi ulteriori rispetto alle finalità della presente licenza possono essere disponibili presso <a xmlns : cc = "http://creativecommons.org/ns#" href = "https://github.com/feaerfiundin/PinServiceLibrary" rel = "cc:morePermissions">https ://github.com/feaerfiundin/PinServiceLibrary</a>

History:
0.1.00 - Initial Version
0.1.01 - Add documentation
0.1.02 - add analog pin wrapper an rename struct for digital pin

*/

void PinServiceClass::init()
{
}

pinDigital PinServiceClass::newDigPin(int number, uint8_t pinMode, uint8_t pinStatus)
{
	pinDigital newpindate;
	newpindate.number = number;
	newpindate.pinMode = pinMode;
	newpindate.pinStatus = pinStatus;
	return newpindate;
}

pinDigital PinServiceClass::newDigInit(int pinNumber, uint8_t pinMode, uint8_t pinStatus)
{
	pinDigital pinName = newDigPin(pinNumber, pinMode, pinStatus);
	pinInit(pinName);
	return pinName;
}

void PinServiceClass::pinInit(pinDigital newpininit)
{
	pinMode(newpininit.number, newpininit.pinMode);
	digitalWrite(newpininit.number, newpininit.pinStatus);
}

void PinServiceClass::pinChangeStatus(pinDigital pinchange, uint8_t newStatus)
{
	int pinActualStatus = digitalRead(pinchange.number);
	if (pinActualStatus != newStatus) {
		digitalWrite(pinchange.number, newStatus);
		pinchange.pinStatus = newStatus;
	}
}

void PinServiceClass::pinChangeStatus(pinDigital pinchange[], uint8_t newStatus)
{
	int arraySize = sizeof(pinchange);
	for (int i = 0; i < arraySize; i++) {
		pinChangeStatus(pinchange[i], newStatus);
	}
}

void PinServiceClass::pinReverseStatus(pinDigital pinReverse)
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

void PinServiceClass::pinReverseStatus(pinDigital pinReverse[])
{
	int arraySize = sizeof(pinReverse);
	for (int i = 0; i < arraySize; i++) {
		pinReverseStatus(pinReverse[i]);
	}
}

uint8_t PinServiceClass::readDigitalPinStatus(pinDigital pinToRead)
{
	uint8_t pinStatus = digitalRead(pinToRead.number);
	if (pinToRead.pinStatus != pinStatus) {
		pinToRead.pinStatus = pinStatus;
	}
	return pinStatus;
}

pinAnalog PinServiceClass::newAnalogPin(int number, int refVolt, int noise)
{
	pinAnalog newPinAnalog;
	newPinAnalog.number = number;
	if (refVolt < 5000) {
		newPinAnalog.refVolt = refVolt;
	}
	if (noise != 2 ) 
	{
		if (noise <=20)
		{
			newPinAnalog.noise = noise;
		 }
		else
		{
			newPinAnalog.noise = 20;
		 }
	}
	return pinAnalog();
}

int PinServiceClass::readAnalogPin(uint8_t pinNumber)
{
	int readValue = analogRead(pinNumber);
	return readValue;
}
/*

Bozza per i metodi analogici
AnalogPin::AnalogPin(const uint8_t pin)
{
	_pin = pin;
	_prevValue = analogRead(pin);
}

int AnalogPin::read(const uint8_t noise)
{
	int value = analogRead(_pin);
	if (noise == 0 || ((value - _prevValue) & 0x7FFF) > noise)
	{
		_prevValue = value;
	}
	return _prevValue;
}

int AnalogPin::readSmoothed(uint8_t alpha)
{
	if (alpha > 31) alpha = 31;
	int value = analogRead(_pin);
	if (alpha > 0)
	{
		value = value + (alpha * (_prevValue - value)) / 32;
	}
	_prevValue = value;
	return value;
}

int AnalogPin::readPrevious()
{
	return _prevValue;
}*/

PinServiceClass PinService;