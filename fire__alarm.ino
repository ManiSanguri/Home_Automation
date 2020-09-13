#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#define WIFISSID "Oppo"
#define PASSWORD "mani_disha"
int status = WL_IDLE_STATUS; //not required.
float temp=30;
const char* ssid = "";  //enter the name of wifi connection
const char* password = "mani_disha"; //enter the password of wifi connection
int firealarm = 1;
void setupWifi();
void setup() {
  
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(115200);

 
  setupWifi();
 
  
}

void setupWifi()
{
     
   WiFi.mode(WIFI_STA);
   status = WiFi.begin(ssid, password);    

   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);  

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
  
    if (temp>=30&&firealarm==0)
    {
      Serial.println("FIRE ALARM");
      while (get_http(String("FIRE ALARM")) != 0);      
      firealarm = 1;
    } 
    
    delay(10);


}


int get_http(String state)
{
   HTTPClient http;
   int ret = 0;
   Serial.print("[HTTP] begin...\n");
   // configure ifttt server and url  should be HTTP only..not https! 
   // http.begin("http://maker.ifttt.com/trigger/fire_trigger/with/key")
   http.begin("http://maker.ifttt.com/trigger/fire_trigger/with/key/b5oBX6hVtG-cZfILJCBJ9AGBd3QQMs3frpnHE0Awaf6"); //HTTP
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
