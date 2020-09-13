#include<string.h>
  char ch[20]={};
 char x;  
   char password="1234";
   void setup()    
{
  Serial.begin(9600);

  }

void loop() 
{
 if((Serial.available()>0)&&(Serial.read()!=" "))
  {
    char x=Serial.read();
    Serial.print(x);
    
  }
  
}
void checkPassword()
{
  if(strcmp(ch,password)==0)
Serial.print("correct password");
else
Serial.print("wrong");
}
