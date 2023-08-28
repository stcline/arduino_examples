int blueLED = 10;              // pin for the blue LED
int redLED = 9;               // pin for the red LED
int waitTime = 500;   // variable used for intervals between blinks

void setup() {
  pinMode (blueLED, OUTPUT);
  pinMode (redLED, OUTPUT); 

    for (int i = 1; i <= 3 ; i++) {
    digitalWrite (redLED, HIGH);
    delay (waitTime);
    digitalWrite (redLED, LOW);
    delay (waitTime); 
  }

  for (int i = 0; i <= 255; i++){
    analogWrite (blueLED, i);
    delay (12);
  }

  for (int i = 255; i >= 0; i--){
    analogWrite (blueLED, i);
    delay (12);   
  }

}

void loop() {

}
