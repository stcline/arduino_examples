int LEDpin = 0;

void setup() {
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  digitalWrite(LEDpin, HIGH);
  delay(1000);
  digitalWrite(LEDpin, LOW);
  delay(1000);
}
