//make a 2´ by 2´ square by moving the robot
int enA = 10;
int enB = 5;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int speed1 = 150;
int speed2 = 160;
int straight=1500;
int turn=470;

void setup() {
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  
  //move forward
  delay(3000);
  analogWrite(enA, speed1);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed2);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(straight);
  
  //turn
  analogWrite(enA, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(turn);
  
  //move forward
  analogWrite(enA, speed1);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed2);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(straight);
  
  //turn
  analogWrite(enA, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(turn);
  
  //move forward
  analogWrite(enA, speed1);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed2);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(straight);
  
  //turn
  analogWrite(enA, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(turn);
  
  //move forward
  analogWrite(enA, speed1);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed2);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(straight);
  
  //turn
  analogWrite(enA, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(turn);
  
  //stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}

void loop() {
  

}
