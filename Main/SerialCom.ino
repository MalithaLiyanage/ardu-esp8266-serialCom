//Arduino code
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include "DHT.h"


#define DHTPIN 2     
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial s(5,6);

int lightVal;
int nutriVal;
int waterVal;
float phVal;
float tempVal;
float humidityVal;



float calibration = 21.34; //change this value to calibrate
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;



void setup() 
{
  s.begin(9600);
  dht.begin();
}
 
void loop() {

  // Get Sensor Values
  // Put them in JSON
  // Send


  nutriVal = getNutriLevelSensorVal();
  waterVal = getWaterLevelSensorVal();
  phVal = getpHSensorVal();
  lightVal = getLightSensorVal();
  humidityVal = getHumidityVal();
  tempVal = getAirTempVal();


  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["ph"] = 5.5;
  root["nutri"] = 600;
  root["water"] = 200;
  root["light"] = 0;
  root["humidity"] = 95.5;
  root["temp"] = 24.3;


  if (s.available()>0)
  {
    root.printTo(s);
  }
  
  
  
  
  
  

  if(s.available()>0)
  {
//   s.write(dht.readTemperature());
//   s.write(dht.readHumidity());
    
    s.write(50);
  }
  
}
