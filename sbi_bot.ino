

#include "CytronMotorDriver.h"

#define CH1 6
#define CH2 7
#define CH3 8
#define CH4 9


// Configure the motor driver.
CytronMD motor1(PWM_DIR, 2,22 );  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 3, 23); // PWM 2 = Pin 9, DIR 2 = Pin 10.

int buttonpinrc=4;                  

//-----------------------Channel Variables-----------------------------------------
unsigned int ch4=0,ch2=0,ch3=0,ch1=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(buttonpinrc,INPUT);
  
  pinMode(CH4,INPUT);
  pinMode(CH2,INPUT);
  pinMode(CH3,INPUT);
  pinMode(CH1,INPUT);
}


//==================================main function===========================================
void loop()  
{
int buttonstate =digitalRead(buttonpinrc);
   if(buttonstate==LOW)
  {
    Serial.println("rc mode");
    Check_Channel();
      if (ch1 != 0 && ch2 != 0 && ch3 != 0 && ch4 != 0){
        moment(); 
      }
      else{
        Serial.println("stopline");
        Stop();
      }
  }
  else
  {    
    Serial.println("off22");
  pinMode(buttonpinrc,INPUT_PULLUP);
  
  }   
}
