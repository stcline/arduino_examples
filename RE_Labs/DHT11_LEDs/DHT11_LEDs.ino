#include <dht.h>

#define dht_apin A0 // Analog Pin for DHT11
int LEDs[] = {2,3,4,5,6,7,8};
int x;
 
dht DHT;
 
void setup(){
  // set all LED pins to output
  for (x = 0; x < 7; x++){
    pinMode (LEDs[x], OUTPUT);
    digitalWrite (LEDs[x], HIGH);
    delay(500);
    digitalWrite (LEDs[x], LOW);
  }
 
}
 
void loop(){ 
    DHT.read11(dht_apin); //Read the sensor

    if (DHT.temperature <= 19){
      digitalWrite(LEDs[0], HIGH);
    }

    else {
      digitalWrite(LEDs[6], HIGH);
    }
    
    for (x = 0; x<7; x++){
      digitalWrite(LEDs[x], LOW);
    }
    
 
}
