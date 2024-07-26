#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9
#define SS_PIN    10
#define ledVerde  2
#define ledRojo   3
#define buzzerPin 4
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

byte tagActual[4]   =  {0x67, 0xE8, 0x15, 0x33};
byte tagConocido[4] = {0x89, 0x1C, 0x93, 0x84};

void setup() {
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Inicializa todos los LEDs
  on(ledRojo);
  off(ledVerde);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) 
    return;

  if (!mfrc522.PICC_ReadCardSerial()) 
    return;
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
}

void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
      tagActual[i] = buffer[i];
  }

  if (compararArray(tagActual, tagConocido)) {
    on(ledVerde);
    off(ledRojo);
    tone(buzzerPin, 200);
    delay(4000);
    noTone(buzzerPin);
    off(ledVerde);
    on(ledRojo); 
  } 
  else {
    off(ledVerde);
    on(ledRojo);
    tone(buzzerPin, 400);
    delay(1000);
    noTone(buzzerPin);
  }
}

boolean compararArray(byte array1[], byte array2[]) {
  for (byte i = 0; i < 4; i++) {
    if (array1[i] != array2[i]) return false;
  }
  return true;
}
