int photoPin = A0;
int ledPin = 6;
int photoVal;
int ledVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  photoVal = analogRead(photoPin);
  ledVal = (0.25 * -photoVal) + 254;
  Serial.print ("photVal = ");
  Serial.print (photoVal);
  Serial.print (" ledVal = ");
  Serial.println(ledVal);
  analogWrite(ledPin, ledVal);
  
}
