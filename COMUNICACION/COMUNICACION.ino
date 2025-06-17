#include <SPI.h>
#include <Ethernet.h>
#include <MFRC522.h>      // incluye libreria especifica para MFRC522

/*
  Arduino UNO + Ethernet Shield:
    SS   -> D10
    MOSI -> D11
    MISO -> D12
    SCK  -> D13

  Trigger Input:
    D3 -> INPUT, envía dato cuando HIGH
*/

#define RST_PIN  6      // constante para referenciar pin de reset
#define SS_PIN  7      // constante para referenciar pin de slave select

MFRC522 mfrc522(SS_PIN, RST_PIN); // crea objeto mfrc522 enviando pines de slave select y reset
byte LecturaUID[4];         // crea array para almacenar el UID leido

byte Usuario1[4]= {0x89, 0x1C, 0x93, 0x84} ;

byte mac[] = { 0xDE,0xAD,0xBE,0xEF,0xFE,0xED };
EthernetClient client;

// Proxy CORS-Anywhere (HTTP) que reenviará tu POST a HTTPS
const char* PROXY_HOST = "cors-anywhere.herokuapp.com";
const uint16_t PROXY_PORT = 80;
// Ruta con URL absoluta de tu endpoint HTTPS
const char* PROXY_PATH = "/https://talanquera-api.vercel.app/talanquera/v1/carnets/create";

// Tu payload fijo
const char* jsonPayload = "{\"number\":\"2019427\"}";

void setup() {
  Serial.begin(9600);
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init(); 

  if (Ethernet.begin(mac) == 0) {
    Serial.println("DHCP falló, configura IP fija si lo necesitas");
  }
  delay(1000);
  Serial.print("Ethernet iniciado. IP local: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // Sólo actuamos con trigger HIGH
   if(!comparaUID(LecturaUID, Usuario1)) return; //6SDSDSD
   
  if(comparaUID(LecturaUID, Usuario1))
  Serial.println();
  Serial.println("Trigger HIGH: enviando carnet 123456…");

  int len = strlen(jsonPayload);

  Serial.print("Conectando a proxy ");
  Serial.print(PROXY_HOST);
  Serial.print(':');
  Serial.println(PROXY_PORT);

  if (!client.connect(PROXY_HOST, PROXY_PORT)) {
    Serial.println("Error: no pudo conectar al proxy");
    delay(3000);
    return;
  }
  Serial.println("Conectado.");

  // Construir la petición HTTP/1.0
  client.print("POST ");
  client.print(PROXY_PATH);
  client.println(" HTTP/1.0");

  client.print("Host: ");
  client.println(PROXY_HOST);
  client.println("Content-Type: application/json");
  client.print("Content-Length: ");
  client.println(len);
  // Header requerido por cors-anywhere demo
  client.println("Origin: http://example.com");
  // client.println("X-Requested-With: Arduino"); // alternativo
  client.println();              // fin de headers
  client.println(jsonPayload);   // body JSON

  // Esperar respuesta (5 s)
  unsigned long t0 = millis();
  while (!client.available() && millis() - t0 < 5000);

  if (!client.available()) {
    Serial.println("Error: sin respuesta tras 5 s");
    client.stop();
    delay(3000);
    return;
  }

  // Mostrar línea de estado
  String status = client.readStringUntil('\n');
  Serial.print("Status: ");
  Serial.println(status);

  // Omitir headers
  while (client.available()) {
    String line = client.readStringUntil('\n');
    if (line == "\r" || line.length() == 0) break;
  }

  // Mostrar body
  String body = client.readString();
  Serial.print("Body: ");
  Serial.println(body);

  client.stop();
  delay(5000);  // debounce
}

boolean comparaUID(byte lectura[],byte usuario[]) // funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){    // bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])        // si byte de UID leido es distinto a usuario
    return(false);          // retorna falso
  }
  return(true);           // si los 4 bytes coinciden retorna verdadero
}
