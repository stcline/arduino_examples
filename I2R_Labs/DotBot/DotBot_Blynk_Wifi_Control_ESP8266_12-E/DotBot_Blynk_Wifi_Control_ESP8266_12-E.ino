/*  ESP8266 side of Dotbot Program
 *  Controls a 2-wheeled robot in both autonomous and teleoperative mode
 *  Chassis of robot is based on DotBot by Michele Maffucci and Ludovico Russo which can be found at: https://www.thingiverse.com/thing:1441937
 *  Receives commands form Blynk
 *  Sends motor control commands to Arduino via serial for control of a 2-wheeled robot
 * 
 *  Joystick conversion formula is based on explanations at http://home.kendra.com/mauser/joystick.html
 * 
 *  by Steve Cline on 8 August 2018
 */

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

WidgetLCD lcd(V2);

// variables to store virtual pin values from Blynk app
int pinV0 = 0;
int pinV1 = 0;
int pinV3 = 0;

//variables to store speed and direction values for motors
int Rspeed = 0;
int Lspeed = 0;
int fastVal = 0;
int stopVal = 0;
int reverseVal = 0;
int teleop = 0;

int i;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "4af0a668c71249bd99c3601071ced5d8";

// WiFi credentials.
char ssid[] = "Cline Network";
char pass[] = "lucyandrickycline";

void setup(){
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, IPAddress(172,16,0,39), 8080);
}

void loop(){
  Blynk.run();
  speedChk();
  speedCalc();
  checkSpeeds();
  sendLCD();
  controlSend();
}

BLYNK_WRITE(V1){
  pinV1 = param.asInt(); // assigns incoming value from y axis to pinV1 variable
}

BLYNK_WRITE(V0){
  pinV0 = param.asInt(); // assigns incoming value from x axis to pinV0 variable
}

BLYNK_WRITE(V3){
  pinV3 = param.asInt(); // assigns incoming value from speed button to pinV3 variable
}

BLYNK_WRITE(V4){
  teleop = param.asInt(); // assigns incoming value from mode button to pinV4 variable
}

// Calculate logical value for fast/slow speed button on Blynk App.
void speedChk(){
  if (pinV3 == 1){
    fastVal = 1;
  }
  
  else {
    fastVal = 0;
  }
}

// Send values to the UNO via Serial.
void controlSend(){  
  Serial.write("<");
  Serial.write(stopVal);
  Serial.write(reverseVal);
  Serial.write(fastVal);
  Serial.write(Rspeed);
  Serial.write(Lspeed);
  Serial.write(teleop);
  Serial.write(">");  
}

// Convert joystick input to speed for each motor.
void speedCalc(){
  if (pinV1 > 0){
    stopVal = 0;
    reverseVal = 0;
    if (pinV0 > 0){
      Lspeed = pinV1;
      Rspeed = pinV1 - pinV0;
    }
    else if (pinV0 < 0) {
      Lspeed = pinV1 - abs(pinV0);
      Rspeed = pinV1;
    }
  }

  else if (pinV1 < 0){
    stopVal = 0;
    reverseVal = 1;
    if (pinV0 > 0) {
      Lspeed = abs(pinV1);
      Rspeed = abs(pinV1) - pinV0;
    }
    else if (pinV0 < 0){
      Lspeed = abs(pinV1) - abs(pinV0);
      Rspeed = abs(pinV1);
    }
  }

  else {
    stopVal = 1;
    Lspeed = 0;
    Rspeed = 0;
  }
  
}

// If the formula calculates either wheel speed at less than zero convert to zero.
void checkSpeeds(){
  if (Lspeed <=0){
    Lspeed = 0;
  }

  else if (Rspeed <= 0){
    Rspeed = 0;
  }
}

// Print motor control values to the LCD on the Blynk App.
void sendLCD(){
  if (stopVal == 1){
    lcd.clear();
    lcd.print(3, 0, "ROBOT STOPPED");
  }
  
  else if (fastVal == 1){
    lcd.clear();
    lcd.print(0,0, "LEFT   RIGHT");
    lcd.print(1,1, Lspeed);
    lcd.print(8,1, Rspeed);
    lcd.print(12,1, "HIGH");
  }
  
  else {
    lcd.clear();
    lcd.print(0,0, "LEFT   RIGHT");
    lcd.print(1,1, Lspeed);
    lcd.print(8,1, Rspeed);
    lcd.print(12,1, "LOW"); 
  }
}

