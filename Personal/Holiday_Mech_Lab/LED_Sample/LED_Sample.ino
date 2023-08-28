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

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
  
  leds[x] = CRGB(255, 0, 0);
  FastLED.show();
  delay(100); 
  leds[x+1] = CRGB (0, 255, 0);
  FastLED.show();
  delay(100); 
  x=x+2;
  if (x>299){
    x=0;
    for (int i = 0; i<300; i++){
      leds[i] = CRGB (0, 0, 0);
      FastLED.show();
    }
  }
 
}
