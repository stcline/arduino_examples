int greenLED = 4;
int redLED = 5;
int blueOnTime = 250;
int blueOffTime = 250;
int greenOnTime = 250;
int greenOffTime = 250;
int numBlueBlinks = 5;
int numGreenBlinks = 5;
String blueMessage = "The red LED is Blinking";
String greenMessage = "The green LED is Blinking";

void setup () {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop () {
  for (int i = 0; i < numBlueBlinks; i++) {
    digitalWrite (redLED, HIGH);
    Serial.println(blueMessage);
    delay (blueOnTime);
    digitalWrite (redLED, LOW);
    delay (blueOffTime);
  }

  for (int i = 0; i < numGreenBlinks; i++) {
    digitalWrite (greenLED, HIGH);
    Serial.println(greenMessage);
    delay (greenOnTime);
    digitalWrite (greenLED, LOW);
    delay (greenOffTime);
  }
}

