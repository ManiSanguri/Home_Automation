
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH); 
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH); 
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH); 
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{
  if(Serial.available()>0)
  {
 char data=Serial.read();
 switch(data)
 {
 /* case 'a':digitalWrite(9,LOW);
  break;
  default:digitalWrite(9,HIGH); 
  break;// put your main code here, to run repeatedly:*/
case 'a':
  digitalWrite(8,HIGH);

digitalWrite(9,HIGH);

digitalWrite(10,LOW);
delay(500);
break;
 case 'b':                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
digitalWrite(8,HIGH);

digitalWrite(9,LOW);

digitalWrite(10,LOW);
delay(500);
break;
case 'c':
digitalWrite(8,HIGH);

digitalWrite(9, LOW);

digitalWrite(10,HIGH);
delay(500);
break;
case 'd':
digitalWrite(8,LOW);

digitalWrite(9,LOW);

digitalWrite(10,LOW);
delay(500);
break;
 }
  }
  
}






































                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
