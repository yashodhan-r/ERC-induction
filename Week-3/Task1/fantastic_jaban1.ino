// C++ code
//
char x = 's';

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(analogRead(A0)>700&&analogRead(A1)>700){
	x='f';
  }
  if(analogRead(A0)>700&&analogRead(A1)<700)
    x='l';
  if(analogRead(A0)<700&&analogRead(A1)>700)
    x='r';
  if(analogRead(A0)<700&&analogRead(A1)<700)
    x='s';
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.print(analogRead(A1));
  Serial.print(",");
  Serial.print(x);
  Serial.println();
  
  
  if(x=='l'){//Left
  	digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }
  if(x=='f'){//FWD
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW); 
  }
  if(x=='r'){//right
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH); 
  }
  if(x=='s'){//Rev
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW); 
  }
}