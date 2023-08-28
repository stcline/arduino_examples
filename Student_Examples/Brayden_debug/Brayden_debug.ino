#include < ESP8266WiFi.h >
#include < BlynkSimpleEsp8266.h >

char ssid[] = "mechlab";
 char pass[] = "etufh89959";
 char auth[] = "9ea8b605d88b443ea1d9d1a847703fc";
 char server[] = "192.168.0.140";
 int port = 8080;
 int D1 = 5;
 int pinV0;
 
void setup() {
 WiFi.begin(ssid, pass);
 Blynk.config(auth, server, port,);
 Blynk.connect();

 pinMode (D1, OUTPUT);
 pinMode (pinV0, INPUT);

}

void loop() {
  Blynk.run();

  if (pinV0 == 1){
    digitalWrite(D1, HIGH);
  }else if (pinV0 == 0){
    digitalWrite(D1, LOW);
  }
  
}
  BLYNK_WRITE(V0){
  pinV0 = param.asInt(); //assigns incoming value button to pinV0 variable
  }

