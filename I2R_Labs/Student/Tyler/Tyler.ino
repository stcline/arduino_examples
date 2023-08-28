void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
}

// the loop function runs over an- over again forever
void loop() {
  digitalWrite(7, HIGH);  // turn the LED on (HIGH)
  delay(2000);                      // wait for a second
  digitalWrite(7, LOW);   // turn the LED off my making the voltage level LOW
  delay(2000);                      // wait for a second

}
