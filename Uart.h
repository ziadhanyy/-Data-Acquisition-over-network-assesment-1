#ifndef _UART_
#define _UART_

void Uart_Init(void);

void Uart_SetBaudRate(unsigned short BuadRate);     // u art sets rate  to be unsigned short and is called buadrate(number of bits per second)

void Uart_SendChar(unsigned char DataByte);         // u art sends char to be unsigned datatype

unsigned char Uart_IsDataAvailable(void);           // u art is asked if data available and if it is available then then u art reads data

unsigned char Uart_ReadData();

void Uart_SendString(const char DataString[]);      // u art sends the string to be in a list called datastring

#endif
