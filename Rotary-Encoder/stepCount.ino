/*
  Rotary encoder basic

  Count the number of steps rotary encoder is turned by in a direction and control the builtin led with push button

  modified 15 October 2023
  by Utpal Kumar
*/
int currentCLKstate, DTstate, lastCLKstate = digitalRead(6), counter=0;

void setup() {
  //pin declaration
  pinMode(10, INPUT_PULLUP);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); //Starting serial communication
}

void loop() {
  currentCLKstate = digitalRead(6);
  DTstate = digitalRead(7);

  if(currentCLKstate != lastCLKstate){
    if(currentCLKstate != DTstate){
      counter++;
    }else counter--;

    lastCLKstate = currentCLKstate;
    Serial.println(counter);
  }

  if(digitalRead(10) == LOW){
      digitalWrite(LED_BUILTIN, HIGH);
  }else digitalWrite(LED_BUILTIN, LOW);
}
