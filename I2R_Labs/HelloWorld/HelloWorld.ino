String Letter="";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Waiting for your key:");
}

void loop() {
  // put your main code here, to run repeatedly:
Letter = Serial.read();
Serial.println(Letter);
}
