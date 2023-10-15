/*
  Joystick

  Print the position of the joystick to serial monitor
  x-position - A1
  y-position - A0
  Switch - 8

  modified 15 October 2023
  by Utpal Kumar
*/
void setup() {
  pinMode(A0, INPUT); //y-position
  pinMode(A1, INPUT); //x-position
  pinMode(8, INPUT); //switch
  Serial.begin(9600); //begin the communication with the serial monitor on baud 9600
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  Serial.println("X-Position: "+(String)analogRead(A1)); //printing the x position of the joystick
  Serial.println("Y-Position: "+(String)analogRead(A0)); //printing the y position of the joystick
  //Serial.println("B-Position: "+(String)digitalRead(8)); // printing the button state on joystick
  if(digitalRead(8) == HIGH) digitalWrite(LED_BUILTIN, HIGH); //controlling inbuilt led with button on joystick
  else digitalWrite(LED_BUILTIN, LOW);
  Serial.println("--------------------------------------------------------------------------------------------------------------------");
}
