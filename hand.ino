#include <Servo.h>
#define CH5 10
#define CH6 11
char receivedCommand;
Servo lefthand; 
Servo righthand; 
Servo head; 
int buttonpinhand=3; 
int pos;      
unsigned int ch5=0,ch6=0;           
void hand_shaking();
void setup() 
{
  Serial.begin(9600);
  pinMode(buttonpinhand,INPUT);
  pinMode(2,OUTPUT);
    pinMode(CH5,INPUT);
  pinMode(CH6,INPUT);
   head.attach(9);
   lefthand.attach(5);
   righthand.attach(6);
}
void Check_Channel()
{
  ch6 =pulseIn(CH6,HIGH);
  ch5 = pulseIn(CH5,HIGH);
  
  Serial.print("   CH5:");Serial.print(ch5);
  Serial.print("   CH6:");Serial.println(ch6);
}

//==================================main function===========================================
void loop()  
{
int buttonstate =digitalRead(buttonpinhand);
   if(buttonstate==LOW)
  {
    digitalWrite(2,HIGH);
    hand_shaking();
    lefthand.write(0);
    head.write(90);
    
  }
  else
  {    
    Serial.println("off22");
  pinMode(buttonpinhand,INPUT_PULLUP);
  digitalWrite(2,LOW);
    Check_Channel();
    moment();
  
  }   
}
