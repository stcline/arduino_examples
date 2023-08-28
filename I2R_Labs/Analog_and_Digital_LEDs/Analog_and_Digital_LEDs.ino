int DigitalPin = 7;
int AnalogPin = 6;
int i;

void setup() {

  pinMode(DigitalPin, OUTPUT);
  pinMode(AnalogPin, OUTPUT);
  
}

void loop() {

  digitalWrite (DigitalPin, HIGH);

  for (i = 0; i < 255; i++) {
    analogWrite (AnalogPin, i);
    delay (5);
  }

  digitalWrite (DigitalPin, LOW);

  for (i = 255; i > 0; i--){
    analogWrite (AnalogPin, i);
    delay (5);
  }
  
}
