/*
  Push button controled LED

  Turn on led while the button is pressed, turn it of while it is not.

  Modified 15 October 2023
  by Utpal Kumar
*/

void setup() {
  // pin declaration
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); //LED_BUILTIN point to the pin connected to builtin led on the board (13 in case of Arduino UNO)
}

void loop() {
  // reading the state of input pin and setting the output accordingly.
  if(digitalRead(8) == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
