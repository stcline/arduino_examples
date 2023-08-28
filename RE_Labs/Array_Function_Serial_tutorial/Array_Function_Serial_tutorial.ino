int LEDs [] = {2, 3, 4, 5, 6};
int x;
int y;
int z;
int Cycles;

void setup() {
  
  for (x = 0; x < 5; x++){
    pinMode (LEDs[x], OUTPUT);
  }
  
  x = 0;
  
  Serial.begin(9600);
  Serial.print ("Enter any integer from 1 to 10.");

  
  if (Serial.available() > 0) {
    Cycles = Serial.read();
  }

  if (isDigit(Cycles)){
    Serial.print ("Good");
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
