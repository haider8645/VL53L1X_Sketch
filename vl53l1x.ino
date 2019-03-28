
#include <Wire.h>
#include "SparkFun_VL53L1X.h"

//Optional interrupt and shutdown pins.
#define SHUTDOWN_PIN 2
#define INTERRUPT_PIN 3
/*
This code is used to configure VL53L1X via ESP32 using i2C Interface
*/


//Uncomment the following line to use the optional shutdown and interrupt pins.
SFEVL53L1X distance_sensor(Wire, SHUTDOWN_PIN, INTERRUPT_PIN);

void setup(){
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  Serial.begin(9600);
  Serial.println("VL53L1X Test");

  while (!distance_sensor.checkBootState())
  {}


  if (!distance_sensor.init())
  {
    Serial.println("Sensor is online!");
  }

  //distance_sensor.setDistanceModeLong();
  distance_sensor.setDistanceThreshold(100,1000,3);
  //distance_sensor.setROI(4,4);

/*
  delay(500);
  distance_sensor.setDistanceModeShort();
  delay(500);
  distance_sensor.setDistanceThreshold(100,1000,0);
  delay(500);
  Serial.println("Distance sensor i2C Address: ");
  Serial.println(distance_sensor.getI2CAddress());
  Serial.println(distance_sensor.getDistanceMode());
  Serial.println(distance_sensor.getDistanceThresholdLow());
  Serial.println(distance_sensor.getDistanceThresholdHigh());
  Serial.println(distance_sensor.getDistanceThresholdWindow());
  //distance_sensor.setInterruptPolarityLow();

  //Serial.println("Sensor is online");
*/
}

void loop()
{

  delay(1000);
  /*
  distance_sensor.startRanging(); //Write configuration bytes to initiate measurement
  int distance = distance_sensor.getDistance(); //Get the result of the measurement from the sensor
  distance_sensor.stopRanging();

  Serial.print("Distance(mm): ");
  Serial.print(distance);

  float distanceInches = distance * 0.0393701;
  float distanceFeet = distanceInches / 12.0;

  Serial.print("\tDistance(ft): ");
  Serial.print(distanceFeet, 2);

  Serial.println();
  */
  Serial.println("Interrupt Polarity: ");
  Serial.println(distance_sensor.getInterruptPolarity());


}

