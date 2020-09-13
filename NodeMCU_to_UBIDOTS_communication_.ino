%NodeMCU to UBIDOTS communication

#include <UbidotsMicroESP8266.h>
#define TOKEN  ""  // Put here your Ubidots TOKEN
#define WIFISSID ""
#define PASSWORD ""
#include<ESP8266WiFi.h>
#define ID_1 ""
#include<SoftwareSerial.h>
//Code By ArduinoALL

Ubidots client(TOKEN);

SoftwareSerial NodeSerial(D2,D3); //RX | TX
void setup() {
  // put your setup code here, to run once:
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
  NodeSerial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
while(NodeSerial.available()>0)
{ 
  float val=NodeSerial.parseFloat();
  if(NodeSerial.read() == '\n')
  { Serial.println("Sensor value 1");
    Serial.println(val);
    client.add(ID_1, val);
 
}

delay(100);

client.sendAll(true);
}}
