
int N3 = 8;
int N4 = 7;
int s = 6  ;

void setup() {
  
  pinMode(N3, OUTPUT);
  pinMode (N4, OUTPUT);
  pinMode (s , OUTPUT);

}

void loop() {
  
  digitalWrite(N4,HIGH);
  digitalWrite(N3,LOW);
  analogWrite(s,255);
  delay(2000);
  digitalWrite(N4,LOW);
  digitalWrite(N3,HIGH);
  analogWrite(s,255);
  delay(2000);

}
