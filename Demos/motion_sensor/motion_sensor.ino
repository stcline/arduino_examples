int redPin = 7;
int whitePin = 6;
int pirPin = 5;
int pirState = LOW;
int val = 0;

void setup (){
  pinMode (redPin, OUTPUT);
  pinMode (whitePin, OUTPUT);
  pinMode (pirPin, INPUT); 

  Serial.begin (9600);
}

void loop (){
  val = digitalRead(pirPin);
  while (val == HIGH){
    digitalWrite (redPin, HIGH);
    digitalWrite (whitePin, LOW);
    Serial.println ("  Intruder!");
    val = digitalRead (pirPin);
  }
  digitalWrite(redPin, LOW);
  digitalWrite (whitePin, HIGH);
  Serial.println("  All Clear!");
}
