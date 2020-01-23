int getNutriLevelSensorVal()
{
  int value = digitalRead(13);  // Dummy pin number

  if (value)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int getWaterLevelSensorVal()
{
  int value = digitalRead(12);

  if (value)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

float getpHSensorVal()
{
  unsigned long int avgValue;
  float b;
  int buf[10], temp;
  int sensorValue = 0;
  float calibration = 21.34;

  
  for (int i = 0; i < 10; i++)
  {
    buf[i] = analogRead(4); // Dummy pin
    delay(30);
  }

  for (int i = 0; i < 9; i++)
  {
    for (int j = i+1; j < 10; j++)
    {
      if (buf[i] > buf[j])
      {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }

  avgValue = 0;

  for (int i = 2; i < 8; i++)
  {
    avgValue += buf[i];
  }
  
  float pHVol = (float)avgValue*5.0/1024/6;
  float phValue = -5.70 * pHVol + calibration + 11;

//Serial.print("sensor = ");
//Serial.println(phValue);

return phValue;

delay(500);
  
}
