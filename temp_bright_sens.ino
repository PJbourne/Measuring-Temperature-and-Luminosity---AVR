#include <TM1638.h>
#include <LiquidCrystal.h>
#include <InvertedTM1638.h>
#define num 10
#define sens A0
#define LDR A1
#define l 2
#define l2 9

LiquidCrystal lcd(4, 3, 5, 6, 7, 8);

float vf, vf1, C, s1, s2, s3, s4, val[num], val1[num];
void temp();
void mov_avg();

void setup(){
  pinMode(l, OUTPUT);
  pinMode(l2, OUTPUT);
  analogWrite(l2, 254);
  digitalWrite(l, LOW);
  lcd.begin(16, 2, LCD_5x8DOTS);
  lcd.setCursor(0,0);
  lcd.print("Calculator");
  lcd.setCursor(0,1);
  lcd.print("E Sensor");
  lcd.setCursor(0,0);
  delay(62);
  }
void loop(){
  s1 = analogRead(sens);
  s3 = analogRead(LDR);
  vf = (s1/1024)*500 ;
  vf1 = s3;
  mov_avg();
  temp();
  if(s4 < 275){
    digitalWrite(l, HIGH);
    }else if(s4 > 275){
      digitalWrite(l, LOW);
      }
   if(s4<600){analogWrite(l2, 255);}
   if(s4<500){analogWrite(l2, 230);}
   if(s4<400){analogWrite(l2, 205);}
   if(s4<300){analogWrite(l2, 180);}
   if(s4<200){analogWrite(l2, 155);}
   if(s4<100){analogWrite(l2, 130);}
}
  
void mov_avg(){
  long acc = 0;
  long acc1 = 0;
for(int i=num-1; i>0; i--){
  val[i] = val[i-1];
  val1[i] = val1[i-1];
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print(i);
//  lcd.setCursor(3,0);
//  lcd.print(val[i]);
//  delay(32);
  }
    val[0] = vf;
    val1[0] = vf1;
for(int i=0; i<num; i++){
  acc += val[i];
  acc1 += val1[i];
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print(acc);
//  delay(32);
  }
  s2 = acc / num;
  s4 = acc1 / num;
}

void temp(){
  C = s2 - 273;
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura ");
  lcd.print(C,0);
  lcd.print(char(223));
  lcd.print('C');
  lcd.setCursor(0,1);
  lcd.print("Luminosidade ");
  lcd.print(s4,0);

//  delay(100);
}
