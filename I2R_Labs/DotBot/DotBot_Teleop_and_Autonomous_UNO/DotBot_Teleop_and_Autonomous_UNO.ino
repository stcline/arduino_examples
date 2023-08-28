/*  Arduino UNO R3 side of Dotbot Program
 *  Controls a 2-wheeled robot in both autonomous and teleoperative mode
 *  Chassis of robot is based on DotBot by Michele Maffucci and Ludovico Russo which can be found at: https://www.thingiverse.com/thing:1441937
 *  motor control of L298N based on https://tronixlabs.com.au/news/tutorial-l298n-dual-motor-controller-module-2a-and-arduino/
 *  
 *  Equipment used:
 *    - Arduino UNO R3
 *    - L298N Motor Controller
 *    - ESP8266 12-E Wifi Board
 *    - 5 AA NiMH batteries
 *    - 2 3-6V DC motors
 *    - DotBot Kit
 *    - Wires
 * 
 *  by Steve Cline on 8 August 2018
 */

/*  =========================================
 *              AUTONOMOUS SETUP
 *  =========================================
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

// variable to store distance values
unsigned int Dist;

// set pins for sensor
#define TRIG 11
#define ECHO 12
#define MAX 400

// configure sensor
NewPing sonar(TRIG, ECHO, MAX);

/*  =========================================
 *            TELEOPERATIVE SETUP
 *  =========================================
 */ 

// Variables to store incoming data over Serial
const byte numChars = 10;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// Variables to store motor control values
int stopComm = 0;
int reverseComm = 0;
int fastComm = 0;
int teleop = 0;
boolean newData = false;

/*  =========================================
 *                GENERAL SETUP
 *  =========================================
 */ 

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10; // connect the enA pin on UNO to DC motor 1 on L298N
int in1 = 9;  // connect the in1 pin on UNO to IN1 on L298N
int in2 = 8;  // connect the in2 pin on UNO to IN2 on L298N
// motor two
int enB = 5;  // connect the enB pin on UNO to DC motor 2 on L298N
int in3 = 7;  // connect the in3 pin on UNO to IN3 on L298N
int in4 = 6;  // connect the in4 pin on UNO to IN4 on L298N

void setup() {
  // Set all motor pins to outputs
  pinMode(enA, OUTPUT); //Right Motor
  pinMode(enB, OUTPUT); //Left Motor
  pinMode(in1, OUTPUT); //Right motor direction 
  pinMode(in2, OUTPUT); //Right motor direction
  pinMode(in3, OUTPUT); //Left motor direction
  pinMode(in4, OUTPUT); //Left motor direction
  // pinMode(testPin, OUTPUT); // Use for debugging switches
  // digitalWrite(testPin, LOW);
  
  Serial.begin(115200); 
}

void loop() {
  // Receive the char string, convert to int arrat, print the values
  recvWithStartEndMarkers();  
  if (newData == true){
    convertCharToInt();
    newData = false;
  } 
  
  if (teleop){
    motorControl(); 
  }

  else {
    // Drive forward.
    analogWrite(enA, Speed + 50);
    analogWrite(enB, Speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
    
    Dist = sonar.ping_cm();
    if (Dist <= 20 && Dist != 0){
      TurnSeq();
    }
  }  
}

// Receive the char string
void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

// Convert chars to ints
void convertCharToInt (){
  stopComm = receivedChars[0];
  reverseComm = receivedChars[1];
  fastComm = receivedChars[2];
  rMotor = ((int)receivedChars[3]);
  lMotor = ((int)receivedChars[4]);
  teleop = ((int)receivedChars[5]);   
}

// Calculate the motor controls
void motorControl(){
  if (stopComm == 1){
     analogWrite (enA, 0);
     analogWrite (enB, 0);    
  }

  if (fastComm == 1){
    if (reverseComm){
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      analogWrite (enA, (rMotor * 2.5));
      analogWrite (enB, (lMotor * 2.5));
    }
    else {
      digitalWrite (in1, LOW);
      digitalWrite (in2, HIGH);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
      analogWrite (enA, (rMotor * 2.5));
      analogWrite (enB, (lMotor * 2.5));
    }
  }

  else {
    if (reverseComm){
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      analogWrite (enA, (rMotor * 1.5));
      analogWrite (enB, (lMotor * 1.5));
    }
    else {
      digitalWrite (in1, LOW);
      digitalWrite (in2, HIGH);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
      analogWrite (enA, (rMotor * 1.5));
      analogWrite (enB, (lMotor * 1.5));
    }  
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
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(turn);

  // Forward again.
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
