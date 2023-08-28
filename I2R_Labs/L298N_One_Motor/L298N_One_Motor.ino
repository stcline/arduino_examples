int ENA = 5;
int IN1 = 6;
int IN2 = 7;

void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
}

void loop() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 250);
  delay (2500);
  digitalWrite (IN1, LOW);
  delay (2500);
}
