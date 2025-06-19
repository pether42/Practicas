#include <Servo.h>

#include <SPI.h>      // incluye libreria bus SPI
#include <MFRC522.h>      // incluye libreria especifica para MFRC522


#define RST_PIN  6      // constante para referenciar pin de reset
#define SS_PIN  7      // constante para referenciar pin de slave select


#define pin_trig 4      
#define pin_echo 5
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)


MFRC522 mfrc522(SS_PIN, RST_PIN); // crea objeto mfrc522 enviando pines de slave select y reset
Servo servo;


byte LecturaUID[4];         // crea array para almacenar el UID leido
byte Usuario1[4]= {0x89, 0x1C, 0x93, 0x84} ;    // UID de tarjeta leido en programa 1
byte Usuario2[4]= {0x83, 0x0A, 0xE5, 0x24} ;    // UID de llavero leido en programa 1
byte a=0;

void setup() {
  Serial.begin(9600);     // inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init();     // inicializa modulo lector
  servo.attach(3);
  servo.write(0);
  pinMode(5, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())   // si no hay una tarjeta presente
    return;           // retorna al loop esperando por una tarjeta
  
  if ( ! mfrc522.PICC_ReadCardSerial())     // si no puede obtener datos de la tarjeta
    return;           // retorna al loop esperando por otra tarjeta
    
   
    for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
      if (mfrc522.uid.uidByte[i] < 0x10){   // si el byte leido es menor a 0x10
        Serial.print("");       // imprime espacio en blanco y numero cero
        }
        else{           // sino
          Serial.print("");        // imprime un espacio en blanco
          }
          
          LecturaUID[i]=mfrc522.uid.uidByte[i];     // almacena en array el byte del UID leido      
          }
          
            if(distancia_ultras()>2&&distancia_ultras()<10){
                a=0;
            }    
            if(a==1){

            Serial.println("Abriendo talanquera"); // si retorna verdadero muestra texto bienvenida
            servo.write(50);
               }
            if(a==0){
              servo.write(0);
            }
                    
          if(comparaUID(LecturaUID, Usuario1)){  
              a=1;
            }
          else if(comparaUID(LecturaUID, Usuario2)){ // llama a funcion comparaUID con Usuario2
            a=1;
               }         
               else  {
                   Serial.println("No ha pagado");
                       delay(1000);  
                  }   
                  mfrc522.PICC_HaltA();          
}

boolean comparaUID(byte lectura[],byte usuario[]) // funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){    // bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])        // si byte de UID leido es distinto a usuario
    return(false);          // retorna falso
  }
  return(true);           // si los 4 bytes coinciden retorna verdadero
}

float distancia_ultras(void)
{
  on(pin_trig);     
  delayMicroseconds(10);            
  off(pin_trig);      
  
  long echo_Sensor = pulseIn(pin_echo, HIGH);     
  long distance = echo_Sensor/59;               
  return distance;   } 
