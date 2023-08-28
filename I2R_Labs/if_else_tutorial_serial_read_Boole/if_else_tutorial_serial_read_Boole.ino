/*  Sketch by Steve Cline on 11-13-18
 *  This uses two LEDs and the serial monitor as a tool for understanding
 *  bigger and better things.  One day, you will use concepts like these to
 *  make real robots listen to your commands. * 
 */

int a = 51;
int LED1 = 4;
int LED2 = 5;

void setup() {
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // turn off both LEDs
  digitalWrite (LED1, LOW);
  digitalWrite (LED2, LOW);
  delay(500); // wait 500 milliseconds until prompting for a new value
  Serial.println("The variable a is equal to 3.  Enter a value for b.");

  // check to see if any communication is being received
  if (Serial.available()) {
    int b = Serial.read();
    
    if (a == 51 && b == 51) {
      // display this message in the serial monitor
      Serial.print ("They are both equal to 3.");
      for (int i = 0; i < 3; i++) {
        // blink the green LED three times
        digitalWrite (LED1, HIGH);
        delay (200);
        digitalWrite (LED1, LOW);
        delay (200);
      }
    }

    else {
      // display this message in the serial monitor
      Serial.print ("They are both NOT equal to 3.");
      for (int i = 0; i < 3; i++) {
        // blink the red LED three times
        digitalWrite (LED2, HIGH);
        delay (200);
        digitalWrite (LED2, LOW);
        delay (200);
      }
    }
  }
}
