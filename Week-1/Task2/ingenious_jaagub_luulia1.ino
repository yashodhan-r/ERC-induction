// C++ code
//
int delaytime = 1000;
int pot;
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
    delaytime = Serial.parseInt();
  pot = analogRead(A0);
  if(digitalRead(6)==LOW)
    pot=0;
  Serial.println(pot);
  analogWrite(11,map(pot,0,1023,0,255));
  delay(delaytime); // Wait for 1000 millisecond(s)
  analogWrite(11, 0);
  delay(delaytime); // Wait for 1000 millisecond(s)
}