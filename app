#include <avr/io.h>                     //includes the libaries
#include <util/delay.h>
#include "DIO.h"
#include "ADC.h"
#include "UART.h"


int main(){
  
  init();
  int Adc_Reading;               //identifies adc_readings as an integer
  unsigned char buffer[4];       //stores unsigned buffer in 4 places
  while(1)
  {
    potentiometer();
    RedLED();
    Adc_Reading = CHANNEL_ADC(5);     //channel_adc is stored in adc_reading
    itoa(Adc_Reading,buffer,10);
    Uart_SendString(buffer);
    Uart_SendString("\n");             // ("/n") to start in a new line
  }
}

void init(){                   //intializing the data without giving an output
    potentiometer();
    RedLED();
    Serial.begin(9600);         //Initializing the baud rate of the connection
}

void RedLED(void){                      
float switchV;                          //to return the value for the upcoming arguments
  Dio_SetPinDirection('D',3,1);
 
  Dio_SetPinDirection('C',3,0);

  Adc_Init();

  switchV = CHANNEL_ADC(3);             // channel_adc with a list made out of 3 and is put in switchV

  Serial.println(switchV);
  if(switchV>500){                          //When the switch is turned on
    
    Dio_SetPortDirection('D',3,1);           // Turn ON the switch Led
   

  }
    else
    Dio_SetPortDirection('D',3,0);           //Turn OFF the switch Led

    
 
}


void potentiometer(void){                      //potentiometer is put in void so it doesn't have an output
  float res;                                   // res is getting identified as a float
  Dio_SetPinDirection('D',2,1);
  Dio_SetPinDirection('C',2,0);

  Adc_Init();

  res = CHANNEL_ADC(2);               

  Serial.println(res);                      //To measure the resistance of the potentiometer in the serial monitor

  if(res>550){                              //When the Potentiometer is above 550 Ohm
    

    
    Dio_SetPortDirection('D',2,1);         //Turn on the potentiometer led
    //PORTB=0b00000100;
  }
    else
    Dio_SetPortDirection('D',2,0);         //Turn off the potentiometer led
    
 
}




