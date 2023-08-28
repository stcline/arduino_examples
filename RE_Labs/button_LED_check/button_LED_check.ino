int LEDgreen = 12;
int pot = A5;

void setup() {

pinMode (pot, INPUT);
pinMode (LEDgreen, OUTPUT);
Serial.begin (9600);

}

void loop() {
  Serial.println(analogRead(pot));

  if (analogRead(pot)>500) {
    digitalWrite (LEDgreen, HIGH);
  }

  else {
    digitalWrite (LEDgreen, LOW);
  }

}
