int intensidad = 6600;
char estado;
 
void setup() {
 Serial.begin(9600);
 pinMode(3, OUTPUT);
}

void loop() {
  while(Serial.available()>0){
    estado = Serial.read();}
   
 if(estado=='0'){
    intensidad = 6600;
  }
   if(estado=='1'){
    intensidad = 6300;
  }
   if(estado=='2'){
    intensidad = 6100;
  }
   if(estado=='3'){
    intensidad = 5200;
  }
   if(estado=='4'){
    intensidad = 4900;
  }
   if(estado=='5'){
    intensidad = 4500;
  }
   if(estado=='6'){
    intensidad = 4100;
  }
   if(estado=='7'){
    intensidad = 3500;
  }
   if(estado=='8'){
    intensidad = 3000;
  }
 control_luz(intensidad);
}


void control_luz(int i){
 delayMicroseconds(i);
 digitalWrite(3, HIGH);
 delayMicroseconds(200);
 digitalWrite(3, LOW);
}
