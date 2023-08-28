int redPin = 9;
int bluePin = 10;

void setup() {

  Serial.begin (115200);

  pinMode (redPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  
}

void loop() {

   for (int i = 0; i <= 255; i = i + 1){

    Serial.print ("Red: ");
    Serial.print (i);
    Serial.print ("    Blue: ");
    Serial.println (255-i);
    analogWrite (redPin, i);
    analogWrite (bluePin, 255-i);
    delay (5);
    
  }

  for (int i = 255; i >= 0; i = i - 1){

    Serial.print ("Red: ");
    Serial.print (i);
    Serial.print ("    Blue: ");
    Serial.println (255-i);
    analogWrite (redPin, i);
    analogWrite (bluePin, 255-i);
    delay (5);
    
  }

}
