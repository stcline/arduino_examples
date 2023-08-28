#include "FastLED.h"
#define NUM_LEDS 300
CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS); 
  leds[2] = CRGB::Red; 
  FastLED.show(); 
}
void loop() {
  

}
