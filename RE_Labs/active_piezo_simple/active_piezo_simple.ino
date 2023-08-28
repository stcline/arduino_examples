const int buzPIN = 9;

void setup() {
  pinMode(buzPIN, OUTPUT);
  tone(buzPIN, 100);
  delay(200);
  noTone(buzPIN);
}

void loop() {

}
