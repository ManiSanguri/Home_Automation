#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define in 2
#define out 3
#define fan 10

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
void checkPassword();
int c=0;
int x,z;
int num;
int password=1234;
int pos=0;
int flag1=0;
int flag2=0;
 static int count=0;
void countplus();
void countMinus();
void setup()
{
lcd.begin(16,2);
lcd.print("Visitor Counter");
delay(500);
attachInterrupt(digitalPinToInterrupt(in),countplus,RISING);
attachInterrupt(digitalPinToInterrupt(out),countMinus,RISING);
pinMode(fan,OUTPUT);
lcd.clear();
lcd.print("Person in room");
lcd.setCursor(0,1);
lcd.print(count);
lcd.clear();
digitalWrite(fan,LOW);  
myservo.attach(9);
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
   pinMode(8,OUTPUT);
}

void loop()
{
}
void countplus()
{
  lcd.clear();
  lcd.print("enter password");
  z=0;
while(z<5)
{
 if(Serial.available())
  {
    x=Serial.read();
    z++;
    lcd.setCursor(z,1);
  lcd.write("*");
    lcd.write(x-48);
      num=num*10+(x-48);
  }
 if(z==4)
 {
    checkPassword();
    break;
 }
 }  

   if(c>0)
  {
  flag1++;
  if(flag2==0)
 {
   for (pos = 180; pos >= 0; pos -= 5)
  {                                   // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  }
  else if(flag2!=0)
  {
    for (pos = 0; pos<=180; pos += 5)
{                                   // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
}
  count--;
  }
  }
  lcd.clear();
  lcd.print("person in room:");
  lcd.setCursor(0,1);
  lcd.print(count);
  flag2=0;
  flag1=0;


if(count==0)
{
lcd.clear();
digitalWrite(fan,LOW);
lcd.clear();
lcd.print("nobody in room");
lcd.setCursor(0,1);
lcd.print("fan is off");
delay(200);
lcd.clear();
}
else
{
  digitalWrite(fan,HIGH);
}
 }


void countMinus()
{flag2++;
if  (flag1 !=0)
   {
    for (pos = 0; pos <= 180; pos += 5)
  {                                   // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  count++;
      lcd.clear();
  lcd.print("person in room");
  lcd.setCursor(0,1);
  lcd.print(count);
  flag1=0;
  flag2=0;
   }
   else
   {
    for (pos = 180; pos >=0; pos-=5)
  {                                   // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
   }

 
 if(count>0)
 {
   digitalWrite(fan,HIGH);  
 }
 if(count==0)
{
  lcd.clear();
digitalWrite(fan,LOW);
lcd.clear();
lcd.print("nobody in room");
lcd.setCursor(0,1);
lcd.print("fan is off");
delay(200);
}
}

void checkPassword(int num,int password)
{
  lcd.clear();
  if(num==password)
  {
lcd.print("Welcome");
delay(500);
lcd.clear();
c++;
  }
else
{
lcd.clear();
lcd.print("Oops Try Again");
delay(500);
lcd.clear();
}
}
 void enterPassword(int z)
 {int x;
  while(1)
{
 if(Serial.available()>0)
  {
    x=Serial.read();
    z++;
    lcd.setCursor(0,1);
  lcd.write("*");
    lcd.write(x-48);
      num=num*10+(x-48);
  }
    if(z==4)
    {
    checkPassword(num,password);
    break;
    }  
 }
 lcd.print("oops");
 } 


 
