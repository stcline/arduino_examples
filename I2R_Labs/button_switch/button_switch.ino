int buttonPin = 2;         // the number of the input pin
int ledPin = 13;       // the number of the output pin

int state = LOW;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = HIGH;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup(){
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop(){

  buttonRead();

}

void buttonRead(){

  reading = digitalRead(buttonPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }

  digitalWrite(ledPin, state);

  previous = reading;
    
}

