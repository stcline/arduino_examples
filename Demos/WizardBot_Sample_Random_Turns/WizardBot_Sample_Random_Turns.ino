/* WizardBot Sample Random Turns
 *  made 2 February 2019 by Steve Cline
 *  
 *  Sketch utilizes the WizardBot mobile robot to demonstrate the differential
 *  turning system of the robot.   
 *  Wiring schematic may be found here: https://bit.ly/2G6AeaL
 */

// variables to control motors
int speedLeft = 9;
int speedRight = 10;
int directionL1 = 3;
int directionL2 = 4;
int directionR1 = 5;
int directionR2 = 6;

// variable for a random delay
int randomDelay;

// speed for each side - adjust to drive straight
int speedValR = 255;
int speedValL = 255;

// variable to store turn choice
int turnChoice;

void setup() {
  // declare all pins as outputs
  pinMode (speedLeft, OUTPUT);
  pinMode (speedRight, OUTPUT);
  pinMode (directionL1, OUTPUT);
  pinMode (directionL2, OUTPUT);
  pinMode (directionR1, OUTPUT);
  pinMode (directionR2, OUTPUT);

  // set speed for each motor
  analogWrite (speedLeft, speedValL);
  analogWrite (speedRight, speedValR);

  Serial.begin(9600);
}

void loop() {
  // drive straight for a random amount of time
  driveStraight ();

  // turn for a random amount of time
  turnSeq();
}

void driveStraight (){
  randomDelay = random(500, 1000);
  
  digitalWrite (directionL1, HIGH);
  digitalWrite (directionL2, LOW);
  digitalWrite (directionR1, HIGH);
  digitalWrite (directionR2, LOW);
  
  delay (randomDelay);
}

void turnSeq(){
  randomDelay = random(1000, 3000);
  turnChoice = random(0, 2);
  Serial.print(turnChoice);
  
  if (turnChoice == 0){
    digitalWrite (directionL1, LOW);
    Serial.println("   left");
  }

  else {
    digitalWrite (directionR1, LOW);
    Serial.println("   right");
  }

  delay (randomDelay);
}

