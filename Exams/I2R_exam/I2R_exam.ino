/*Basic sketch to demonstrate understanding of digitalWrite and analogWrite
 * 
 * Uses an Arduino controller
 * 2-LEDs
 * 2-220 Ohm resistors
 * by Steve Cline on 21 October 2018
 */

int blueLED = 6;
int redLED = 7;
int waitTime = 250;
int blinkS = 4;

void setup() {
  pinMode (blueLED, OUTPUT);
  pinMode (redLED, OUTPUT);

  for (int i = 0; i < blinkS; i++){
    digitalWrite (redLED, HIGH);
    delay (waitTime);
    digitalWrite (redLED, LOW);
    delay (waitTime);
  }

  for (int x = 0; x <= 255; x++){
    analogWrite (blueLED, x);
    delay (6);
  }

  for (int x = 255; x >= 0; x--){
    analogWrite (blueLED, x);
    delay (6);
  }
}

void loop() {

}
