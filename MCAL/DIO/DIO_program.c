#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
/*THIS FUNCTION DETERMINES THE DIRECTION THE ENTIRE PORT WILL BE 
IT TAKES ARGUMENTS OF THE PORT 
AVAILABLE OPTIONS :
DIO_PORTA
DIO_PORTB
DIO_PORTC
DIO_PORTD

AND A U8 VALUE THAT DETERMINES THE DIRECTION OF THE PINS */
void MDIO_u8SetPortDirection (u8 Copy_u8PortName,u8 Copy_u8PortDirection)
{
	switch(Copy_u8PortName){
	case DIO_PORTA : DDRA = Copy_u8PortDirection;
	break;
	case DIO_PORTB : DDRB = Copy_u8PortDirection;
	break;
	case DIO_PORTC : DDRC = Copy_u8PortDirection;
	break;
	case DIO_PORTD : DDRD = Copy_u8PortDirection;
	break;
	default : break;
	}
}
/*THIS FUNCTION DETERMINES THE VALUE TO BE OUTPUT FOR THE ENTIRE PORT 
IT TAKES ARGUMENTS OF THE PORT 
AVAILABLE OPTIONS :
DIO_PORTA
DIO_PORTB
DIO_PORTC
DIO_PORTD

AND A U8 VALUE THAT DETERMINES THE OUTPUT OF THE PINS 
ALSO FUNCTION IS USED TO CONFIGURE AN INPUT PIN OR PORT TO USE PULL UP OR PULL DOWN RESISTOR 

1 FOR PULL UP
0 FOR PULL DOWN */
void MDIO_u8SetPortValue (u8 Copy_u8PortName,u8 Copy_u8PortOutput)
{
	switch(Copy_u8PortName){
	case DIO_PORTA : PORTA = Copy_u8PortOutput;
	break;
	case DIO_PORTB : PORTB = Copy_u8PortOutput;
	break;
	case DIO_PORTC : PORTC = Copy_u8PortOutput;
	break;
	case DIO_PORTD : PORTD = Copy_u8PortOutput;
	break;
	default : break;
	}
}
/*FUNCTION CONFIGURES THE DIRECTION OF AN IO PIN
ARGUMENT 1 OPTIONS :
DIO_PORTA
DIO_PORTB
DIO_PORTC
DIO_PORTD

ARGUMENT 2 OPTIONS 
PIN0-PIN7

ARGUMENT 3 OPTIONS
DIO_OUTPUT
DIO_INPUT */
void MDIO_voidSetPinDirection (u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection){
	switch(Copy_u8PortName){

	case DIO_PORTA : if(Copy_u8PinDirection==DIO_OUTPUT) {DDRA |= (1<<Copy_u8PinNumber);}
	  else   if (Copy_u8PinDirection==DIO_INPUT) {DDRA &= ~(1<<Copy_u8PinNumber);}
	break;

	case DIO_PORTB : if(Copy_u8PinDirection==DIO_OUTPUT) {DDRB |= (1<<Copy_u8PinNumber);}
	  else   if (Copy_u8PinDirection==DIO_INPUT) {DDRB &= ~(1<<Copy_u8PinNumber);}
	break;

	case DIO_PORTC : if(Copy_u8PinDirection==DIO_OUTPUT) {DDRC |= (1<<Copy_u8PinNumber);}
	  else   if (Copy_u8PinDirection==DIO_INPUT) {DDRC &= ~(1<<Copy_u8PinNumber);}
	break;

	case DIO_PORTD : if(Copy_u8PinDirection==DIO_OUTPUT) {DDRD |= (1<<Copy_u8PinNumber);}
	  else   if (Copy_u8PinDirection==DIO_INPUT) {DDRD &= ~(1<<Copy_u8PinNumber);}

	break;
	default : break;
	}
	}



/*FUNCTION DETERMINES THE OUTPUT OF AN IO PIN
ARGUMENT 1 OPTIONS :
DIO_PORTA
DIO_PORTB
DIO_PORTC
DIO_PORTD

ARGUMENT 2 OPTIONS 
PIN0-PIN7

ARGUMENT 3 OPTIONS
DIO_OUTPUT_HIGH
DIO_OUTPUT_LOW 

ALSO WORKS AS TO DEFINE INPUT PIN CONFIGURATION
DIO_OUTPUT_HIGH FOR PULLUP 
DIO_OUTPUT_LOW FOR PULLDOWN*/
void MDIO_u8SetPinValue (u8 Copy_u8PortDirection,u8 Copy_u8PinNumber,u8 Copy_u8PinValue){

switch(Copy_u8PortDirection){

case DIO_PORTA : if(Copy_u8PinValue==DIO_OUTPUT_HIGH) {PORTA |= (1<<Copy_u8PinNumber);}
  else   if (Copy_u8PinValue==DIO_OUTPUT_LOW) {PORTA &= ~(1<<Copy_u8PinNumber);}
break;

case DIO_PORTB : if(Copy_u8PinValue==DIO_OUTPUT_HIGH) {PORTB |= (1<<Copy_u8PinNumber);}
  else   if (Copy_u8PinValue==DIO_OUTPUT_LOW) {PORTB &= ~(1<<Copy_u8PinNumber);}
break;

case DIO_PORTC : if(Copy_u8PinValue==DIO_OUTPUT_HIGH) {PORTC |= (1<<Copy_u8PinNumber);}
  else   if (Copy_u8PinValue==DIO_OUTPUT_LOW) {PORTC &= ~(1<<Copy_u8PinNumber);}
break;

case DIO_PORTD : if(Copy_u8PinValue==DIO_OUTPUT_HIGH) {PORTD |= (1<<Copy_u8PinNumber);}
  else   if (Copy_u8PinValue==DIO_OUTPUT_LOW) {PORTD &= ~(1<<Copy_u8PinNumber);}

break;
default : break;
}
}
//RETURNS THE VALU OF AN INPUT PORT 
u8 MDIO_u8GetPort (u8 Copy_u8PortName){
	u8 Local_u8PortValue;
	switch (Copy_u8PortName){
		case DIO_PORTA : Local_u8PortValue=PINA;
		break;
		case DIO_PORTB : Local_u8PortValue=PINB;
		break;
		case DIO_PORTC : Local_u8PortValue=PINC;
		break;
		case DIO_PORTD : Local_u8PortValue=PIND;
		break;
		default : break;
	}
	return Local_u8PortValue;
}
//RETURNS THE VALUE OF AN INPUT PIN
u8 MDIO_u8GetPinValue (u8 Copy_u8PortName , u8 Copy_u8PinNumber){
u8 Local_u8PinValue;
switch(Copy_u8PortName){
case DIO_PORTA : Local_u8PinValue =  ((PINA >> Copy_u8PinNumber)&1);
break;
case DIO_PORTB : Local_u8PinValue =  ((PINB >> Copy_u8PinNumber)&1);
break;
case DIO_PORTC : Local_u8PinValue =  ((PINC >> Copy_u8PinNumber)&1);
break;
case DIO_PORTD : Local_u8PinValue =  ((PIND >> Copy_u8PinNumber)&1);
break;
default : break;
}
return Local_u8PinValue;
}