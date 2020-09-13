#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 // #define fire_alarm 5 //D1
float temp=40;
int status = WL_IDLE_STATUS; //not required.
void setupwifi();
//#include<SoftwareSerial.h>
const char* ssid = "Oppo";
const char* password = "mani_disha";
int fireAlarm = 1;
//SoftwareSerial NodeSerial(D2,D3); //RX | TX
void setup() {
  
  //pinMode(D2,INPUT);
  //pinMode(D3,OUTPUT);
 
   
  //NodeSerial.begin(4800);

  Serial.begin(115200);

  setupWifi();
   
   //get_http();

}

void setupWifi()
{
 
     // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
   WiFi.mode(WIFI_STA);
   status = WiFi.begin(ssid, password);    

   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);  

   // Wait for connection
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
   }
   Serial.println("Connected to wifi");
}

void loop() {
   
   if (WiFi.status() != WL_CONNECTED)
   {
     setupWifi();
   }
  // put your main code here, to run repeatedly:
    if ((temp>=30) && (fireAlarm == 1))
    {
      Serial.println("Fire Fire Fire!!");
      while (get_http(String("Fire_Triggered_Alarm")) != 0);      
      fireAlarm = 0;
    } 
   
    delay(10);


}


int get_http(String state)
{
   HTTPClient http;
   int ret = 0;
   Serial.print("[HTTP] begin...\n");
   // configure ifttt server and url  should be HTTP only..not https!!!  (http://)   
    http.begin("https://maker.ifttt.com/trigger/Fire_Alarm_Triggered/with/key//b5oBX6hVtG-cZfILJCBJ9AGBd3QQMs3frpnHE0Awaf6"); //HTTP
   //If you have enabled value1 from iftt settings then uncomment below line to send value and comment out above line  
   //http.begin("http://maker.ifttt.com/trigger/door/with/key/your_key_from_Iftt/?value1="+state); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();
    // httpCode will be negative on error
    if(httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET code: %d\n", httpCode);

      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
        ret = -1;
        Serial.printf("[HTTP] GET failed, error: %s\n", http.errorToString(httpCode).c_str());
        delay(500); // wait for half sec before retry again
    }

    http.end();
    return ret;
}  
