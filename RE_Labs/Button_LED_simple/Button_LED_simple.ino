int buttonPin = 3;
int buttonState = 0;
int ledPin = 6;

void setup() {
  pinMode (buttonPin, INPUT);
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite (ledPin, HIGH);
    Serial.println("ON");
  }
  else {
    digitalWrite (ledPin, LOW);
    Serial.println("OFF");  
  }

}
