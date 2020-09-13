%LED control using Browser NodeMCU

#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
const char* ssid = "";
const char* password = "";
int value1=0;
#include<SoftwareSerial.h>
SoftwareSerial NodeSerial(D2,D3); //RX | TX
WiFiServer server(80);
void setup() {
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(115200);
  NodeSerial.begin(4800);
 delay(10);
 // Connect to WiFi network
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print("...");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 // Start the server
 server.begin();
 Serial.println("Server started");
 // Print the IP address
 Serial.print("Use this URL to connect: ");
 Serial.print("http://");
 Serial.print(WiFi.localIP());
 Serial.println("/");
 Serial.print('X');
 }
void loop() {
 // Check if a client has connected
 WiFiClient client = server.available();
 if (!client) {
 return;
 }
  NodeSerial.print("\n");
 NodeSerial.print(value1);
  
 // Wait until the client sends some data
 while(!client.available()) {
 delay(1);
 }
String request = client.readStringUntil('\r');
 client.flush();
 // Match the request
 if (request.indexOf("/BULB=ON") != -1) {
 Serial.println('a');
 value1 = 1;
 NodeSerial.print("\n");
 NodeSerial.print(value1);
  
 }
 if (request.indexOf("/BULB=OFF") != -1) {
 Serial.println('A');
 value1=0;
 NodeSerial.print("\n");
 NodeSerial.print(value1);
  
 }
 NodeSerial.print("\n");
 NodeSerial.print(value1);
  
 if (request.indexOf("/BULB=2MORE") != -1) {
 Serial.println('b');
 value1=2;
 NodeSerial.print("\n");
 NodeSerial.print(value1);
  
 }
 if (request.indexOf("/BULB=2MOST") != -1) {
 Serial.println('B');
 value1=3;
 NodeSerial.print("\n");
 NodeSerial.print(value1);
 }
 // Return the response
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 // client.println("Refresh: 15"); // refresh the page automatically every 5 sec
 client.println();
 client.println(""); // do not forget this one
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<br><br>");
 client.println("<a href=\"/BULB=ON\"\"><button>Turn 1 On </button></a>");
 client.println("<a href=\"/BULB=OFF\"\"><button>Turn 1 Off </button></a><br />");
 client.println("<a href=\"/BULB=2MORE\"\"><button>Turn 2 On</button></a>");
 client.println("<a href=\"/BULB=2MOST\"\"><button>Turn 2 Off </button></a><br />");
 client.println("</html>");
 delay(1);
}
