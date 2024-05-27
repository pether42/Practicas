/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final
   Dev: Pether Reyes
   Fecha: 26 de mayo
   
*/
#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define leer(pin) digitalRead(pin)
#define ons(pin) digitalWrite(pin, HIGH)
#define offs(pin) digitalWrite(pin, LOW)
#define ida ons(3); pausa1; offs(3); ons(4);pausa1; offs(4); ons(5); pausa1; offs(5)
#define regreso ons(5); pausa1; offs(5); ons(4); pausa1; offs(4); ons(3);pausa1; offs(3)
#define pausa1 delay(500)
#define onall ons(13); ons(3); ons(4); ons(5) 
#define offall offs(13); offs(3); offs(4); offs(5)
#define a_dis 6
#define b_dis 7
#define e_dis 8
#define f_dis 9
#define g_dis 10
#define onp ons(6); ons(7); ons(8); ons(9); ons(10)
#define offp offs(6); offs(7); offs(8); offs(9); offs(10)

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>             
#include <Wire.h>  
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo;

byte i = 0, b = 0, c = 0;

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte filas [4] = {A0,A1,A2,A3};  
byte columnas [4] = {11,12,13,0};

Keypad teclado = Keypad(makeKeymap(keys), filas, columnas, 4,4);

void setup()
{ servo.attach(2); 
  servo.write(0);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Pether Reyes");
  lcd.setCursor(1,1); 
  lcd.print("Proyecto Final");
  salida(3);
  salida(4);
  salida(5);
  salida(6);
  salida(7);
  salida(8);
  salida(9);
  salida(10);
  Serial.begin(9600);
 
}

void loop()
{ char tecla = teclado.getKey();
 if(tecla){
   switch(tecla){
    case('1'):{
    for(c;c<100;c=c){
  Serial.print("El valor del contador es: ");
  Serial.println(c);
  c+= 1;}
  c = 0;
      break;}
     
  case('2'):{
    for(c=99;c>=0&&c<100;c=c){
  Serial.print("El valor del contador es: ");
  Serial.println(c);
  c-= 1;}
  c = 0;
      break;} 
     
     case('3'):{
       for(byte l=0;l<3;l++){
       ida;
       regreso;
         }
       for(byte o=0;o<5;o++){
       onall;
       pausa1;
       offall;
       pausa1;}
      break;}
     
     case('4'):{
   
  animacion_p (500);
  animacion_p (250);
  animacion_p (100);     
  onp;
  delay(500);
  offp;
  animacion_p (100);
  animacion_p (50);
  animacion_p (50);
  animacion_p (50);      
  onp;
  delay(250);
  offp;
  delay(250); 
  onp;
  delay(250);
  offp;
  delay(250);
  onp;
  delay(1000);
  offp;    
  
       
 
      break;}
     case('5'):{
   
  servo.write(180);
  delay(1250);
  servo.write(0);     
 
      break;}
    }}
 
   
}

void animacion_p (int duracion){
  ons(e_dis);
  delay(duracion);
  offs(e_dis);
  ons(f_dis);
  delay(duracion);
  offs(f_dis);
  ons(a_dis);
  delay(duracion);
  offs(a_dis);
  ons(b_dis);
  delay(duracion);
  offs(b_dis);
  ons(g_dis);
  delay(duracion);
  offs(g_dis);
}

  
