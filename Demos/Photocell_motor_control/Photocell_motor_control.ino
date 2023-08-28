/* This simple sketch is designe to demonstrate the three parts of a robotic system (sensing, decisions and actuation)

Wire up a DC motor to pin 5 using a motor controller and a power source.
Wire a photoresistor in a voltage divider circuit and a 1000 Ohm resistor.

*/

int val; 
int senPin = A0;
int ENA = 5;
int IN1 = 6;
int IN2 = 7;

void setup() {
  pinMode (senPin, INPUT);
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  
  Serial.begin(9600);  
}

void loop() {
  val = (analogRead(senPin)/2);
  
  if (val > 255){
    val = 255;
  }
  
  analogWrite(ENA, (val));
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  Serial.println(val);
  
    
}
