void Check_Channel()
{
  ch4 =pulseIn(CH4,HIGH);
  ch2 = pulseIn(CH2,HIGH);
  ch3 =pulseIn(CH3,HIGH);
  ch1 =pulseIn(CH1,HIGH);
  
  Serial.print("   CH1:");Serial.print(ch1);
  Serial.print("   CH2:");Serial.print(ch2);
  Serial.print("   CH3:");Serial.print(ch3);
  Serial.print("   CH4:");Serial.print(ch4); 
}
