/*
Fundacion kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito 
Quinto Electronica
Codigo Tecnico: EB5AV
Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
Proyecto: Practica 1 I
Dev: Pether Anderson David Reyes Guzman
Fecha: 21 de Junio
*/
#define A 6
#define B 7
#define C 8
#define D 9
#define E 10
#define F 11
#define G 12
#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define leer(pin) digitalRead(pin)
#define on0 on(A); on(B); on(C); on(D); on(E); on(F)
#define off0 off(A); off(B); off(C); off(D); off(E); off(F)
#define on1 on(B); on(C)
#define off1 off(B); off(C)
#define on2 on(A); on(B); on(D); on(E); on(G)
#define off2 off(A); off(B); off(D); off(E); off(G)
#define on3 on(A); on(B); on(C); on(D); on(G)
#define off3 off(A); off(B); off(C); off(D); off(G)
#define on4 on(B); on(C); on(F); on(G)
#define off4 off(B); off(C); off(F); off(G)
#define on5 on(A); on(C); on(D); on(F); on(G)
#define off5 off(A); off(C); off(D); off(F); off(G)
#define on6 on(C); on(D); on(E); on(F); on(G)
#define off6 off(C); off(D); off(E); off(F); off(G)
#define on7 on(A); on(B); on(C)
#define off7 off(A); off(B); off(C)
#define on8 on(A); on(B); on(C); on(D); on(E); on(F); on(G)
#define off8 off(A); off(B); off(C); off(D); off(E); off(F); off(G)
#define on9 on(A); on(B); on(C); on(F); on(G)
#define off9 off(A); off(B); off(C); off(F); off(G)
#define pausa delay(500)
#define pin_trig 4      
#define pin_echo 5 
#include <Adafruit_NeoPixel.h>

byte s=0, contador_dis=0, z=0, paso=0, tono=0;

enum colores {
  rojo,
  verde,
  off};
Adafruit_NeoPixel anillo(24,2, NEO_GRB + NEO_KHZ800);
float readDistance(void);

void setup()
{
  anillo.begin();
  color_leds(off);
  pausa;
  salidas();
  entrada(5);
  control_display(contador_dis);
  color_leds(verde);
}

void loop()
{ 
  if (distancia_ultras()<11&&distancia_ultras()>5&&paso==0&&contador_dis<11){
    contador_dis++;
    paso=1;
    tono=0;}
  
  if(distancia_ultras()<6||distancia_ultras()>10){
    paso=0;}
  
  if(contador_dis<=8){
    control_display(contador_dis);
      if(tono==0){ 
        tone(3,1250,500);
        delay(500);
        noTone(11);
        tono=1;}}
  
  if(contador_dis>8){
    if(z==0){
        tone(3,1250,500);
        delay(500);
        noTone(11);
        control_display(contador_dis);
        z++;}
    off8;
    color_leds(rojo);
    on(G);}}

int salidas(){
  for(s=6;s<13;s++){ 
    salida(s);}
  for(s=4;s<5&&s>1;s--){ 
    salida(s);}
}

float distancia_ultras(void)
{
  on(pin_trig);     
  delayMicroseconds(10);            
  off(pin_trig);      
  
  long echo_Sensor = pulseIn(pin_echo, HIGH);     
  long distance = echo_Sensor/59;                  
  return distance;   } 

void color_leds(int color)
{
  switch(color)
  {
    case(rojo):
          for(int i =0; i<25; i++){
          anillo.setPixelColor(i,anillo.Color(255,0,0));
          anillo.show(); } 
      break;
    
    case(verde):
        for(int i =0; i<25; i++){
          anillo.setPixelColor(i,anillo.Color(124,252,0));
          anillo.show();}
      break;
    
    case(off):
          for(int i =0; i<25; i++){
          anillo.setPixelColor(i,anillo.Color(0,0,0));
          anillo.show(); } 
      break;
    }
}
  
void control_display(int i){
  if (i==0){
    on0;
    pausa;}
  if (i==1){
    off0;
    on1;
    pausa;}
   if (i==2){
    off1;
    on2;
    pausa;}
  if (i==3){
    off2;
    on3;
    pausa;}
  if (i==4){
    off3;
    on4;
    pausa;}
  if (i==5){
    off4;
    on5;
    pausa;}
  if (i==6){
    off5;
    on6;
    pausa;}
  if (i==7){
    off6;
    on7;
    pausa;}
  if (i==8){
    off7;
    on8;
    pausa;
    }
  if (i==9){
    off8;
    on9;
    pausa;
    }
}
