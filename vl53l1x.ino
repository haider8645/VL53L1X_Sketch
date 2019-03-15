#include "Wire.h"
#include "SparkFun_VL53L1X.h"

/*
This code is used to configure VL53L1X via ESP32 using i2C Interface
*/


//Uncomment the following line to use the optional shutdown and interrupt pins.
SFEVL53L1X distance_sensor;

void setup(){

Wire.begin();

  Serial.println("VL53L1X Test");

  if (distance_sensor.begin() == true)
  {
    Serial.println("Sensor online!");
  }

}

void loop(){}

