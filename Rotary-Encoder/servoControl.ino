/*
  Rotary encoder basic

  Control the movement of servo with rotary encoder and builtin led with push button

  modified 15 October 2023
  by Utpal Kumar
*/
#include <Servo.h>

int currentCLKstate, DTstate, lastCLKstate = digitalRead(6), counter=0;
Servo servo1; // making a servo object

void setup() {
  //pin declaration
  pinMode(10, INPUT_PULLUP);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); //Starting serial communication
  servo1.attach(11); // Attaching the servo to pin 11
  servo1.write(0); // Setting the servo to 0 degrees
}

void loop() {
  currentCLKstate = digitalRead(6);
  DTstate = digitalRead(7);
  
  //Servo control
  if(currentCLKstate != lastCLKstate){
    if(currentCLKstate == DTstate && counter<180){
      counter++;
    }else if(counter>0) counter--;

    lastCLKstate = currentCLKstate;
    servo1.write(counter);
  }
  //LED control
  if(digitalRead(10) == LOW){
      digitalWrite(LED_BUILTIN, HIGH);
  }else digitalWrite(LED_BUILTIN, LOW);
}
