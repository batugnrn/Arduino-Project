#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include <SPI.h>

int RST_PIN = 9;
int SS_PIN = 10;

MFRC522 rfid(SS_PIN, RST_PIN);

byte ID[4] = {241,207,252,27};

void setup() {
  
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

}

void loop() {
 
  if ( ! rfid.PICC_IsNewCardPresent())    
    return;

  if ( ! rfid.PICC_ReadCardSerial())    
    return;

  if (rfid.uid.uidByte[0] == ID[0] &&     
    rfid.uid.uidByte[1] == ID[1] && 
    rfid.uid.uidByte[2] == ID[2] && 
    rfid.uid.uidByte[3] == ID[3] ) {
        Serial.println("Hoşgeldiniz");
        ekranaYazdir();
        digitalWrite(2, HIGH);
        delay(2000);
        digitalWrite(2, LOW);
    }
    else{                                 
      Serial.println("Yetkisiz Kart");
      ekranaYazdir();
      digitalWrite(3, HIGH);
        delay(2000);
        digitalWrite(3, LOW);
    }
  rfid.PICC_HaltA();
}
void ekranaYazdir(){
  Serial.print("ID Numarasi: ");
  for(int sayac = 0; sayac < 4; sayac++){
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}
















