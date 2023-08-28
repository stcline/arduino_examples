int potPin = A0;
int ledPin = 6;
int potVal;
int ledVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  ledVal = (0.25 * potVal);
  Serial.print ("potVal = ");
  Serial.print (potVal);
  Serial.print (" ledVal = ");
  Serial.println(ledVal);
  analogWrite(ledPin, ledVal);
  
}
