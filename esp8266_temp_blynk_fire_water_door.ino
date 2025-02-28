#include "DHT.h"
#define DHTPIN 14 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);






float t,h;
int val;



#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3tWPJ6QI-"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "BSpnJtjQEe-O3hdrA5QAlt_epaZ9I8GB"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;


char ssid[] = "iotdata";
char pass[] = "12345678";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);
  
  Blynk.begin(auth, ssid, pass);
  dht.begin();
 
}


void loop()
{
  
  int a = digitalRead(5);
  if(a == LOW)
  {
     Blynk.virtualWrite(V1,1);
     digitalWrite(12,HIGH);
     delay(300);
     digitalWrite(12,LOW);
  }
  else
  {
    Blynk.virtualWrite(V1,0);
  }

   int b = digitalRead(4);
  if(b == LOW)
  {
     Blynk.virtualWrite(V2,1);
     digitalWrite(12,HIGH);
     delay(300);
     digitalWrite(12,LOW);
  }
  else
  {
    Blynk.virtualWrite(V2,0);
  }

 int c = digitalRead(13);
  if(c == HIGH)
  {
     Blynk.virtualWrite(V3,1);
    
  }
  else
  {
    Blynk.virtualWrite(V3,0);
  }
   t = dht.readTemperature();
   h = dht.readHumidity();
   Blynk.virtualWrite(V0,t);
    Blynk.virtualWrite(V4,h);

 
  Blynk.run();
  
}
