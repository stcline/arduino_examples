#include <SoftwareSerial.h>

#define ARDUINO_RX 5 // TX - Arduino RX
#define ARDUINO_TX 6 // RX - Arduino TX

SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);

static int8_t Send_buf[8] = {0};

void setup(){
  Serial.begin (9600);
  mySerial.begin(9600);
  delay(500);
  sendCommand(0x06, 0x1E);

  uint8_t i = 0;
  do {
    sendCommand(0x03, i);
    i++;
    Serial.print ("Fart noise ");
    Serial.println (i);
    delay (2000);
  } while (i < 0x06);  
}

void loop(){
  
}

void sendCommand(int8_t command, int16_t dat){
  delay(20);
  Send_buf[0] = 0x7e; 
  Send_buf[1] = 0xff; 
  Send_buf[2] = 0x06; 
  Send_buf[3] = command;
  Send_buf[4] = 0x00;
  Send_buf[5] = (int8_t)(dat >> 8);
  Send_buf[6] = (int8_t)(dat); 
  Send_buf[7] = 0xef; 
  for(uint8_t i=0; i<8; i++) {
    mySerial.write(Send_buf[i]);  
  }
}
