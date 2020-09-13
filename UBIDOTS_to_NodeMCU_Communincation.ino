%UBIDOTS to NodeMCU Communincation

#include <UbidotsMicroESP8266.h>
#define TOKEN  "BBFF-Nznu4JKJlDgk0dCY9Gl2MvvwwqqawD"  // Put here your Ubidots TOKEN
#define WIFISSID ""
#define PASSWORD ""
#define ID1  "5d8126140ff4c3781cbf88ee"  // switch1
#define ID2  "5ba4dd76c03f972af34993fa" //switch2
Ubidots client(TOKEN);
int value1=0,value2=0,value3=0;
int val4,val5; //switch1,switch2

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}


void loop() {
  // put your main code here, to run repeatedly:
value1=client.getValue(ID1);
value2=client.getValue(ID2);
delay(1000);
  Serial.println(value2);
  Serial.println(value1);
}
