int potPin = A0;
int redPin = 6;
int greenPin = 9;
int bluePin = 11;
int potVal;
int redVal;
int greenVal;
int blueVal;
String colorName;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);

  rgbConvert();
  Serial.print ("potVal = ");
  Serial.print (potVal);
  Serial.print (" redVal = ");
  Serial.print(redVal);
  Serial.print (" greenVal = ");
  Serial.print(greenVal);
  Serial.print (" blueVal = ");
  Serial.print(blueVal);
  Serial.print(" Color:");
  Serial.println(colorName);
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
  
}

void rgbConvert(){
  
  //red
  if (potVal < 146){
    redVal = 255;
    greenVal = 0;
    blueVal = 0;
    colorName = "red";
  }

  //orange
  else if (potVal >= 146 && potVal < 292){
    redVal = 255;
    greenVal = 80;
    blueVal = 0;
    colorName = "orange";
  }

  //yellow
  else if (potVal >= 292 && potVal < 438){
    redVal = 255;
    greenVal = 160;
    blueVal = 0;
    colorName = "yellow";
  }

  //green
  else if (potVal >= 438 && potVal < 584){
    redVal = 0;
    greenVal = 153;
    blueVal = 0;
    colorName = "green";
  }

  //blue
  else if (potVal >= 584 && potVal < 730){
    redVal = 0;
    greenVal = 0;
    blueVal = 255;
    colorName = "blue";
  }

  //indigo
  else if (potVal >= 730 && potVal < 876){
    redVal = 102;
    greenVal = 0;
    blueVal = 204;
    colorName = "indigo";
  }

  //violet
  else {
    redVal = 255;
    greenVal = 0;
    blueVal = 127;
    colorName = "violet";
  }
}
