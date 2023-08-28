int rSpeed = 6;
int lSpeed = 3;
int dir1R = 7;
int dir2R = 8;
int dir1L = 2;
int dir2L = 5;

void setup() {

  pinMode (rSpeed, OUTPUT);
  pinMode (lSpeed, OUTPUT);
  pinMode (dir1R, OUTPUT);
  pinMode (dir2R, OUTPUT);
  pinMode (dir1L, OUTPUT);
  pinMode (dir2L, OUTPUT);

  // direction controls
  digitalWrite(dir1R, HIGH);
  digitalWrite(dir2R, LOW);
  digitalWrite(dir1L, HIGH);
  digitalWrite(dir2L, LOW);

  // speed controls
  analogWrite(rSpeed, 255);
  analogWrite(lSpeed, 255);

  delay(3000);

  analogWrite(rSpeed, 0);
  analogWrite(lSpeed, 0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
