/*ASEN 1403 Introduction to Rocket Engineering
 * This code runs on the arduino uno to gather time and pressure data
 * Author: Matt Rhode
 */

/////////////////////////////////---------- Declarations ----------///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <Adafruit_Sensor.h>                                  //includes Adafruit Sensor library
#include <Adafruit_BMP280.h>                                  //includes Adafruit BME280 pressure sensor library
#include <Wire.h>                                             //Includes Wire library, necessary for I2C communication
#define SEALEVELPRESSURE_HPA (1013.25)                        //Defines Sea Level Pressure for the BME280 sensor

Adafruit_BMP280 bmp;                                          // bme is identifying the sensor and preceeds functions in the bme280 library

/////////////////////////////////---------- Setup Block ----------/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()                                                  //setup block

{
  Serial.begin(9600);                                         //Begin communications with the serial monitor for data acquisition
  unsigned status;                                            //create an unsigned variable (non-negative max 32 bits) called "status"
  status = bmp.begin(0x76);                                   //assigns the variable "status" the address for the BME280 pressure sensor
  pinMode (2, OUTPUT);                                       //Sets digital pin 11 to output mode for lighting LED       
}

/////////////////////////////////---------- Loop Block ----------//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop()                                                  //loop block (repeats)

{ 
    digitalWrite (2, HIGH);                                //Lights up LED to show loop started
    Serial.print(millis());                                //Writes out a time stamp to the serial monitor
    Serial.print(";");                                      //Writes out semi-colon to serial monitor so data can be delimited
    Serial.println(bmp.readAltitude(SEALEVELPRESSURE_HPA)); //Writes out altitude reading to serial monitor, uses read pressure, compares to sea level (defined above), then returns altitude
    
}
