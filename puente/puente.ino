#define horario 5
#define antihorario 6
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define sensorLevantarPin 7  // Pin para el sensor de levantar
byte a=0,b=0;

void setup() {
  pinMode(sensorLevantarPin, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
   }

void loop() {
  if (digitalRead(sensorLevantarPin) == HIGH) {
    bajarPuente();
  }
  
  if (digitalRead(sensorLevantarPin) == LOW) {
    subirPuente();
  }
}

void bajarPuente() {
 
  if(b==1){
  on(6); 
  delay(500);   
  off(6); 
  delay(500);
  b=0; 
  a=0;   
  }
}

void subirPuente() {
  if(a==0){
  on(5); 
  delay(500);   
  off(5); 
  delay(500);  
  b=1;
  a=a+1;}        
}
