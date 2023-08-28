int blueLED = 6;      // pin for the Blue LED
int redLED = 7;       // pin for the Red LED
int waitTime = 50;  // variable used for intervals between blinks

void setup() {
  pinMode (blueLED, OUTPUT);
  pinMode (redLED, OUTPUT);

}

void loop() {
  digitalWrite (blueLED, HIGH);
  delay (waitTime);
  digitalWrite (blueLED, LOW);
  delay (waitTime);

}
