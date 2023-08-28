int x = 3;
int LED1 = 5;
int LED2 = 4;

void setup() {
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter a number");
}

void loop() {

  if (Serial.available()) {
    x = Serial.read();
    //Serial.println(x);
    if (x == 50) {
      digitalWrite (LED1, HIGH);
      digitalWrite (LED2, LOW);
      delay (2000);
    }
  }

  else {
    digitalWrite (LED1, LOW);
    digitalWrite (LED2, HIGH);
  }

}
