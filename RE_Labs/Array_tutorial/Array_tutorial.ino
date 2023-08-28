int LEDs [] = {2, 3, 4, 5, 6};
int Times [] = {5, 2, 7, 1, 3};
int x;

void setup() {
  for (x = 0; x < 5; x++){
    pinMode (LEDs[x], OUTPUT);
  }
  x = 0;
}

void loop() {
  for (x = 0; x < 5; x++){
    digitalWrite(LEDs[x], HIGH);
    delay(1000 * Times[x]);
    digitalWrite (LEDs[x], LOW);
  }

}
