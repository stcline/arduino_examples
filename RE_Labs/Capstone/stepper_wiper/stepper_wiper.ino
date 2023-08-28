// Motor pin definitions
#define motorPin1  10      // IN1 on the ULN2003 driver 1
#define motorPin2  11     // IN2 on the ULN2003 driver 1
#define motorPin3  12     // IN3 on the ULN2003 driver 1
#define motorPin4  13     // IN4 on the ULN2003 driver 16

int degreeWipe;
int interval = 3;

void setup() {

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT); 

  Serial.begin(9600);

  Serial.println ("Enter any character to start the wiper.");

  //while (Serial.available() == 0){}

  Serial.print ("Moving the wiper");

  for (int i = 0; i < 128; i++){
    directionOne ();
  }

  for (int i = 0; i <128; i++){
    directionTwo ();
  }

}

void loop() {

}

void directionOne (){
  
  digitalWrite (motorPin1, HIGH);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, LOW);
  delay (interval);

  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, HIGH);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, LOW);
  delay (interval);

  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, HIGH);
  digitalWrite (motorPin4, LOW);
  delay (interval);

  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, HIGH);
  delay (interval);
  
}

void directionTwo (){

  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, HIGH);
  delay (interval);

  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, HIGH);
  digitalWrite (motorPin4, LOW);
  delay (interval);

  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, HIGH);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, LOW);
  delay (interval);

  digitalWrite (motorPin1, HIGH);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, LOW);
  delay (interval);
  
}

