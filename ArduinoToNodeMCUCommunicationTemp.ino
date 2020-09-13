%Ardunio to NodeMCU Communication of Temperature DHT-11
#include <dht.h>
dht DHT;
#define DHT11_PIN 7
#include<SoftwareSerial.h>
SoftwareSerial ArduinoSerial(4,2); //RX TX
int value2=2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ArduinoSerial.begin(4800);

}
void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);
  
  Serial.println(DHT.temperature);
 
 // Serial.println(DHT.humidity);
  
  delay(100);
  
   ArduinoSerial.print("\n");
  
  ArduinoSerial.print(DHT.temperature);
  
//  Serial.println("DHT values");
 
 //Serial.println(value1);


delay(100);
}
