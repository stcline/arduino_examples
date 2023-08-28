/*
 * This sketch utilizes the DK ELectronics version of the AdaFruit Motor Shield V1.0
 * Tutorial for this shield may be found at: https://learn.adafruit.com/afmotor-library-reference/af-dcmotor
 * 
 * Created by Steve Cline on 20 May 2018
 */


#include <AFMotor.h>

//Create motor objects
AF_DCMotor left_motor(2, MOTOR12_64KHZ);
AF_DCMotor right_motor(1, MOTOR12_64KHZ);

void setup(){
  // left motor is less powerful on this particular robot
  left_motor.setSpeed(255);
  right_motor.setSpeed(155);  
}

void loop(){

  left_motor.run(FORWARD);
  right_motor.run(FORWARD);
  delay (1000);
  left_motor.run(RELEASE);
  right_motor.run(RELEASE);
  delay(1000);
  
}

