/*
Fundacion kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito 
Quinto Electronica
Codigo Tecnico: EB5AV
Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
Proyecto: Cuenta regresiva
Dev: Pether Anderson David Reyes Guzman
Fecha: 09 de mayo
*/
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define on0 on(a); on(b); on(c); on(d); on(e); on(f)
#define off0 off(a); off(b); off(c); off(d); off(e); off(f)
#define on1 on(b); on(c)
#define off1 off(b); off(c)
#define on2 on(a); on(b); on(d); on(e); on(g)
#define off2 off(a); off(b); off(d); off(e); off(g)
#define on3 on(a); on(b); on(c); on(d); on(g)
#define off3 off(a); off(b); off(c); off(d); off(g)
#define on4 on(b); on(c); on(f); on(g)
#define off4 off(b); off(c); off(f); off(g)
#define on5 on(a); on(c); on(d); on(f); on(g)
#define off5 off(a); off(c); off(d); off(f); off(g)
#define on6 on(c); on(d); on(e); on(f); on(g)
#define off6 off(c); off(d); off(e); off(f); off(g)
#define on7 on(a); on(b); on(c)
#define off7 off(a); off(b); off(c)
#define on8 on(a); on(b); on(c); on(d); on(e); on(f); on(g)
#define off8 off(a); off(b); off(c); off(d); off(e); off(f); off(g)
#define on9 on(a); on(b); on(c); on(f); on(g)
#define off9 off(a); off(b); off(c); off(f); off(g)
#define ofall_dis off(a); off(b); off(c); off(d); off(e); off(f); off(g) 
#define pausa delay(1000)
byte s=0,i=9,buzzer=0;
void setup()
{
  ofall_dis;
  on(10);
  salidas();
}

void loop()
{
  control();
  
}

int salidas(){
  for(s=2;s<11;s++){ 
    pinMode(s,OUTPUT);
 }
  s=11;
}

void control(){
  if(i>0){
for(int i =9; i > 0;i= i-1){
  if (i==1){
    off2;
    on1;
    pausa;}
  if (i==2){
    off3;
    on2;
    pausa;}
  if (i==3){
    off4;
    on3;
    pausa;}
  if (i==4){
    off5;
    on4;
    pausa;}
  if (i==5){
    off6;
    on5;
    pausa;}
  if (i==6){
    off7;
    on6;
    pausa;}
  if (i==7){
    off8;
    on7;
    pausa;}
  if (i==8){
    off8;
    on8;
    pausa;}
  if (i==9){
    on9;
    pausa;
  }}}
  i=0; 
if (i==0){
    off1;
    on0;
    if(buzzer==0){
    tone(9,88,500);
    off(10);
    delay(500);
    noTone(9);
    buzzer++;}
    }
    }
