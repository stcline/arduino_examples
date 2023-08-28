/* Created by Steve Cline on 3 Februaary 2019
 *  This sketch test the motor direction and speed for the DFRobot Baron 4WD robot.
 *  Attached additional equipment includes:
 *    Arduino UNO R3
 *    AdaFruit MotorShield V2.3
 *    Battery pack with 8 AA NiMH cells attached to the motor shield
 *    Battary pack with 5 AA NiMH cells attached to the microcontroller
 *    4 DC 130 motors  
 */

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4
Adafruit_DCMotor *LF = AFMS.getMotor(1);
Adafruit_DCMotor *RF = AFMS.getMotor(2);
Adafruit_DCMotor *LR = AFMS.getMotor(3);
Adafruit_DCMotor *RR = AFMS.getMotor(4);

// SET UP VARIABLES
// general variables for settings on the 
int x;

int Speed = 150;
int feetOfTravel = 1;
int delayPerFoot = 1000;      // modify this variable as you test distance calculations 
int turnDelay = 1000;         // modify this variable to change turn duration

void setup() {
  
  AFMS.begin();     // create with the default frequency 1.6KHz

  LF->setSpeed(Speed);
  LR->setSpeed(Speed);
  RR->setSpeed(Speed);
  RF->setSpeed(Speed);

  LF->run(RELEASE);
  LR->run(RELEASE);
  RR->run(RELEASE);
  RF->run(RELEASE);

  delay(5000);                    //Wait 5 seconds to set the robot on the course

  // drive forward
  LF->run(FORWARD);
  LR->run(FORWARD);
  RR->run(FORWARD);
  RF->run(FORWARD);

  delay (feetOfTravel * delayPerFoot);

  LF->run(RELEASE);
  LR->run(RELEASE);
  RR->run(RELEASE);
  RF->run(RELEASE);

}

void loop() {

}
