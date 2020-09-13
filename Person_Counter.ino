#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define in 2
#define out 3
#define fan 10
#include<string.h>

#include <Servo.h>

Servo myservo;  // create servo object to control a servo



char a[4]={};
char password[]={"1234"};
int flag=0;
int pos=0;

int flag1=0;
int flag2=0;
int count=0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Visitor Counter");
delay(2000);
attachInterrupt(digitalPinToInterrupt(in),countplus,RISING);
attachInterrupt(digitalPinToInterrupt(out),countminus,RISING);
pinMode(fan,OUTPUT);
lcd.clear();
lcd.print("Person in room");
lcd.setCursor(0,1);
lcd.print(count);
digitalWrite(fan,LOW);  
myservo.attach(9);
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  //attachInterrupt(digitalPinToInterrupt(2),ISR1,CHANGE );
  }

void loop() {
  // put your main code here, to run repeatedly:

}
void enterPassword()
{
 if(Serial.available()>0)
  {
    strcat(a, Serial.read());
    Serial.write(a);
  }
  



checkPassword();                                        
    
  

}
int checkPassword()
{
   if ( strcmp(password,a)==0)
  {
    Serial.println("welcome");
  flag=1;
  return 1;
  }
 else
 {
    Serial.println("Wrong password");
      return 0;
 }
}
void countplus()
 { flag1++;
 
    if(flag2!=0) 
  { //password enter krva do user se
 
 count--;
lcd.clear();
lcd.print("person in room:");
lcd.setCursor(0,1);
lcd.print(count);
delay(1000);
if(count==0)
{lcd.clear();
digitalWrite(fan,LOW);
lcd.clear();
lcd.print("nobody in room");
lcd.setCursor(0,1);
lcd.print("fan is off");
delay(200);
}
else
{ digitalWrite(fan,HIGH);
} flag2=0;flag1=0;
} 

}
void countminus()
{flag2++;

  if(flag1!=0)
 { enterPassword();
     
  if(checkPassword()==1)
   {count++;
   for (pos = 0; pos <= 90; pos += 1) 
  {                                    // goes from 0 degrees to 180 degrees
                                        // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10000);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) 
  {                                   // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10000);                       // waits 15ms for the servo to reach the position
  } 
  lcd.clear();
  lcd.print("person in room");
  lcd.setCursor(0,1);
  lcd.print(count);
  delay(1000);
  if(count>0)
  digitalWrite(fan,HIGH);
 flag1=0;
 flag2=0;
 } }
 
 }
 
