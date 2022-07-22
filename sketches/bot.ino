#include <SPI.h>
#include <ESP8266WiFi.h>
char ssid[] = "Redmi Note 8";           // SSID of your home WiFi
char pass[] = "alwaysme";            // password of your home WiFi
unsigned long askTimer = 0;
IPAddress server(192,168,253,251);       // the fix IP address of the server
WiFiClient client;
int in1=D8;
int in2=D7;
int in3=D4;
int in4=D3;
int ENA=D1;
int ENB=D2;

void setup() 
{
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
analogWrite(ENA,255);
analogWrite(ENB,255);
Serial.begin(115200);
WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}


void loop() 
{

    while(!client.connect(server, 80))
    {
      Serial.println("Connecting.....");
    }
    client.println("Hello server! Are you sleeping?\r");  // sends the message to the server
    String datas = client.readStringUntil('\r');
    Serial.println(WiFi.localIP());// receives the answer from the sever
    Serial.println("from server: " + datas);
    client.flush();
          
      if(datas == "r")
      {
        analogWrite(ENA,75);
        analogWrite(ENB,200);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
      }
      else if(datas == "u")
      {
        analogWrite(ENA,200);
        analogWrite(ENB,200);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
      }
      else if(datas == "d")
      {
        analogWrite(ENA,200);
        analogWrite(ENB,200);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
      }
      
      else if(datas == "l")
      {
        analogWrite(ENA,200);
        analogWrite(ENB,75);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
      }

      else if(datas == "s")
      {
        analogWrite(ENA,200);
        analogWrite(ENB,75);
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
      }
      delay(500);
}
