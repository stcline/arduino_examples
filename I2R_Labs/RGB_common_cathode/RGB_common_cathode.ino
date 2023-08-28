int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup() {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);

  analogWrite (redPin, 255);
  analogWrite (greenPin, 0);
  analogWrite (bluePin, 0);
}

void loop() {

}
