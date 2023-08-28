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

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
  
  xmas_basic();
}

void xmas_basic () {

  randNum = random(299);
  
  leds[randNum] = CRGB(255, 255, 255);
  FastLED.show();
  delay(100); 
  leds[randNum + 1] = CRGB(255, 255, 255);
  FastLED.show();
  delay(100);
  leds[randNum + 2] = CRGB(255, 255, 255);
  FastLED.show();
  delay (100);
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

