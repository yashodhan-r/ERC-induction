#include <Servo.h>
Servo myServo;
const int trig = 6;
const int echo = 7;
bool arr[181];
int angle = 0;
bool direction = true;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  myServo.attach(3);
  myServo.write(0);
}

void loop()
{
  myServo.write(angle);
  delay(30);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration = pulseIn(echo,HIGH,30000);

  float dista = duration*0.034/2;

  if(duration > 0 && dista < 50){
    arr[angle] = true;
    Serial.print("Target spotted at ");
    Serial.print(angle);
   Serial.print(" Degrees at ");
    Serial.print(dista);
    Serial.println("cm");
  }
  else{
    arr[angle] = false;
  }

  bool t = false;
  for(int i = 0;i<=180;i++){
    if(arr[i]==true){
      digitalWrite(LED_BUILTIN,HIGH);
     t = true;
    }
  }
  if(t==false)
    digitalWrite(LED_BUILTIN,LOW);

  if(angle == 180)
    direction = false;
  else if(angle == 0)
    direction = true;

  if(direction == true)
    angle++;
  else
   angle--;
}