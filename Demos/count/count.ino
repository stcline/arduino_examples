int x =0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  x=x+1;
  Serial.print("Working ");
  Serial.println(x);
  delay(1000);

}
