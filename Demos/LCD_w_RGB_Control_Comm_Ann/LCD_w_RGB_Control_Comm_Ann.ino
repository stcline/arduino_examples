int potPin = A0;
int redPin = 6;
int greenPin = 9;
int bluePin = 10;
int potVal;
int redVal;
int greenVal;
int blueVal;
String colorName;

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.print("PotValue: ");
}

void loop() {
  potVal = analogRead(potPin);

  rgbConvert();
  lcd.setCursor(10, 0);
  lcd.print("     ");
  lcd.setCursor(10, 0);
  lcd.print(potVal);
  lcd.setCursor(0, 1);
  lcd.print("Color:  ");
  lcd.setCursor(7,1);
  lcd.print(colorName);
  
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
    redVal = 0;
    greenVal = 255;
    blueVal = 255;
    colorName = "red   ";
  }

  //orange
  else if (potVal >= 146 && potVal < 292){
    redVal = 0;
    greenVal = 175;
    blueVal = 255;
    colorName = "orange";
  }

  //yellow
  else if (potVal >= 292 && potVal < 438){
    redVal = 0;
    greenVal = 65;
    blueVal = 223;
    colorName = "yellow";
  }

  //green
  else if (potVal >= 438 && potVal < 584){
    redVal = 255;
    greenVal = 0;
    blueVal = 255;
    colorName = "green ";
  }

  //blue
  else if (potVal >= 584 && potVal < 730){
    redVal = 255;
    greenVal = 255;
    blueVal = 0;
    colorName = "blue  ";
  }

  //indigo
  else if (potVal >= 730 && potVal < 876){
    redVal = 153;
    greenVal = 255;
    blueVal = 51;
    colorName = "indigo";
  }

  //violet
  else {
    redVal = 40;
    greenVal = 203;
    blueVal = 133;
    colorName = "violet";
  }
}
