void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop() {
  for (int x = 0; x < 255; x++){
    analogWrite(6,x);
    Serial.println(x);
    delay(10);
  }
}
