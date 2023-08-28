int LEDs [] = {2, 3, 4, 5, 6};
int x;
int y;
int z;
int Cycles = 3;

void setup() {
  for (x = 0; x < 5; x++){
    pinMode (LEDs[x], OUTPUT);
  }
  for (x = 0; x < Cycles; x++){
    for (z = 0; z < 5; z++){
       cycleLEDs(z);
    }
  }
}

void loop() {
}

void cycleLEDs (int y){
  digitalWrite (LEDs[y], HIGH);
  delay (400);
  digitalWrite (LEDs[y], LOW);
}
