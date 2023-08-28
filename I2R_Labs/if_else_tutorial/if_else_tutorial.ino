int x = 6;
int LED1 = 5;  // This is the red LED
int LED2 = 4;  // This is the green LED

void setup() {
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
}

void loop() {

  if (x == 2) {
    digitalWrite (LED1, HIGH);
    digitalWrite (LED2, LOW);
  }
  

  else {
    digitalWrite (LED1, LOW);
    digitalWrite (LED2, HIGH);
  }

}
