# PinServiceLibrary

## PinServiceLibrary

Author	:			Esc4DEV -- feaer.fiundin at gmail dot com
Version :			0.1.02
documentation date :12/11/2019



## Todo List

### Class PinServiceClass  
	- implement all Analog Function 


## Class Index

### Class List

Here are the classes, structs, unions and interfaces with brief descriptions:

	1.pinAnalog  	
	2.pinDigital  	
	3.PinServiceClass  	

## Class Documentation
	### pinAnalog Struct Reference

		Detailed Description
			pinAnalog analog pin Struct

		Parameters:

			-number 		:name of digital pin example value: A1,A2,A3... 
			-_previusValue 	:last value read 
			-refVolt 	:reference voltage in mv, if not set base value is 5000 mv 
			-noise 		:param reduce read noise value is 0 to 1023, in practice 0..20 default value is 2 -max noise = 20 



pinDigital Struct Reference

Detailed Description

pinDigital digital pin Struct 


Parameters:

-number 		:number of digitalpin example 1to 13 for arduino uno 
-pinMode		:start mode of digital pin value: INPUT,OUTPUT,INPUT_PULLUP 
-pinStatus	:pin last or start status example value : HIGH,LOW 



PinServiceClass Class Reference

Public Member Functions

pinDigital newDigPin (int number, uint8_t pinMode, uint8_t pinStatus)

Detailed Description

Class for simple interact with digital pin, and semplify analog read

Todo:
implement all Analog Function 



Member Function Documentation

pinDigital PinServiceClass::newDigPin (int  number, uint8_t  pinMode, uint8_t  pinStatus)

create a new struct pin digital with param 

Parameters:

-number 		:int number of pin to control 
-pinMode 	:uint8_t start operating mode. Example value: INPUT,OUTPUT,INPUT_PULLUP 
-pinStatus 	:uint8_t start status or last read value for inputpin or last write status for outputpin. Example Value : HIGH,LOW 


Returns

-pinDate return pinDate Struct populate 

The documentation for this class was generated from the following files:
PinServiceLibrary.h
PinServiceLibrary.cpp

