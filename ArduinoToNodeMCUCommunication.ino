%Arduino To NodeMCU Communication

#include<SoftwareSerial.h>
SoftwareSerial ArduinoSerial(4,2); //RX TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ArduinoSerial.begin(4800);
  pinMode(9,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 while(ArduinoSerial.available()>0)
{ 
  float val=ArduinoSerial.parseFloat();
  
  Serial.println(val);
  if(ArduinoSerial.read() == '\n')
  { if(val!=0)
 { digitalWrite(7,HIGH);
 }
  else digitalWrite(7,LOW);
      
  }
}
 

delay(1000);
}
