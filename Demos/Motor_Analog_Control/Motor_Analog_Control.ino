int speedPin = 6;
int dirPin1 = 7;
int dirPin2 = 8;

void setup() {

  Serial.begin (9600);

  pinMode (speedPin, OUTPUT);
  pinMode (dirPin1, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  
  digitalWrite (dirPin1, LOW);
  digitalWrite (dirPin2, HIGH);
  
  for (int i = 0; i <= 255; i = i + 1){

    Serial.println(i);
    analogWrite (speedPin, i);
    delay (10);
    
  }
  
}

void loop() {

}
