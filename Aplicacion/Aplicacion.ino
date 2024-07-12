#define led1 2
char entrada;
void setup(){
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
  }
void loop(){
  if(Serial.available()>0){
    entrada=Serial.read();
    }
    if(entrada=='E'){
      digitalWrite(led1,HIGH);
      }
      if(entrada=='A'){
        digitalWrite(led1,LOW);
        }
  }
