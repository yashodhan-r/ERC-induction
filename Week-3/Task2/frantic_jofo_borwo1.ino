// C++ code
//
#include <Servo.h>
Servo myServo;

int angle = 0;

void setup()
{
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  myServo.attach(3);
  myServo.write(angle);
}

void loop()
{
  if(digitalRead(9)==LOW){
    update(15);
    delay(200);
  }
  if(digitalRead(10)==LOW){
    update(30);
    delay(200);
  }
  if(digitalRead(11)==LOW){
    update(60);
    delay(200);
  }
  if(digitalRead(12)==LOW){
    update(90);
    delay(200);
  }
  if(digitalRead(13)==LOW){
    update(180);
    delay(200);
  }
  if(digitalRead(8)==LOW){
    update(-angle);
    delay(200);
  }
}
void update(int add_angle){
	angle += add_angle;
  if (angle>=180){
  	 angle = 180;
  }
  myServo.write(angle);
}