int blueLEDPin = 8;
int yellowLEDPin = 7;
int blueOnTime = 250;
int blueOffTime = 250;
int yellowOnTime = 250;
int yellowOffTime = 250;
int numYellowBlinks = 5;
int numBlueBlinks = 5;
String blueMessage="The Blue Led is Blinking";
String yellowMessage="The Yellow LED is Blinking";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(blueLEDPin, OUTPUT);
pinMode(yellowLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int x=0; x <= 5; x++){  
  digitalWrite(blueLEDPin, HIGH);
  Serial.println(blueMessage);
  delay(blueOnTime);
  digitalWrite,(blueLEDPin, LOW);
  delay(blueOffTime);

}
for(int x=0; x <= 5; x++){  
  digitalWrite(yellowLEDPin, HIGH);
  Serial.println(yellowMessage);
  delay(yellowOnTime);
  digitalWrite,(yellowLEDPin, LOW);
  delay(yellowOffTime);
}
}
\
