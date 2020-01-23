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
