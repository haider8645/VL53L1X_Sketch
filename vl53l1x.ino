
#include <Wire.h>
#include "SparkFun_VL53L1X.h"

//Optional interrupt and shutdown pins.
#define SHUTDOWN_PIN 2
#define INTERRUPT_PIN 3

SFEVL53L1X distance_sensor_arrive;
SFEVL53L1X distance_sensor_leave;

#define  XSHUT_PIN_SENSOR_LEAVE 4
#define  XSHUT_PIN_SENSOR_ARRIVE 5


void setup()
{
  pinMode(XSHUT_PIN_SENSOR_ARRIVE,OUTPUT);
  pinMode(XSHUT_PIN_SENSOR_LEAVE, OUTPUT);
  digitalWrite(XSHUT_PIN_SENSOR_ARRIVE, LOW);
  digitalWrite(XSHUT_PIN_SENSOR_LEAVE, LOW);
  Wire.begin();
  //Wire.setClock(400000); // use 400 kHz I2C
  Serial.begin(9600);
  Serial.println("VL53L1X Test");

  digitalWrite(XSHUT_PIN_SENSOR_ARRIVE,HIGH);
  delay(150);
  distance_sensor_arrive.init();
  delay(100);
  distance_sensor_arrive.setI2CAddress(0x35);
  Serial.println("04");

  digitalWrite(XSHUT_PIN_SENSOR_LEAVE,HIGH);
  delay(150);
  distance_sensor_leave.init();
  delay(100);
  distance_sensor_leave.setI2CAddress(0x30);
  Serial.println("04");

  byte count = 0;

  for (byte i = 1; i < 120; i++)
   {

      Wire.beginTransmission (i);
      if (Wire.endTransmission () == 0)
      {
        Serial.print ("Found address: ");
        Serial.print (i, DEC);
        Serial.print (" (0x");
        Serial.print (i, HEX);
        Serial.println (")");
        count++;
        delay (1);
      }
    }
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");

}

void loop()
{
  delay(60);
  
  distance_sensor_arrive.startRanging(); //Write configuration bytes to initiate measurement
  distance_sensor_leave.startRanging();
  int distance_arrive = distance_sensor_arrive.getDistance(); //Get the result of the measurement from the sensor
  int distance_leave = distance_sensor_leave.getDistance(); //Get the result of the measurement from the sensor
  distance_sensor_arrive.stopRanging();
  distance_sensor_leave.stopRanging();

  Serial.print("Distance Arrive(mm): ");
  Serial.println(distance_arrive);
  Serial.print("Distance Leave(mm): ");
  Serial.println(distance_leave);
}

