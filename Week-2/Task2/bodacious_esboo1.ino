
long timer1=0;
long timer2=0;
long timer3=0;

bool trip = flase;
void setup(){
  pinMode(A0, INPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(3,HIGH);
}

void loop(){
  if(trip){
    if(millis()-timer1>=2000&&millis()-timer1<=4000){
     digitalWrite(5,HIGH);
    }
    if(millis()-timer1>4000){
     digitalWrite(5,LOW);
      timer1=millis();
    }
    if(millis()-timer2>=1000&&millis()-timer2<=2000){
     digitalWrite(2,HIGH);
    }
    if(millis()-timer2>2000){
     digitalWrite(2,LOW);
      timer2=millis();
    }
  }
  if(analogRead(A0)>512 && !trip){
   	 trip = true;
     digitalWrite(3,LOW);
  }
  if(digitalRead(8)==LOW&&millis()-timer3>200){
   	 trip = false;
    timer3=millis();
    digitalWrite(5,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
  }
}