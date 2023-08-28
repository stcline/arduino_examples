
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {

  digitalWrite (LED_BUILTIN, HIGH);
  delay(1000);

//  for (i = 0; i < 255; i++) {
//    analogWrite (AnalogPin, i);
//    delay (5);
//  }

  digitalWrite (LED_BUILTIN, LOW);

//  for (i = 255; i > 0; i--){
//    analogWrite (AnalogPin, i);
//    delay (5);
//  }
  
}
