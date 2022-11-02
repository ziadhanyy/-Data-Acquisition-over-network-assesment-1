#ifndef _DIO__
#define _DIO_

void Dio_SetPinDirection(unsigned char DDRX, unsigned char Pin,unsigned char Direction);
unsigned char Dio_GetPinState(unsigned char Port,unsigned char pin);
void Dio_SetPortDirection(unsigned char PORTX, unsigned char Pin,unsigned char Direction);
#endif





#include <avr/io.h>

#define SetBit(Reg,Pin) (Reg |= (1<<Pin))           //to change one bit from 0 to 1
#define ClearBit(Reg,Pin) (Reg &=~ (1<<Pin))          //to change one bit from 1 to 0 
#define ToggleBit(Reg,Pin) (Reg ^= (1<<Pin))          //to check a bit if it is 1 then change it to 0 and if it is 0 then change it to 1.
#define GetBit(Reg,Pin) (Reg&(1<<Pin))

void Dio_SetPinDirection(unsigned char DDRX, unsigned char Pin,unsigned char Direction){             //determines if port is input or output


  switch (DDRX)
  {
    
       case 'B':
    if (Direction == 1)
    {
      SetBit(DDRB,Pin);       
     
    }
    else{
      ClearBit(DDRB,Pin);       
      
    }
    break;
        case 'C':
    if (Direction == 1)
    {
      SetBit(DDRC,Pin); 
      
    }
    else{
      ClearBit(DDRC,Pin);       
      
    }
    break;
        case 'D':
    if (Direction == 1)
    {
      SetBit(DDRD,Pin);      
      
    }
    else{
      ClearBit(DDRD,Pin);      
      
    }
    break;
}
}
unsigned char Dio_GetPinState(unsigned char Port,unsigned char pin){                     //to output data                        

  int BitValue;
  switch(Port){
    
    case 'B':
    BitValue = GetBit(PORTB,pin);
    break;
    case 'C':
    BitValue = GetBit(PORTC,pin);
    break;
    case 'D':
    BitValue = GetBit(PORTD,pin);
    break;
  }
  return BitValue;
}
void Dio_SetPortDirection(unsigned char PORTX, unsigned char Pin,unsigned char Direction){             //To activate/deactivate pull up resistors
  switch (PORTX)
  {
    
       case 'B':
    if (Direction == 1)
    {
      SetBit(PORTB,Pin);       
     
    }
    else{
      ClearBit(PORTB,Pin);       
      
    }
    break;
        case 'C':
    if (Direction == 1)
    {
      SetBit(PORTC,Pin); 
      
    }
    else{
      ClearBit(PORTC,Pin);       
      
    }
    break;
        case 'D':
    if (Direction == 1)
    {
      SetBit(PORTD,Pin);      
      
    }
    else{
      ClearBit(PORTD,Pin);      
      
    }
    break;
}
}














