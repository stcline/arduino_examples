#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *M = AFMS.getMotor(1);
Adafruit_DCMotor *M2 = AFMS.getMotor(2);
Adafruit_DCMotor *M3 = AFMS.getMotor(3);
Adafruit_DCMotor *M4 = AFMS.getMotor(4);

int LEncoder = 3;
int REncoder = 2;
int currentLeft = 0;
int currentRight = 0;
int pastRight = 0;
int pastLeft = 0;
int LCount = 0;
int RCount = 0;
int drive = 0;
;

void setup() {
AFMS.begin();
Serial.begin(9600);
pinMode(LEncoder, INPUT);
pinMode(REncoder, INPUT);

delay(3000);

LCount = 0;
RCount = 0;

while (LCount <= 40 && RCount <= 40){

  M->run(BACKWARD);
  M2->run(BACKWARD);
  M3->run(BACKWARD);
  M4->run(BACKWARD);
  
  M->setSpeed(100);
  M2->setSpeed(100);
  M3->setSpeed(100);
  M4->setSpeed(100);


  currentLeft = digitalRead(LEncoder);
  currentRight = digitalRead(REncoder);

  if (pastLeft == 0 && currentLeft == 1){
    pastLeft = 1; // was previously pastRight
    LCount = LCount+1;
  }

  else if (pastRight == 0 && currentRight == 1){
    pastRight = 1;
    RCount = RCount+1;
  }
  
  else if (pastLeft == 1 && currentLeft == 0){
    pastLeft = 0;
  }
  
  else if (pastLeft == 1 && currentLeft == 0){
    pastLeft = 0;
  }

  Serial.print("Left");
  Serial.print(":");
  Serial.print(LCount);
  Serial.print("   ");
  Serial.print("Right");
  Serial.print(":");
  Serial.println(RCount);
}

M->setSpeed(0);
M2->setSpeed(0);
M3->setSpeed(0);
M4->setSpeed(0);

}

void loop() {




}
