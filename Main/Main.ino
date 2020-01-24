#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

SoftwareSerial s(5,6);


void setup() 
{
  
  s.begin(9600);
  dht.begin();
}

void loop() 
{
 
}
