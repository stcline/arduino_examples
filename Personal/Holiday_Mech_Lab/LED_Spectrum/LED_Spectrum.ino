/**
 * LED Control
 * Steve Cline made this for the WHS Mechatronics Lab door
 * Displays holiday lights using a Pro Mini and 300 LED string
 * Created 12/5/18
 * Accepts commands from Thing on how to control LEDs.
 */

#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    300

int x = 0;
int randNum;
int redVal;
int greenVal;
int blueVal;
int rgbVal = 0;
String colorName;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin (9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
  
  rgbConvert();
  xmas_basic();
  
  Serial.println(colorName);
  rgbVal = rgbVal + 1;
  if (rgbVal > 6){
    rgbVal = 0;
  }
}

void xmas_basic () {

  randNum = random(299);
  
  leds[randNum] = CRGB(redVal, greenVal, blueVal);
  FastLED.show();
  delay(100);
  leds[randNum + 1] = CRGB(redVal, greenVal, blueVal);
  FastLED.show();
  delay(100);
  leds[randNum + 2] = CRGB(redVal, greenVal, blueVal);
  FastLED.show();
  delay(100);

  leds[randNum] = CRGB(0, 0, 0);
  FastLED.show();
  delay(100); 
  leds[randNum + 1] = CRGB(0, 0, 0);
  FastLED.show();
  delay(100);
  leds[randNum + 2] = CRGB(0, 0, 0);
  FastLED.show();
  delay (100);
  
}

void rgbConvert(){
  
  //red
  if (rgbVal == 0){
    redVal = 255;
    greenVal = 0;
    blueVal = 0;
    colorName = "red";
  }

  //orange
  else if (rgbVal == 1){
    redVal = 255;
    greenVal = 80;
    blueVal = 0;
    colorName = "orange";
  }

  //yellow
  else if (rgbVal == 2){
    redVal = 255;
    greenVal = 160;
    blueVal = 0;
    colorName = "yellow";
  }

  //green
  else if (rgbVal == 3){
    redVal = 0;
    greenVal = 153;
    blueVal = 0;
    colorName = "green";
  }

  //blue
  else if (rgbVal == 4){
    redVal = 0;
    greenVal = 0;
    blueVal = 255;
    colorName = "blue";
  }

  //indigo
  else if (rgbVal == 5){
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

