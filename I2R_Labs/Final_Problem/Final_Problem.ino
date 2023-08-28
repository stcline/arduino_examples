int LED1 = 7;
int LED2 = 6;

void setup() {
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);

  for (int i = 0; i < 4; i++){
    digitalWrite (LED1, HIGH);
    delay (1000);
    digitalWrite (LED1, LOW);
    delay (1000);
  }

  for (int x = 0; x < 255; x++){
    analogWrite (LED2, x);
    delay (8);
  }

  digitalWrite (LED2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
