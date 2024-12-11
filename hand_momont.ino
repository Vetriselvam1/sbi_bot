void head_moment() {
  for (pos = 45; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree // tell servo to go to position in variable 'pos'
    head.write(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 135; pos >= 45; pos -= 1) { // goes from 180 degrees to 0 degrees
    head.write(pos);            // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
void moment(){ 
  
 if(ch5>1520){
   Serial.println("righthand");
    lefthand.write(90);
    righthand.write(165);  

   
  }
  else if (ch5 < 1250) {
    Serial.println("left");
       lefthand.write(15);
    righthand.write(90);   
 }
 else if ((ch5 > 1270) && (ch5 < 1480)){
   righthand.write(90);
   lefthand.write(90); 
 }

  else if(ch6>1000){
    Serial.println("head home");
    head.write(90);
  }
  else if(ch6<1000){
    Serial.println("head move");
    head_moment();
  }
  else{
    Serial.println("stop");
        lefthand.write(90);
    righthand.write(90);
    head.write(90);
  }
  // Variable to store the received command

}
void hand_shaking() {
  // Check if data is available to read from the Serial
  if (Serial.available() > 0) {
    // Read the incoming command
    receivedCommand = Serial.read();
    Serial.print("Received command: ");
    Serial.println(receivedCommand);

    // Handle the received command
    if (receivedCommand == 'f') {
      // Move the servo to the active position
      righthand.write(165);
      delay(300);
      righthand.write(175);
      delay(300);
      righthand.write(165);
      delay(300);
      righthand.write(175);
      delay(300);
      righthand.write(165);
      delay(300);     
      righthand.write(90);
      Serial.println("Servo moved to active position");
    } 
    else if (receivedCommand == 'h') {
      // Move the servo back to the home position
      righthand.write(90);
      Serial.println("Servo moved to home position");
    }
    else{
      righthand.write(90);
      Serial.println("Servo moved to home position");
    }
  }
}
