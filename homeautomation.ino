#include <SPI.h>
#include <MFRC522.h>



float x = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   
void setup() 
{
  Serial.begin(9600);   
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    digitalWrite(2, HIGH);
  SPI.begin();     
  mfrc522.PCD_Init();  
  Serial.println("Approximate your card to the reader...");
   Serial.println();
}

void loop() 
{
  int a = digitalRead(A2);
  if(a == HIGH)
  {
    biscuits();
  }
  int b = digitalRead(A0);
  if(b == HIGH)
  {
    digitalWrite(3,LOW);
  }
  else
  {
    digitalWrite(3,HIGH);
  }
   int c = digitalRead(A1);
   if(c == HIGH)
  {
    digitalWrite(4,LOW);
  }
  else
  {
    digitalWrite(4,HIGH);
  }

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
 
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {    
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  //Serial.println();
  //Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "F3 0C 0E FB") 
  {     
    biscuits();
    }
   
 
 
  
  else
  {
   //Serial.println("unknown"); 
  
  } 
}


void biscuits(){
  
   digitalWrite(2, LOW);
   digitalWrite(5, HIGH);
   delay(5000);
   digitalWrite(5, LOW);
     digitalWrite(2, HIGH);
    
}
