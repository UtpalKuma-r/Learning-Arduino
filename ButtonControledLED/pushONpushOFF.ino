/*
  Push button controled LED

  Turn on led when push button is pressed, turn it off when it is pressed again

  Modified 15 October 2023
  by Utpal Kumar
*/

bool LED_state = 0;
bool button_state = 0;

void setup() {
  // pin declaration
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); //LED_BUILTIN point to the pin connected to builtin led on the board (13 in case of Arduino UNO)
}

void loop() {

  // reading the state of input pin and setting the output accordingly.
  if(digitalRead(8) == HIGH && !button_state){
    button_state=1;
    if(!LED_state){
      digitalWrite(LED_BUILTIN, HIGH);
      LED_state = 1;
    } else {
    digitalWrite(LED_BUILTIN, LOW);
    LED_state = 0;
    }  
  }
  else if(digitalRead(8) == LOW) button_state = 0;
}
