// C++ code
//

#include <Wire.h>

long timer=0;

void setup()
{
  Wire.begin();
  pinMode(3,INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(3)==LOW&&millis()-timer>200){
   Wire.beginTransmission(0x08);
    Wire.write("midsems :((");
    Wire.endTransmission();
    timer = millis(); 
  }
}