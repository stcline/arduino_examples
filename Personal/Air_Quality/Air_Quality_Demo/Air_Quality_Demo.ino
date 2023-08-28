int sensorAnalog = A0;
int sensorDigital = 8;
int sensorVal = 0;

void setup() {

  pinMode(sensorAnalog, INPUT);
  Serial.begin(9600);

}

void loop() {
  sensorVal = analogRead(sensorAnalog);
  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);
  delay(1000);

}
