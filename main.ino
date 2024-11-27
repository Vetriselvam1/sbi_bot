
void moment(){ 
  
 if(ch2>1520){
   Serial.println("for");
    int Speed=map(ch2,1520 ,1820,100,200);
    motor1.setSpeed(Speed);   // Motor 1 runs forward at 50% speed.
    motor2.setSpeed(Speed);  // Motor 2 runs backward at 50% speed.
   
  }
  else if (ch2 < 1250) {
    Serial.println("back");
    int SpeedR = map(ch2, 1350, 1134, 120, 180); // Map the input value to speed range
      motor1.setSpeed(-SpeedR);   // Motor 1 runs forward at 50% speed.
      motor2.setSpeed(-SpeedR);  // Motor 2 runs backward at 50% speed.
}

  else if(ch4>1550){
    Serial.println("right");
    right();
  }
  else if(ch4<1350){
    Serial.println("left");
    left();
  }
  else{
    Serial.println("stop");
    Stop();
  }
}


void right(){
  motor1.setSpeed(-120);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(120);  // Motor 2 runs backward at 50% speed.
  }
void left(){
  motor1.setSpeed(120);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(-120);  // Motor 2 runs backward at 50% speed.
}
void Stop(){
  motor1.setSpeed(0);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(0);  // Motor 2 runs backward at 50% speed.

}
