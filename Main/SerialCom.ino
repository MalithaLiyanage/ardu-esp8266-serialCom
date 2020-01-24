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
