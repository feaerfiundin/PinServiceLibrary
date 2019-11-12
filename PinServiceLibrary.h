#ifndef _PinServiceLibrary_h
#define _PinServiceLibrary_h
/*
 File Name		:		PinServiceLibrary.h
 Created		:		16/10/2017 16:20:55
 Author			:		ESC4DEV -- feaer.fiundin at googlemail dot com
 Version		:		0.1.02
 History		:		see PinServiceLibrary.ccp
 Editor			:		http://www.visualmicro.com
 Purpose		:		digital and analog pin method wrapper
 Licence		:		CC BY-NC
 Licence html  :		<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licenza Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">PinServiceLybrary</span> di<a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/feaerfiundin/PinServiceLibrary" property="cc:attributionName" rel="cc:attributionURL">Setfano Crivellin</a> è distribuito con Licenza <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Creative Commons Attribuzione - Non commerciale 4.0 Internazionale</a>.<br />Permessi ulteriori rispetto alle finalità della presente licenza possono essere disponibili presso <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/feaerfiundin/PinServiceLibrary" rel="cc:morePermissions">https://github.com/feaerfiundin/PinServiceLibrary</a>
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

/**
*pinDigital
*digital pin Struct
*@param number	   number of digitalpin example 1to 13 for arduino uno
*@param pinMode	   start mode of digital pin value: INPUT,OUTPUT,INPUT_PULLUP
*@param pinStatus  pin last or start status example value : HIGH,LOW
*/
struct pinDigital
{
	int number;
	uint8_t pinMode;
	uint8_t pinStatus;
};
/**
*pinAnalog
*analog pin Struct
*
*@param number         name of digital pin example value: A1,A2,A3...
*@param _previusValue  last value read
*@param refVolt		   reference voltage in mv, if not set base value is 5000 mv
*@param noise		   param reduce read noise  value is 0 to 1023, in practice 0..20 default value is 2 max noise = 20
*/
struct pinAnalog
{
	uint8_t number;
	int _previusValue;
	int refVolt=5000;
	int noise=2;
};

/**
*Class for simple interact with digital pin, and semplify analog read
*
*\todo implement all Analog Function
*\todo
*\todo
*/

class PinServiceClass
{
public:
	void init();
	/**
	*create a new struct pin digital with param
	*@param number	  int number of pin to control
	*@param pinMode	  uint8_t start operating mode. Example value: INPUT,OUTPUT,INPUT_PULLUP
	*@param pinStatus uint8_t start status or last read value for inputpin or last write status for outputpin. Example Value : HIGH,LOW
	*@return pinDate  return pinDate Struct populate
	*/
	pinDigital newDigPin(int number, uint8_t pinMode, uint8_t pinStatus);

	pinDigital newDigInit(int pinNumber, uint8_t pinMode, uint8_t pinStatus);
	void pinInit(pinDigital pinToInit[]);
	void pinInit(pinDigital newpininit);
	void pinChangeStatus(pinDigital pinchange, uint8_t newStatus);
	void pinChangeStatus(pinDigital pinchange[], uint8_t newStatus);
	void pinReverseStatus(pinDigital pinReverse);
	void pinReverseStatus(pinDigital pinReverse[]);
	uint8_t readDigitalPinStatus(pinDigital pinToRead);

	pinAnalog newAnalogPin(int number, int refVolt = 5000, int noise = 2);
	int readBitAnalogPin(pinAnalog pintoread);
	int readBitAnalogPinWithNoise(pinAnalog pinToRead, int noise);
	int readBitAnalogPinWithDefaultNoise(pinAnalog pinToRead);
	int readBitAnalogPinSmoothed(pinAnalog pinToRead, int alpha);
	double readAnalogPin(pinAnalog pinToRead);
	double readAnalogPinWithNoise(pinAnalog pinToRead, int noise);
	double readAnalogPinWithDefaultNoise(pinAnalog pinToRead);
	double readAnalogPinSmoothed(pinAnalog pinToRead);

private:

	int readAnalogPin(uint8_t number);
};

extern PinServiceClass PinService;

#endif

/*end of file*/
