%NodeMCU to Arduino Communication more than one variable

#include "UbidotsMicroESP8266.h"
#define TOKEN  ""  // Put here your Ubidots TOKEN
#define WIFISSID "" // Put here your Wi-Fi SSID
#define PASSWORD "" // Put here your Wi-Fi password
#include<SoftwareSerial.h>
SoftwareSerial nodemcu(D2,D3); //RX | TX

Ubidots client(TOKEN);
  float t=0;
  float h=0;
  float l=0;
  float L=0;
void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    //client.setDebug(true); // Uncomment this line to set DEBUG on
nodemcu.begin(115200);
}
void loop(){
if(nodemcu.available()>0)
{
  String s=nodemcu.readStringUntil('#');
  Serial.println(s);
  t=s.substring(s.lastIndexOf('t')+1,s.lastIndexOf('h')).toFloat();
  h=s.substring(s.lastIndexOf('h')+1,s.lastIndexOf('l')).toFloat();
  
}
if(t>0 && h>0){

Serial.println(t);
Serial.println(h);

client.add("temperature",t);
client.add("humidity",h);

client.sendAll(true);

delay(500);
}

}
