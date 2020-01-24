//Arduino code
//#include <SoftwareSerial.h>
//#include <ArduinoJson.h>
//#include "DHT.h"
//
//
////#define DHTPIN 2
////#define DHTTYPE DHT11
////
////DHT dht(DHTPIN, DHTTYPE);
//
//SoftwareSerial s(5,6);

void SerialJSONCommunication()
{

  int lightVal;
  int nutriVal;
  int waterVal;
  float phVal;
  float tempVal;
  float humidityVal;


  nutriVal = getNutriLevelSensorVal();
  waterVal = getWaterLevelSensorVal();
  phVal = getpHSensorVal();
  lightVal = getLightSensorVal();
  humidityVal = getHumidityVal();
  tempVal = getAirTempVal();


  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["ph"] = phVal;
  root["nutri"] = nutriVal;
  root["water"] = waterVal;
  root["light"] = lightVal;
  root["humidity"] = humidityVal;
  root["temp"] = tempVal;


  if (s.available() > 0)
  {
    root.printTo(s);
  }


}
