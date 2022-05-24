#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void MDIO_u8SetPortDirection (u8 Copy_u8PortName,u8 Copy_u8PortDirection);
void MDIO_u8SetPortValue (u8 Copy_u8PortName,u8 Copy_u8PortOutput);
void MDIO_voidSetPinDirection (u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection);
void MDIO_u8SetPinValue (u8 Copy_u8PortDirection,u8 Copy_u8PinNumber,u8 Copy_u8PinValue);
u8 MDIO_u8GetPort (u8 Copy_u8PortName);
u8 MDIO_u8GetPinValue (u8 Copy_u8PortName , u8 Copy_u8PinNumber);

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0 
#define DIO_PIN1 1 
#define DIO_PIN2 2 
#define DIO_PIN3 3 
#define DIO_PIN4 4 
#define DIO_PIN5 5 
#define DIO_PIN6 6 
#define DIO_PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_OUTPUT_HIGH 1
#define DIO_OUPUT_LOW 0

#endif 
