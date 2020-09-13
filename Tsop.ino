#include <IRremote.h>

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;
char pass;
String password;
char check()
 {
  if(irrecv.decode(&results))
  {
    irrecv.resume();
    return translateIR();
  }
  else
    return '\0';
 }
 char translateIR()
 {
    switch(results.value)
  {
    case 0x1FE48B7:return 'P';
    case 0x1FE58A7:return 'm';
    case 0x1FE7887:return 'M';
    case 0x1FE807F:return 's';
    case 334439935:return 'p';
    case 33472575:return 'f';
    case 33431775:return 'e';
    case 33464415:return 'd';
    case 0x1FEE01F:return '0';
    case 0x1FE50AF:return '1';
    case 0x1FED827:return '2';
    case 0x1FEF807:return '3';
    case 0x1FE30CF:return '4';
    case 0x1FEB04F:return '5';
    case 0x1FE708F:return '6';
    case 0x1FE00FF:return '7';
    case 0x1FEF00F:return '8';
    case 0x1FE9867:return '9';
        
  }
 }
  void setup()
  {
    Serial.begin(9600);
    Serial.println("Enabling IRin");
    irrecv.enableIRIn(); // Start the receiver
    Serial.println("Enabled IRin");
  }
  void loop()
  {
    pass=check();
  }
