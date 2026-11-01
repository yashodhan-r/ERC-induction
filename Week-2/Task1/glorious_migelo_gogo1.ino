#include<Wire.h> 
#include<LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);

String input = "";
bool complete = false;
int n1 = 0, n2 = 0;
char op = ' ';
bool toggleBacklight = true;
int currentMillis, lastInterruptTime;


void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), buttonChk, FALLING);
}

void buttonChk(){
  currentMillis = millis();
 if (currentMillis - lastInterruptTime > 200) {
    toggleBacklight = !toggleBacklight;
    lastInterruptTime = currentMillis;
  } 
}

void loop() {
  
 if(toggleBacklight)
   lcd.backlight();
  
  
  
  while (Serial.available()) {
    char inchar = (char)Serial.read();
    if (inchar != '\n' && inchar != '\r') {
      input += inchar;
    }
    delay(5);
  }

  if (input.length()>0) {
    int s = 0;
    n1 = 0;
    n2 = 0;
    op = ' ';

    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);
      if (c == 42 || c == 43 || c == 45 || c == 47) {
        op = c;
        s = 1;
      } else if (c >= 48 && c <= 57) {
        if (s == 0) {
          n1 = n1 * 10 + (c - 48);
        } else if (s == 1) {
          n2 = n2 * 10 + (c - 48);
        }
      }
    }

    lcd.clear();
    lcd.setCursor(0, 0);

    switch (op) {
      case '+':
        lcd.print(n1 + n2);
        break;
      case '-':
        lcd.print(n1 - n2);
        break;
      case '*':
        lcd.print(n1 * n2);
        break;
      case '/':
        if (n2 != 0) {
          lcd.print(n1 / (float)n2);
        } else {
          lcd.print("Div by 0 Error");
        }
        break;
    }
    input = "";
  }
}