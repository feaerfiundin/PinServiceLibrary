#ifndef _PinServiceLibrary_h
#define _PinServiceLibrary_h
/*
 File Name		:		PinServiceLibrary.h
 Created		:		16/10/2017 16:20:55
 Author			:		feaer.fiundin at googlemail dot com
 Version		:		0.1.00
 Version History:		see PinServiceLibrary.ccp	
 Editor			:		http://www.visualmicro.com
 Licence		:		CC BY-NC
 Licence html   :		<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licenza Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">PinServiceLybrary</span> di<a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/feaerfiundin/PinServiceLibrary" property="cc:attributionName" rel="cc:attributionURL">Setfano Crivellin</a> è distribuito con Licenza <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Creative Commons Attribuzione - Non commerciale 4.0 Internazionale</a>.<br />Permessi ulteriori rispetto alle finalità della presente licenza possono essere disponibili presso <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/feaerfiundin/PinServiceLibrary" rel="cc:morePermissions">https://github.com/feaerfiundin/PinServiceLibrary</a>
 Purpose		:		Classe per utilizzo 
*/


#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
/*contenitore dei pin digitali
digital pin container*/
struct pinDate
{
	/*pin number*/
	int number;
	/*Start pinMode value:INPUT,OUTPUT,INPUT_PULLUP*/
	uint8_t pinMode;
	/*pin last status or start status value: HIGH, LOW */
	uint8_t pinStatus;
};
struct pinAnalog
{
	/*pin number value: A1,A2,A3....*/
	uint8_t number;
	int _previusValue;
};
class PinServiceClass
{
protected:


public:

	void init();
	/*
	it: crea un nuovo pin digitale e lo restituisce al chiamante
	en: make and return a new digitalpin
	*/
	pinDate newPin(int number, uint8_t pinMode, uint8_t pinstatus);
	/*
	it: crea pin digitali passati come array e li restituisce al chiamante
	en: make a and return a digitalpin array
	*/
	void arrayNewInit(pinDate pinNameArray[], int pinNumberArray[], uint8_t pinMode, uint8_t pinStatus);

	void newInit(pinDate pinName, int pinNumber, uint8_t pinMode, uint8_t pinStatus);
	void pinChangeStatus(pinDate pinchange, uint8_t newStatus);
	void pinChangeStatus(pinDate pinchange[], uint8_t newStatus);
	void pinReverseStatus(pinDate pinReverse);
	void pinReverseStatus(pinDate pinReverse[]);
	uint8_t readPinStatus(pinDate pinToRead);

private:
	void pinInit(pinDate newpininit);


};

extern PinServiceClass PinService;

#endif

