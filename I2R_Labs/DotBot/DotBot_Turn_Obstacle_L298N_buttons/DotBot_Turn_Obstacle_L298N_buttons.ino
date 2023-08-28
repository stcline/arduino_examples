/* Sketch drives DotBot to autonomously avoid obstacles using the HC-SR04 Ultrasonic Sensor
 *  This part of the code is for a larger project utilizing wifi control and the Blynk app
 *  motor control based on https://tronixlabs.com.au/news/tutorial-l298n-dual-motor-controller-module-2a-and-arduino/
 *  
 *  by Steve Cline on 8 August 2018
 */

#include <NewPing.h> // Library for ultrasonic sensor

// Variables to store motor control values
int rMotor = 0;
int lMotor = 0;

// Variables for motor behavior
int x = 0;
int drive = 500;
int turn = 500;
int wait = 1000;
int Speed = 150;
int dif = 0; // difference in motor speeds

// Variables for the button

const int buttonPin = 2;      // the number of the pushbutton pin
const int ledPin = 4;         // the number of the LED pin
int buttonState = 0;          // variable for reading the pushbutton status
int stopState = 0;            // variable for storine the stop state

// variable to store distance values
unsigned int Dist;

// set pins for sensor
#define TRIG 11
#define ECHO 12
#define MAX 400

// configure sensor
NewPing sonar(TRIG, ECHO, MAX);

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10; // connect the enA pin on UNO to DC motor 1 on L298N
int in1 = 9;  // connect the in1 pin on UNO to IN1 on L298N
int in2 = 8;  // connect the in2 pin on UNO to IN2 on L298N
// motor two
int enB = 5;  // connect the enB pin on UNO to DC motor 2 on L298N
int in3 = 7;  // connect the in3 pin on UNO to IN3 on L298N
int in4 = 6;  // connect the in4 pin on UNO to IN4 on L298N

// Pins for the LEDs and Piezo buzzer


void setup() {
  // Set all motor pins to outputs
  pinMode(enA, OUTPUT); //Right Motor
  pinMode(enB, OUTPUT); //Left Motor
  pinMode(in1, OUTPUT); //Right motor direction 
  pinMode(in2, OUTPUT); //Right motor direction
  pinMode(in3, OUTPUT); //Left motor direction
  pinMode(in4, OUTPUT); //Left motor direction

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  // pinMode(testPin, OUTPUT); // Use for debugging switches
  // digitalWrite(testPin, LOW);
  
  Serial.begin(115200);

  // Stop both motors.
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay (5000); // wait 5 seconds to start

  // Drive forward.
  analogWrite(enA, Speed + dif);
  analogWrite(enB, Speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
}

void loop() {

  buttonState = digitalRead(buttonPin);
  Dist = sonar.ping_cm();

  if (buttonState  == HIGH){
    digitalWrite (ledPin, HIGH);
    buttonRead();
    delay(500);
  }

  if (stopState == HIGH){
    stopSeq();
  }

  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(ledPin, HIGH);
  }

  if (Dist <= 10 && Dist != 0){
    TurnSeq();
  }
}

void buttonRead(){

  if (stopState == HIGH){
    stopState = 0;
  }

  else {
    stopState = HIGH;
  }
}

void TurnSeq(){

  turn = rand() % 500 + 1000;

  // Stop both motors.
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay (wait);

  // Turn back and right.
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(turn);

  // Forward again.
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopSeq(){
  // Stop both motors.
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite (ledPin, LOW);
  delay (wait);
  
}

