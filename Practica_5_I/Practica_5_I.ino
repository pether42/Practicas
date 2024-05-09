/*
Fundacion kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito 
Quinto Electronica
Codigo Tecnico: EB5AV
Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
Proyecto: Conversiones y Display 
Dev: Pether Anderson David Reyes Guzman
Fecha: 07 de mayo
*/
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define leer(pin) digitalRead(pin)
#define on1 on(b); on(c)
#define off1 off(b); off(c)
#define on2 on(a); on(b); on(d); on(e); on(g)
#define off2 off(a); off(b); off(d); off(e); off(g)
#define on3 on(a); on(b); on(c); on(d); on(g)
#define off3 off(a); off(b); off(c); off(d); off(g)
#define on5 on(a); on(c); on(d); on(f); on(g)
#define off5 off(a); off(c); off(d); off(f); off(g)
#define on7 on(a); on(b); on(c)
#define off7 off(a); off(b); off(c)
#define on9 on(a); on(b); on(c); on(f); on(g)
#define off9 off(a); off(b); off(c); off(f); off(g)
#define pausa delay(500)
byte i=0,s=0,kg=0,am=0;


void setup()
{
salidas();
Serial.begin (9600);
}

void loop()
{  

  control_display();
  kg_lb(1);
  a_ua(3);
}

void control_display(){
 
for(int i =1; i < 10 ;i= i+2){
  if (i==1){
    off9;
    on1;
    pausa;}
  if (i==3){
    off1;
    on3;
    pausa;}
  if (i==5){
    off3;
    on5;
    pausa;}
  if (i==7){
    off5;
    on7;
    pausa;}
  if (i==9){
    off7;
    on9;
    pausa;
    }
    
}}
int salidas(){
  for(s=2;s<9;s++){ 
    salida(s);}
  s=10;
}

void kg_lb (int x){ 
  if (kg== 0){ 
  float resultado;
  resultado = x*2.2;
  Serial.print(x);
  Serial.print("kg ");
  Serial.print("Equivalen a: ");
  Serial.print(resultado);
  Serial.println("lbs");
  kg+= 1;
  delay(500);}} 

void a_ua (int x){ 
  if (am== 0){ 
  long resultado;
  resultado = x*1000000;
  Serial.print(x);
  Serial.print("A ");
  Serial.print("Equivalen a: ");
  Serial.print(resultado);
  Serial.println("µA");
  am+= 1;
  delay(500);}} 
  
